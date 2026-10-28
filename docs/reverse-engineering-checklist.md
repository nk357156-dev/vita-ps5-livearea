# План reverse engineering и реализации

## 1. Исходная точка

Существующий проект `livearea_nolimits` — хороший baseline для понимания, как работает patching Vita shell:
- он валидирует identity shell module
- находит правильный text segment
- применяет firmware-specific patches через `taiInjectData`
- поддерживает compatibility profiles для нескольких версий прошивки

Этот проект должен переиспользовать общую структуру, но ориентироваться на visual rendering вместо ограничений счётчиков.

## 2. Что нужно reverse-engineer'ить

Нужно определить shell-элементы, используемые для рендера LiveArea pages:
- page background
- layout контейнеров иконок
- page text labels
- focus/highlight overlays
- composition folder view
- behavior scroll и transitions

На практике это означает трассировку:
- memory layout `SceShell`
- PAF UI widgets, используемых LiveArea
- загрузки и кэширования изображений иконок
- функций, которые компонуют page elements и overlays

## 3. Вероятный технический путь

### Фаза A — baseline hook discovery
- найти модуль `SceShell`
- определить livearea text segment и module NID
- проверить профиль прошивки и offsets
- сформировать минимальный framework injection patch

### Фаза B — points рисования UI
- найти функции композиции страницы
- захватить или disassemble rendering calls
- определить структуры background и icon overlay
- определить resources текста и hitboxes

### Фаза C — кастомный слой стиля
- заменить или переопределить данные цвета для UI surface
- заменить background textures или overlays
- скорректировать highlight/focus state rendering
- построить стратегию asset fallback для неподдерживаемых прошивок

### Фаза D — runtime safety
- обеспечить обратимость patching
- избегать разрушения логики обновления иконок и страницы
- поддерживать fallback к stock UI на неподдерживаемых layouts модулей

## 4. Стратегия ассетов

Использовать layered asset model:
- base background textures
- accent overlays
- icon masks
- focus glow textures
- custom fonts или text style data

Система ассетов должна поддерживать:
- default stock fallback
- кастомные PS5-like packs
- per-firmware compatibility profiles

## 5. Workflow валидации

1. Валидировать identification модуля и структуру shell text
2. Подтвердить page drawing hooks до injection любого visual override
3. Протестировать минимальное изменение темы на одной прошивке
4. Расширять на больший набор прошивок только после стабильности UI hook

## 6. Оценка риска

Это проект с высоким риском, потому что:
- shell Vita завязан на прошивку
- композиция UI shell тесно связана с memory layout
- неправильный patching способен ломать boot или render LiveArea

Самый безопасный путь — начинать с одного хорошо понятного профиля прошивки и держать все остальные сборки как fallback-only targets.
