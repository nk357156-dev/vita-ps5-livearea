# Структура проекта

Этот проект намеренно начинается как чистый plugin scaffold, отдельный от существующего плагина `livearea_nolimits`.

## Директории

- `src/` — основной исходный код
- `include/` — публичные заголовки
- `assets/` — UI-ресурсы и заглушки
- `docs/` — заметки и планы
- `tests/` — scripts in test и smoke tests

## Ключевые исходники

- `src/main.c` — entry points модуля
- `src/theme_patch.c` — логика patching shell и theme hooks
- `src/asset_loader.c` — загрузка ассетов и ресурсов
- `src/patch_bytes.S` — helper'ы для injection patch
