# vita-ps5-livearea

PS Vita LiveArea UI project inspired by PS5 design, built as a separate experimental project based on the architecture and compatibility approach used by `livearea_nolimits`.

## О проекте

Этот репозиторий — отдельный проект для исследования и разработки кастомного визуального оформления LiveArea. Основная идея — не ломать системный UI, а строить safe runtime layer, которая верифицирует firmware, выбирает compatible profile, валидирует metadata, и только после этого допускает изменения в UI.

## Ссылка на reference

- https://github.com/devnoname120/livearea_nolimits/releases/tag/v2.1.0

Важно: этот проект не дублирует функциональность `livearea_nolimits`, а использует его подход к проверке прошивки, модульной совместимости и fail-closed runtime логике.

## Серьёзный milestone: first real hook validation candidate

Первый целевой candidate для реальной верификации — это:

- `selected_icon_glow`

Документ:

- `docs/selected_icon_glow_validation.md`

Он описывает:

- risk classification
- acceptance criteria
- validation flow
- revert and fallback requirements
- hard-blocked candidates
- current status = `REVIEW`

## Hook policy and safe review model

Перед реальным patching проект использует policy layer и review matrix:

- `include/livearea_hook_policy.h`
- `src/livearea_hook_policy.c`
- `docs/livearea_hook_policy.md`
- `docs/livearea_hook_matrix.md`
- `docs/hook_investigation.md`
- `docs/candidate_validation_report.md`

Это делает архитектуру проекта fail-closed, а не “сразу с patching”.

## First candidate status

`selected_icon_glow` currently remains in `REVIEW` state.

It is selected because it is the best low-risk local candidate, but it still needs proof of:

- firmware compatibility
- local-scope safety
- reversibility
- fallback restoration
- no leakage to adjacent elements

This is the correct engineering posture before any actual UI override.

## Hard-blocked candidates

The following remain blocked until proven safe:

- full_livearea_redraw
- global_page_lifecycle_patch
- global_layout_composition_patch
- shared_shell_state_mutation

## Fail-closed architecture

Вся логика построена по модели "fail closed":

1. определить активную прошивку
2. проверить идентичность модуля `SceShell`
3. выбрать compatible firmware profile
4. загрузить profile темы
5. проверить metadata, палитру и ассеты
6. применять кастомный стиль только после успешной валидации
7. если что-то не прошло — включить стандартный LiveArea

## Итог

На данном этапе проект уже имеет:

- safe runtime bootstrap
- firmware-aware validation flow
- hook matrix
- hook policy layer
- a concrete first review candidate (`selected_icon_glow`)
- a clear blocked pool for high-risk global state patches

This is the correct serious engineering stage before actual LiveArea override.
