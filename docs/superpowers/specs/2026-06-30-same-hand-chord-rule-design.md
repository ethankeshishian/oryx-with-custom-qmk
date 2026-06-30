# Same-Hand-Only Modifier Chord Rule — Design

**Date:** 2026-06-30
**Keyboard:** ZSA Voyager, layout `PWK6Z`, Colemak-DH, home-row mods
**File touched:** `PWK6Z/keymap.c` (custom QMK on the `main` branch)
**Firmware:** `zsa/qmk_firmware` @ `firmware25`

## The rule (user's words, normalized)

Excluding thumb keys:

1. **Same-hand mods stack into a chord.** Holding a home-row mod and adding
   another home-row mod **on the same hand** builds a combined modifier
   (e.g. hold T-left + S-left → Shift+GUI).
2. **Same-hand letters are not modified.** A letter on the same hand as the held
   mod just taps; the mod does not apply to it.
3. **The chord applies only to the opposite hand.** A held mod (or same-hand mod
   stack) modifies keys on the **other** hand — those keys are *targets*, not
   chord members. Hold T-left → press N-right → **capital N**.
4. **The opposite hand can never join the chord.** Holding T-left and then
   holding N-right must NOT produce Shift+Cmd. N must be *modified* (capital N),
   not registered as its own modifier.
5. **Thumbs are exempt** from all of the above.

The decisive clarification: *Chordal Hold lets an opposite-hand key become an
additional modifier (the `sn` → Shift+Cmd case). The user wants the opposite of
that — opposite-hand keys may be **modified by** the chord but may never **be
part of** it. The chord membership set is same-hand-only.*

## What already works (no code needed)

Source review of `firmware25 quantum/action_tapping.c` and `quantum/action.c`
established that **rule 3 is automatic** for a fully-settled first mod:

- There is exactly one `tapping_key` at a time (`action_tapping.c:113`). When the
  first mod (T) settles as a hold it calls `register_mods` (`action.c:532`) and
  leaves the machine; `tapping_key` is reset to `{0}`.
- A subsequently pressed opposite-hand key starts a *fresh* sequence. If it
  resolves as a **tap**, it emits its tap keycode and automatically picks up the
  already-registered Shift from global mod state → a shifted character. No
  mod-clearing happens on the tap path. **So opposite-hand modification is an
  emergent property of global mod state, not a feature we implement.**

Rules 1, 2 and 5 are likewise handled by stock Chordal Hold + the existing
`chordal_hold_layout` (`keymap.c:117-123`): same-hand interrupter → force tap
(rule 2), opposite-hand or `*` → eligible to hold, thumbs marked `*` exempt.

## The one gap (rule 4 — what needs code)

The `sn` → Shift+Cmd failure occurs only when the opposite-hand key **also settles
as a hold** (both keys held past their terms, or permissive-hold settles both).
Then both register mods → a cross-hand chord. Nothing in stock config forbids an
opposite-hand mod-tap from holding while a same-hand mod is already engaged.

**Fix:** a custom `get_chordal_hold` override that force-taps an opposite-hand
mod-tap whenever a real modifier is already held on the other hand.

Source facts that make this exact and safe (from `firmware25`):

- `get_chordal_hold(uint16_t tap_hold_keycode, keyrecord_t *tap_hold_record,
  uint16_t other_keycode, keyrecord_t *other_record)` is called for the second
  key's *own* resolution, with that key as `tap_hold_*` (`:316`, `:424`).
- Returning **`false`** force-settles it as a tap (`:322 tap.count = 1`), which
  emits the tap keycode and **does not** register its hold modifier (`:528` tap
  branch, not the `:532` hold branch). → exactly "modify, don't join chord."
- The already-held first mod is **not** an argument to `get_chordal_hold`, but its
  modifier **is** visible via `get_mods()` — it was registered before the second
  key became `tapping_key`. So the override reads `get_mods()` to detect it.

## Design decisions (made with user)

- **Scope: all 6 modifier keys per hand**, not just the 4 home-row mods. Per hand:
  the 4 home-row mods **plus** the 2 upper-row mod-taps (Hyper/Meh). The override
  applies the same-hand-only-chord rule to all 6; plain letters and thumbs fall
  through to stock behavior.
  - Left 6: `ALL_T(KC_F)`, `MEH_T(KC_P)`, `MT(MOD_LCTL,KC_A)`, `MT(MOD_LALT,KC_R)`,
    `MT(MOD_LGUI,KC_S)`, `MT(MOD_LSFT,KC_T)`.
  - Right 6: right-sided Hyper(`U`), right-sided Meh(`L`), `MT(MOD_RSFT,KC_N)`,
    `MT(MOD_RGUI,KC_E)`, `MT(MOD_RALT,KC_I)`, `MT(MOD_RCTL,KC_O)`.
- **Detect "opposite-hand mod held" by mod side (L vs R).** A left-hand mod-tap
  interrupted while any **right-sided** mod bit is held → force tap; a right-hand
  mod-tap while any **left-sided** mod bit is held → force tap.
