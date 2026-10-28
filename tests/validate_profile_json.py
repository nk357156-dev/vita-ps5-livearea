#!/usr/bin/env python3
import json
import sys
from pathlib import Path


def fail(msg: str):
    print(f"ERROR: {msg}", file=sys.stderr)
    raise SystemExit(1)


def validate_profile(path: Path):
    try:
        data = json.loads(path.read_text(encoding="utf-8"))
    except json.JSONDecodeError as exc:
        fail(f"{path}: invalid JSON: {exc}")

    required = {
        "name", "style", "enabled", "glass_mode", "neon_accent",
        "dynamic_background", "custom_icons", "ui_scale", "palette"
    }

    missing = required - set(data.keys())
    if missing:
        fail(f"{path}: missing keys: {sorted(missing)}")

    if not isinstance(data["name"], str) or not data["name"].strip():
        fail(f"{path}: name must be non-empty string")

    if data["style"] not in {"default", "neon", "glass", "neon-glass"}:
        fail(f"{path}: unsupported style {data['style']}")

    for key in ["enabled", "glass_mode", "neon_accent", "dynamic_background", "custom_icons"]:
        if not isinstance(data[key], bool):
            fail(f"{path}: {key} must be bool")

    if not isinstance(data["ui_scale"], int):
        fail(f"{path}: ui_scale must be int")

    palette = data["palette"]
    required_palette = {
        "bg_base", "bg_surface", "panel", "panel_frost",
        "accent_primary", "accent_secondary", "glow_cyan",
        "text_primary", "text_secondary", "success", "warning"
    }

    missing_palette = required_palette - set(palette.keys())
    if missing_palette:
        fail(f"{path}: missing palette values: {sorted(missing_palette)}")

    for key, value in palette.items():
        if not isinstance(value, str) or not value.startswith("0x"):
            fail(f"{path}: palette {key} must be hex string like 0xAABBCC")


def main():
    root = Path(__file__).resolve().parent.parent
    profiles_dir = root / "profiles"
    if not profiles_dir.exists():
        fail(f"missing profiles directory: {profiles_dir}")

    for path in sorted(profiles_dir.glob("*.json")):
        validate_profile(path)

    print("Theme profile JSON validation passed.")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
