# Asset specification

## Purpose

Define the structure of a custom asset pack for the PS5-inspired LiveArea theme.

## Required asset categories

### 1. Backgrounds
- page background base
- folder background variations
- app page overlays
- ambient glow textures

### 2. Panels and overlays
- translucent glass panels
- focus frame overlays
- selected state masks
- folder highlight shapes

### 3. Icons and masks
- app icon overlays
- selected icon masks
- folder icon variants
- neutral default fallback icons

### 4. Typography and labels
- label color metadata
- selected vs unselected text styles
- optional font overrides

## Asset pack format

A simple pack layout could be:

```text
assets/
  default/
    backgrounds/
    overlays/
    icons/
    metadata.json
  fallback/
    stock/
```

## Metadata example

```json
{
  "theme": "vita-ps5-livearea",
  "version": "0.1.0",
  "style": "neon-glass",
  "fallback": "stock-livearea",
  "requires": ["background", "overlay", "icons"],
  "supported_firmware": ["3.60", "3.65", "3.73"]
}
```

## Fallback rules

- if required files are missing, use stock LiveArea assets
- if a firmware is unsupported, disable custom packs immediately
- if asset memory is too large, reduce texture resolution before failover
