# PS5-inspired design specification

## Visual direction

The project aims to create a PS5-inspired LiveArea style without breaking the underlying Vita shell behavior.

## Core color palette

- Background base: very dark charcoal / near black
- Accent primary: PS5 blue / cyan glow
- Accent secondary: soft white-blue highlight
- Panel fill: glass-like dark slate
- Focus ring: bright cyan-on-black
- Text primary: near-white
- Text secondary: soft gray-blue
- Danger / warning: muted amber for fallback states

## Surface treatment

- layered translucent panels
- subtle gradients with low-opacity blur-like transitions
- soft glow around selected app tiles
- clean icon spacing and density preservation
- dark-to-glow transitions that mimic PS5 interface depth

## Layout rules

- maintain Vita page geometry and icon hitboxes
- avoid major reflow of app positions unless a higher-level shell hook is fully validated
- preserve readability and remain consistent with stock Vita UI behavior
- keep focus states legible even when a custom theme uses darker surfaces

## Icon treatment

- use high-contrast edges for selected icons
- apply glows lightly to avoid over-saturation
- maintain a consistent visual weight across folders and apps
- allow fallback to stock icons when custom assets are unavailable

## Motion guidance

- gentle fade on page transitions
- subtle glow pulse for selected items
- minimal motion to avoid disrupting Vita responsiveness

## Fallback behavior

If a custom asset or patch cannot be validated:
- revert to stock LiveArea appearance
- leave default icon layout unchanged
- disable tutorial or animation overlays
- retain safe shell behavior before theme styling

## Design principle

The theme should feel “PS5-inspired,” not “PS5-recreated.” The goal is to respect Vita constraints while integrating the core visual language of PS5.
