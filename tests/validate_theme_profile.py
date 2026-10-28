#!/usr/bin/env python3
import json
import sys
from pathlib import Path

REQUIRED_KEYS = {
    "theme_name",
    "version",
    "style",
    "fallback_mode",
    "fallback_enabled",
    "requires_background",
    "requires_overlays",
    "requires_icons",
    "requires_labels",
    "supported_firmware",
    "palette",
}

ALLOWED_STYLES = {"default", "neon", "glass", "neon-glass"}


def fail(msg: str) -> None:
    print(f"ERROR: {msg}", file=sys.stderr)
    raise SystemExit(1)


def validate_palette(palette: dict) -> None:
    if not isinstance(palette, dict):
        fail("palette must be an object")

    required = {
        "bg_base",
        "bg_surface",
        "panel",
        "panel_frost",
        "accent_primary",
        "accent_secondary",
        "glow_cyan",
        "text_primary",
        "text_secondary",
        "success",
        "warning",
    }

    missing = required - set(palette.keys())
    if missing:
        fail(f"missing palette fields: {sorted(missing)}")

    for key, value in palette.items():
        if not isinstance(value, str):
            fail(f"palette field '{key}' must be a string")
        if not value.startswith("0x") and not value.startswith("0X"):
            fail(f"palette field '{key}' must be a hex string like 0xAABBCC")


def main() -> int:
    root = Path(__file__).resolve().parent.parent
    path = root / "assets" / "theme_metadata.json"

    if not path.exists():
        fail(f"missing metadata file: {path}")

    try:
        with path.open("r", encoding="utf-8") as f:
            data = json.load(f)
    except json.JSONDecodeError as exc:
        fail(f"invalid JSON: {exc}")

    missing = REQUIRED_KEYS - set(data.keys())
    if missing:
        fail(f"missing required keys: {sorted(missing)}")

    if not isinstance(data["theme_name"], str) or not data["theme_name"].strip():
        fail("theme_name must be a non-empty string")

    if not isinstance(data["version"], str) or not data["version"].strip():
        fail("version must be a non-empty string")

    if not isinstance(data["style"], str) or data["style"] not in ALLOWED_STYLES:
        fail(f"style must be one of: {sorted(ALLOWED_STYLES)}")

    if not isinstance(data["fallback_mode"], str) or not data["fallback_mode"].strip():
        fail("fallback_mode must be a non-empty string")

    for key in ["fallback_enabled", "requires_background", "requires_overlays", "requires_icons", "requires_labels"]:
        if not isinstance(data[key], bool):
            fail(f"{key} must be bool")

    if not isinstance(data["supported_firmware"], list) or len(data["supported_firmware"]) == 0:
        fail("supported_firmware must be a non-empty array")

    for firmware in data["supported_firmware"]:
        if not isinstance(firmware, str) or not firmware.strip():
            fail("each firmware entry must be a non-empty string")

    validate_palette(data["palette"])

    print("Theme metadata validation passed.")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
