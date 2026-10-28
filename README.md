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

Это уже шаг от “чистого каркаса” к “реально проверяемой архитектуре”.

## Следующий этап

Следующий этап — не “делать красивый UI”, а проверить реальный `selected_icon_glow` candidate по full safety checklist и при необходимости заменить его на другой local hook candidate.

Это и есть серьёзный результат, который соответствует reference architecture и не рискует системным UI.
