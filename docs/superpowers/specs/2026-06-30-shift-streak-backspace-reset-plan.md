# Planned change: Backspace resets the Shift streak term

**Date:** 2026-06-30
**Status:** PLANNED (not yet implemented)
**File:** `PWK6Z/keymap.c` — the `pre_process_record_user` in the `/* CUSTOM */` block
**Firmware:** `zsa/qmk_firmware` @ `firmware25`

## Context

The two Shift mod-taps (`MT(MOD_LSFT,KC_T)`, `MT(MOD_RSFT,KC_N)`) use a two-level
streak-dependent tapping term (commit `5021d3b`):

- fresh (gap since previous key >= 200 ms) -> **100** (Shift holds quickly)
- mid-streak (gap < 200 ms) -> **TAPPING_TERM (250)** (quick presses stay taps)

State lives in `pre_process_record_user`: `static uint16_t shift_streak_prev_time`
holds the previous key's press time; `shift_streak_term` is recomputed each press
and read by `get_tapping_term`.

## The change

**When the last pressed key is Backspace, reset the streak** so the *next* key is
treated as fresh (term 100). Rationale: pressing Backspace signals "I'm fixing a
typo," so an immediately-following Shift (or other mod) should hold fast rather
than be suppressed as mid-streak.

### Decisions (made with user)

- **Which Backspace forms:** BOTH `KC_BSPC` (base-layer thumb) and
  `LT(5, KC_BSPC)` (layer-tap on layers 1/2/3, where Backspace is the tap action).
  "Backspace" means Backspace regardless of form/layer.
- **Reset timing:** the *next* key after Backspace is fresh (term 100),
  regardless of how quickly it follows the Backspace.

### Implementation sketch

In `pre_process_record_user`, on a key **press**, after computing the term for
the current key, detect whether the current key is Backspace and, if so, arm the
"next key is fresh" state.

Match both forms. `LT(5, KC_BSPC)`'s tap keycode is `KC_BSPC`; the cleanest match
is either an explicit `case KC_BSPC: case LT(5, KC_BSPC):` or reducing via the
tap-keycode helper. Prefer the explicit two-case match to avoid pulling in extra
helpers and to keep it obviously correct:

```c
bool pre_process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        uint16_t gap = TIMER_DIFF_16(record->event.time, shift_streak_prev_time);
        shift_streak_term = (gap >= SHIFT_STREAK_RESET_MS) ? SHIFT_STREAK_FRESH_TERM
                                                           : TAPPING_TERM;

        // Backspace = correcting a typo -> make the NEXT key fresh (term 100),
        // regardless of how fast it follows. Arm this by back-dating prev_time so
        // the next key's gap is guaranteed >= SHIFT_STREAK_RESET_MS.
        if (keycode == KC_BSPC || keycode == LT(5, KC_BSPC)) {
            shift_streak_prev_time = record->event.time - SHIFT_STREAK_RESET_MS;
        } else {
            shift_streak_prev_time = record->event.time;
        }
    }
    return true;
}
```

Note the back-dating trick: setting `shift_streak_prev_time` to
`event.time - SHIFT_STREAK_RESET_MS` guarantees the next key computes
`gap >= SHIFT_STREAK_RESET_MS` -> fresh. This avoids adding a separate boolean
flag and keeps all state in the one existing variable. (16-bit wraparound is fine:
`TIMER_DIFF_16` is modular subtraction, so a back-dated value near the timer wrap
still yields the correct difference for the next key within the window.)

### Verify at implementation

1. Confirm `LT(5, KC_BSPC)` is the exact layer-tap keycode in the current keymap
   (layers 1/2/3, thumb). If Oryx changes the layer number, update the case.
2. Confirm the back-dating expression yields `gap >= 200` on the next key in
   practice (unit-reason through TIMER_DIFF_16 modular math; it holds).
3. Build clean against firmware25 (`make zsa/voyager:PWK6Z`) before flashing.

### Non-goals

- No change to the 100/250 levels or the 200 ms reset gap.
- No effect on non-Shift keys (they don't read `shift_streak_term`).
