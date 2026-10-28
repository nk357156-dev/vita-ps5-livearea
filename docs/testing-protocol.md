# Test protocol and validation

## Goal

Define a safe test process for validating custom UI hooks without damaging the Vita shell.

## Validation phases

### Phase 1: static validation
- verify module identity
- check text segment size
- confirm hook points are not out of range
- validate patch metadata and fallback conditions

### Phase 2: stock fallback validation
- enable theme engine with fallback mode on
- verify stock UI remains visible if theme injection is impossible

### Phase 3: minimal visual activation
- use one known-good firmware profile
- enable only one UI component at a time
- verify page rendering and icon selection

### Phase 4: extended validation
- validate on a second firmware profile
- compare crash-free behavior and layout stability
- only then expand to additional hardware classes

## Test checklist

Before each test:
- [ ] confirm module is loaded
- [ ] confirm stock UI is available as fallback
- [ ] confirm logs are active
- [ ] confirm custom asset pack exists
- [ ] confirm no unsupported profile is active

During each test:
- [ ] open LiveArea
- [ ] navigate pages
- [ ] open folders
- [ ] focus and select icons
- [ ] verify no visual corruption or crashes

Pass criteria:
- no crash
- no broken page composition
- no missing app tiles
- no invalid selection state
- stock UI remains available if theme is disabled

## Failure policy

Any visual corruption, module crash, or render break should immediately:
- disable visual hook
- revert to stock UI
- log the exact compatibility issue
- stop expansion to other firmware profiles until fixed
