# vita-ps5-livearea

PS Vita LiveArea UI project inspired by PS5 design, built as a separate experimental project based on the architecture and compatibility approach used by `livearea_nolimits`.

## О проекте

Этот репозиторий — отдельный проект для исследования и разработки кастомного визуального оформления LiveArea. Основная идея — не ломать системный UI, а строить safe runtime layer, которая верифицирует firmware, выбирает compatible profile, валидирует metadata, и только после этого допускает изменения в UI.

## Ссылка на reference

- https://github.com/devnoname120/livearea_nolimits/releases/tag/v2.1.0

Важно: этот проект не дублирует функциональность `livearea_nolimits`, а использует его подход к проверке прошивки, модульной совместимости и fail-closed runtime логике.

## Серийный результат: validation report

Доказанная инженерная веха проекта — это не серия “декоративных коммитов”, а документ с карантинной верификацией реальных candidate hook points.

В проекте добавлен документ:

- `docs/candidate_validation_report.md`

Он содержит:

- список candidate hooks
- классификацию по уровню риска
- условия разрешения для safe activation
- выбранный первый candidate для проверки
- hard-blocked hooks
- validation checklist для fallback и reversibility

## Hook policy и candidate review

Перед реальным patching в проекте используется separate policy layer и review matrix:

- `include/livearea_hook_policy.h`
- `src/livearea_hook_policy.c`
- `docs/livearea_hook_policy.md`
- `docs/livearea_hook_matrix.md`

Это делает проект не “попыткой сломать UI”, а безопасной validation pipeline.

## First candidate selected for real validation

Первый кандидат для реальной проверки:

- `selected_icon_glow`

Причина выбора:

- локальная область highlight
- малая зона влияния
- минимальный риск нарушения shell state
- потенциально reversible при restoration path

## Hard-blocked candidates

Следующие кандидаты явно заблокированы и не должны использоваться до дополнительной проверки:

- full_livearea_redraw
- global_page_lifecycle_patch
- global_layout_composition_patch
- any shared shell state mutation

## Fail-closed architecture

Вся логика построена по модели "fail closed":

1. определить активную прошивку
2. проверить идентичность модуля `SceShell`
3. выбрать compatible firmware profile
4. загрузить profile темы
5. проверить metadata, палитру и ассеты
6. применять кастомный стиль только после успешной валидации
7. если что-то не прошло — включить стандартный LiveArea

## Текущее состояние проекта

На данный момент проект уже имеет:

- safe runtime bootstrap
- firmware-aware validation
- hook matrix
- hook policy guard
- explicit blocked candidates
- a concrete first candidate for validation
- a serious engineering report before any real UI patching

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
