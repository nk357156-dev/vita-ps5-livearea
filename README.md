# vita-ps5-livearea

PS Vita LiveArea UI project inspired by PS5 design, built as a separate experimental project based on the architecture and compatibility approach used by `livearea_nolimits`.

## О проекте

Этот репозиторий — отдельный проект для исследования и разработки кастомного визуального оформления LiveArea. Основная идея — не ломать системный UI, а строить safe runtime layer, которая верифицирует firmware, выбирает compatible profile, валидирует metadata, и только после этого допускает изменения в UI.

## Почему отдельный проект

`livearea_nolimits` — это проект, решающий другую задачу:
- увеличение количества LiveArea страниц
- увеличение количества иконок
- управление кэшированием иконок
- патчинг `SceShell` под конкретные прошивки

Наш проект решает другую задачу:
- создание PS5-подобной визуальной темы для LiveArea
- управление стилем и цветовой схемой
- загрузка профиля темы и ассетов
- безопасная валидация прошивки перед применением темы
- откат к стандартному интерфейсу при несовместимости

## Ссылка на reference

- https://github.com/devnoname120/livearea_nolimits/releases/tag/v2.1.0

Важно: этот проект не дублирует функциональность `livearea_nolimits`, а использует его подход к проверке прошивки, модульной совместимости и fail-closed runtime логике.

## Безопасный протокол hook investigation

Мы не начали прямой UI patching. Перед любым реальным override у LiveArea должны быть выполнены следующие проверки:

1. Проверка firmware profile
2. Проверка совместимости `SceShell`/LiveArea module
3. Проверка theme profile
4. Проверка metadata и ассетов
5. Проверка риска hook
6. Проверка reversibility и isolation
7. Только после этого — safe hook activation
8. Всегда доступен fallback в стандартный UI

Протокол описан в `docs/hook_investigation.md`.

## Hook candidate matrix

Перед реальным патчингом мы формируем матрицу потенциальных hook points и оцениваем их по риску:

- low risk: isolated UI piece, local rendering path
- medium risk: local visual layer or layout effect
- high risk: global shell state or lifecycle patch

Матрица хранится в `docs/livearea_hook_matrix.md` и поддерживается через `include/livearea_hook_matrix.h` / `src/livearea_hook_matrix.c`.

## Fail-closed architecture

Вся логика построена по модели "fail closed":

1. определить активную прошивку
2. проверить идентичность модуля `SceShell`
3. выбрать compatible firmware profile
4. загрузить profile темы
5. проверить metadata, палитру и ассеты
6. применять кастомный стиль только при успешной валидации
7. если что-то не прошло — включить стандартный LiveArea

## Safe hook candidate model

Под безопасные hook рассматриваются только точки, которые удовлетворяют требованиям:

- firmware checked
- not high-risk
- reversible
- isolated
- fallback available

Подход описан в `include/livearea_hook_guard.h` и `src/livearea_hook_guard.c`.

## Цель проекта

Создать PS5-inspired визуальное оформление для LiveArea PS Vita, сохранив:
- стабильность работы интерфейса
- безопасный fallback в стандартный UI
- поддержку поиска и валидации совместимых firmware profile
- разделение стиля, ассетов и логики патчей

## Текущее состояние

На данный момент репозиторий находится в стадии инженерного каркаса и проектной архитектуры. В нём уже есть:
- базовый скелет Vita module
- runtime-конфигурация темы
- модель профиля темы
- валидация metadata и palette
- логика fallback в стандартный LiveArea
- модель совместимости по firmware
- guard для pre-hook validation
- протокол безопасного исследования hook points
- матрица candidate hook points

## Архитектура проекта

- `src/` — исходный код runtime и логики темы
- `include/` — заголовки и API интерфейсы
- `assets/` — ассеты, палитры, metadata пакета темы
- `profiles/` — профили визуальных тем
- `docs/` — документы по архитектуре, дизайну и валидации
- `tests/` — скрипты валидации профилей и metadata
- `CMakeLists.txt` — сборка проекта под VitaSDK
- `vita_ps5_livearea.yml` — модульные метаданные

## Поддерживаемые firmware

В текущей модели проект ориентируется на семейства прошивок, которые уже были использованы в исследовании:

- Retail PS Vita / PSTV: 3.60–3.74
- Testkit: 3.60, 3.61, 3.63, 3.65, 3.67, 3.68, 3.70, 3.72, 3.73
- Devkit: 3.60, 3.61, 3.63, 3.65, 3.67, 3.68, 3.69, 3.70, 3.71, 3.73

## Сборка

Для сборки требуется VitaSDK и CMake.

```sh
cmake -S . -B build -G Ninja \
  -DCMAKE_BUILD_TYPE=Release
cmake --build build
```

Результат сборки:

```text
build/vita_ps5_livearea.suprx
```

## Важное замечание

Это проект исследовательского характера. Он не обещает готовый PS5 UI для всех прошивок сразу. Реальный визуальный override должен происходить только после безопасной верификации hook point и профиля прошивки.

## Roadmap

1. Проверить и подтвердить `SceShell`-маршруты LiveArea
2. Найти безопасные точки рендера и хуки
3. Валидировать совместимость по firmware profile
4. Загрузить активный theme profile
5. Проверить metadata и ассеты
6. Подключить визуальные override только после успешной валидации
7. Расширять поддержку только на протестированных профилях

## Итог

Этот проект — безопасная, firmware-aware основа для создания PS5-inspired LiveArea для PS Vita. Он использует подходы, проверенные в `livearea_nolimits`, но сохраняет изоляцию, безопасный fallback и fail-closed runtime logic.

Если цель — сделать именно кастомный LiveArea в PS5-стиле, этот репозиторий — правильная точка старта.