- **Oryx-side prerequisite (user will do):** the two upper-row mods must be set to
  **hand-matched sides** in Oryx, so mod *side* maps to physical *hand* for all 6
  keys. Stock `ALL_T`/`MEH_T` are hardcoded LEFT-sided (`MOD_HYPR`/`MOD_MEH`); a
  right-hand Meh/Hyper that registered left-sided bits would defeat mod-side
  detection. After the Oryx change the right-hand upper mods register right-sided
  bits (`MT(MOD_RCTL|MOD_RSFT|MOD_RALT|MOD_RGUI, KC_U)` and
  `MT(MOD_RCTL|MOD_RSFT|MOD_RALT, KC_L)`). The override assumes this is in place;
  **verify the built keymap's right-hand upper mods are right-sided before relying
  on the rule** — if Oryx emits left-sided ones, mod-side detection misfires for
  those two keys and we'd fall back to per-keycode special-casing.
- **Scope of force-tap: only opposite-hand mod-tap keys.** Plain letters already
  tap and get modified automatically; the override only neutralizes the mod-tap
  keys that could wrongly join the chord.
- **Config: `PERMISSIVE_HOLD` only — no `HOLD_ON_OTHER_KEY_PRESS`.** Same-hand
  chords settle via permissive hold as they do today; no new config toggle.

## Implementation

Add a `get_chordal_hold` override to the `/* CUSTOM */` block in `keymap.c`
(currently only holds `get_flow_tap_term`, `keymap.c:490-507`). Pseudocode:

```c
// Left-hand home-row mod-taps use LEFT-sided mods; right-hand use RIGHT-sided.
// Rule 4: an opposite-hand mod-tap must never join the chord. If a mod is already
// held on the other side, force this mod-tap to settle as a TAP so it is *modified*
// by the existing chord instead of registering its own modifier.
bool get_chordal_hold(uint16_t tap_hold_keycode, keyrecord_t *tap_hold_record,
                      uint16_t other_keycode, keyrecord_t *other_record) {
    if (IS_QK_MOD_TAP(tap_hold_keycode)) {
        char hand = chordal_hold_handedness(tap_hold_record->event.key);
        uint8_t mods = get_mods();
        const uint8_t L = MOD_BIT(KC_LCTL)|MOD_BIT(KC_LALT)|MOD_BIT(KC_LGUI)|MOD_BIT(KC_LSFT);
        const uint8_t R = MOD_BIT(KC_RCTL)|MOD_BIT(KC_RALT)|MOD_BIT(KC_RGUI)|MOD_BIT(KC_RSFT);
        if (hand == 'L' && (mods & R)) return false; // right chord held → tap this
        if (hand == 'R' && (mods & L)) return false; // left chord held → tap this
    }
    // Everything else: stock opposite-hands behavior.
    return get_chordal_hold_default(tap_hold_record, other_record);
}
```

This covers all 6 mods per hand automatically: the guard keys on
`IS_QK_MOD_TAP` + the key's `chordal_hold_handedness`, so home-row and upper-row
(Hyper/Meh) mod-taps are treated identically — provided the upper-row mods carry
hand-matched sides (Oryx prerequisite). Thumbs are `'*'` in `chordal_hold_layout`
and are never `'L'`/`'R'`, so they fall through to default and combine freely.

(Exact mod-bit macros / `IS_QK_MOD_TAP` spelling to be verified against
`firmware25` headers during implementation; `chordal_hold_handedness` and
`get_chordal_hold_default` are confirmed present in `action_tapping.c`.)

## Open / verify-at-implementation

1. **Right-hand upper mods must be right-sided** in the built keymap (Oryx
   prerequisite above). Verify the merged `keymap.c` shows right-sided bits for
   the `U`/`L` upper-row mods before trusting mod-side detection for those two.
2. **Interaction with the existing `get_flow_tap_term`** (`keymap.c:496`): Flow
   Tap force-taps incoming mod-taps during a typing streak. With the new override
   enforcing rule 4 directly, the `return 0` on T/N (which previously reopened the
   "ti space" leak) may be redundant or counterproductive. Re-evaluate after the
   override is in; do not change it blindly — user manages Flow Tap via Oryx.
3. **`LT()` thumb / layer-tap keys**: the override guards on `IS_QK_MOD_TAP`, so
   layer-taps are untouched. Confirm no home-row position is an `LT()`.

## Non-goals

- No timing-based leak suppression (`process_record_user` thumb-strip, Flow Tap
  tuning) — superseded by the handedness override.
- No change to the `chordal_hold_layout`, combos, macros, or tapping terms.
- No Oryx-side (`keymap.c` base layer) changes; this is `main`-branch custom code
  per README step 4.

## Test plan (manual, on-device)

| Input | Expected | Rule |
|---|---|---|
| hold T-left, tap I-right | `I` (capital) | 3 |
| hold T-left, tap N-right | `N` (capital) | 3 |
| hold T-left, hold N-right | `N` (capital), NOT Shift+Cmd | 4 ✅ key case |
| hold T-left + S-left, tap N-right | Shift+GUI applied to N | 1 + 3 |
| hold T-left, tap R-left (same hand) | `r` (lowercase, unmodified) | 2 |
| hold Hyper-F-left, hold N-right | N modified, NOT joined to chord | 4 (upper-row) |
| hold Meh-L-right, hold S-left | S modified, NOT joined to chord | 4 (upper-row) |
| hold Hyper-F-left + S-left, tap E-right | Hyper+GUI applied to E | 1 + 3 (mixed rows) |
| fast roll "this" | `this`, no stray caps/mods | regression |
| thumb + any mod | combine freely, unaffected | 5 |
