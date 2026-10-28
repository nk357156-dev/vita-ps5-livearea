# Спецификация ассетов

## Цель

Определить структуру кастомного asset pack для PS5-inspired LiveArea темы.

## Обязательные категории ассетов

### 1. Backgrounds
- базовый фон страницы
- вариации фоновых изображений папок
- overlay страницы приложений
- ambient glow textures

### 2. Panels and overlays
- полупрозрачные glass panels
- overlay для focus frame
- маски состояния selected
- формы подсветки папок

### 3. Icons and masks
- overlay иконок приложений
- маски selected icon
- варианты иконок папок
- нейтральные default fallback icons

### 4. Typography and labels
- metadata цветов подписи
- стили текста selected vs unselected
- необязательные переопределения шрифта

## Формат asset pack

Простая структура пакета может быть такой:

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

## Пример metadata

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

## Правила fallback

- если необходимые файлы отсутствуют, использовать stock LiveArea assets
- если прошивка неподдерживается, немедленно отключить кастомные пакеты
- если память ассетов слишком велика, уменьшить разрешение текстур до failover
