# PS5 UI Style Guide for Vita LiveArea

## Purpose

This document defines a PS5-inspired visual language for the Vita LiveArea redesign project. The goal is to capture the atmosphere and clarity of the PS5 interface while respecting the technical and layout constraints of the PlayStation Vita shell.

This style guide is intended as a design reference for the custom LiveArea theme in this repository and is intentionally adapted for a lower-resolution, lower-contrast, and more constrained shell environment.

## Design philosophy

The visual system should feel:
- premium and clean
- high-contrast and readable
- layered and atmospheric
- minimal but expressive
- futuristic, but not noisy

The interface must not feel like a direct PS5 port. Instead, it should be a Vita-native interpretation of PS5 design language.

## Core visual identity

### 1. Base color palette

Use a dark foundation with restrained neon highlights.

Primary colors:
- Background base: #090B12
- Surface dark: #121821
- Card panel: #181F2B
- Panel frost: #1E2A3A
- Primary accent: #5BC0FF
- Secondary accent: #7F9BFF
- Glow cyan: #72E5FF
- Text primary: #F5F7FB
- Text secondary: #B7C2D9
- Muted emphasis: #7D8AA7
- Success accent: #7BE0A0
- Warning accent: #FFCC66

### 2. Contrast strategy

- Keep backgrounds dark and layered
- Use accent colors sparingly, mostly for selected states, focus rings, and highlight elements
- Maintain strong readability for app names and labels
- Avoid bright full-screen neon effects that can reduce legibility

### 3. Surface treatment

Use layered glass-like panels:
- low-opacity dark fill
- subtle gradients with soft transparency
- soft edge lighting
- clean separation between UI surfaces and content

The goal is to create a pseudo-glass treatment without making the Vita shell look too heavy or visually noisy.

## Layout language

### 1. Page structure

The Vita LiveArea retains a compact, grid-driven composition. The custom design should respect:
- icon grid spacing
- page alignment and page boundaries
- folder geometry
- app naming layout
- selection focus behavior

The system should not fundamentally change the shell layout unless a specific shell hook is validated.

### 2. Panel rhythm

Use a consistent rhythm for:
- app tiles
- folder groups
- page headers
- page overlays
- action focus states

Keep margins generous enough to preserve readability but tight enough to retain the Vita aesthetic.

### 3. Spatial hierarchy

The interface should use a clear hierarchy:
- background is the environment
- cards and panels are the furniture
- selected app is the visual focal point
- accent glow marks the active item or selected state

This is especially important on Vita, where display area is limited and information density is high.

## Icon language

### 1. Icon shell

Icons should remain compact, recognizable, and easy to scan. Custom rendering should avoid broad changes to icon aspect ratio.

Recommended treatment:
- subtle soft corner rounding
- dark base plate behind the icon
- clean accent glow around focus/selection
- low-intensity border or outline on active state

### 2. Focus state

The selected or focused app tile should be visually obvious without overpowering the rest of the page.

Selected tile treatment:
- brighter ambient glow
- cyan/blue border or rim
- elevated surface or panel lift
- subtle shadow or highlight edge

### 3. Folder appearance

Folder tiles should feel distinct but consistent:
- slightly more saturated focus states
- neutral base with accent border
- clean separation from regular app tiles
- include minimal visual difference so the user still understands structure

## Typography

### 1. Type behavior

The UI should use a readable, geometric sans-serif look with a clean, modern profile. It should feel premium and tech-forward, not playful.

Recommended type principles:
- high legibility on dark backgrounds
- minimal letter spacing for names
- stronger weight for active selection
- lower emphasis for metadata or secondary info

### 2. Label hierarchy

- app titles: primary text
- folder labels: medium emphasis
- secondary metadata: low emphasis, short and minimal
- active selection: brighter weight and stronger contrast

### 3. Accessibility

When using cyan and white-on-dark combinations, ensure:
- sufficient contrast ratio
- no unreadable text in low light conditions
- no excessive glow that reduces legibility

## Motion and interaction design

### 1. Motion characteristics

Keep motion subtle and purposeful:
- short fade-in for selection / focus
- smooth page transitions
- minimal bounce or overshoot
- no abrupt flashing or neon pulses

### 2. Interaction expectations

Selection should feel immediate and controlled:
- short glow ramp on focus
- subtle panel lift or shadow increase
- smooth movement when navigating pages

### 3. Performance constraints

On the Vita, motion should remain lightweight. Prioritize:
- low-cost transitions
- minimal particle effects
- restrained alpha blending
- reduced effects when system load is high

## PS5-inspired flavor, adapted to Vita

The project should borrow the following PS5 design cues without violating Vita constraints:

- dark base + bright accent framing
- layered translucent panels
- UI depth via subtle gradients and soft lighting
- high-legibility selected states
- premium industrial look with minimal ornament
- controlled glow as a focus and highlight signal

Avoid these traits:
- overly bright full-color backgrounds
- excessive neon noise
- heavy motion effects or animated background clutter
- complex glass layering that hurts readability or performance
- unplanned changes to Vita icon geometry and layout

## Fallback behavior

When the theme cannot be validated or a custom asset is missing:
- revert to the stock Vita LiveArea layout
- disable custom glow or accent overlays
- return to default icon state and page composition
- leave the system in a stable fallback mode

Fallback is mandatory and must be treated as a first-class design requirement.

## Example style state table

### Default state
- background: dark charcoal
- panels: translucent slate
- accent: subtle blue cyan
- selection: brighter cyan rim
- text: near-white, high contrast

### Focused state
- border glow: cyan or soft blue
- panel slightly elevated
- selected icon brighter and more saturated
- text weight increases slightly

### Folder state
- muted panel background
- accent on folder header or selected edge
- folder icon glow with smaller intensity than active app tiles

### Disabled or fallback state
- stock Vita rendering
- no custom accent or overlays
- no custom UI composition

## Implementation guidance

When implementing this style in the project:

- keep the rule set modular
- separate color spec from shell patch logic
- keep the custom rendering layer optional
- make the theme profile-selectable by firmware
- maintain asset and theme fallback paths

## Acceptance criteria for the visual design

The PS5-inspired theme should be accepted only if:
- the Vita shell remains readable and stable
- selected state is clearly visible
- app icons remain recognizable and easy to scan
- the interface feels premium and coherent without heavy visual noise
- fallback mode remains robust and safe

## Summary

The PS5-inspired style should feel like a Vita-native reinterpretation of PS5 design language: dark, clean, premium, expressive, and clear. The emphasis is not on making Vita look exactly like PS5, but on bringing the spirit of PS5 clarity and polish into a constrained and firmware-sensitive Vita environment.
