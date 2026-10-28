# vita-ps5-livearea

PS Vita LiveArea UI project inspired by PS5 design, созданный как отдельный экспериментальный проект на основе архитектуры и подхода к совместимости, используемых в `livearea_nolimits`.

## О проекте

Этот репозиторий — отдельный проект для исследования и разработки кастомного визуального оформления LiveArea на PlayStation Vita. Основная идея состоит в том, чтобы сохранить безопасную, совместимую и обратимую модель применения пользовательского стиля, не разрушая базовый shell.

## Ссылка на reference

- https://github.com/devnoname120/livearea_nolimits/releases/tag/v2.1.0

Важно: этот проект не дублирует функциональность `livearea_nolimits`, а использует его подход к проверке прошивки, модулей и безопасного fallback.

## Серьёзный milestone: первый реальный кандидат для валидации hook

Первым целевым кандидатом для реальной верификации является:

- `selected_icon_glow`

Документ:

- `docs/selected_icon_glow_validation.md`

Он описывает:

- классификацию риска
- критерии принятия
- поток валидации
- требования к откату и fallback
- hard-blocked кандидаты
- текущий статус = `REVIEW`

## Hook policy и безопасная модель review

Перед реальным patching проект использует policy layer и review matrix:

- `include/livearea_hook_policy.h`
- `src/livearea_hook_policy.c`
- `docs/livearea_hook_policy.md`
- `docs/livearea_hook_matrix.md`
- `docs/hook_investigation.md`
- `docs/candidate_validation_report.md`

Это делает архитектуру проекта fail-closed, а не "сразу с patching".

## Статус первого кандидата

`selected_icon_glow` в настоящее время остаётся в состоянии `REVIEW`.

Он выбран потому, что является лучшим локальным кандидатом с низким риском, но всё ещё требует доказательств:

- совместимости с прошивкой
- локальной безопасности
- обратимости
- восстановления fallback
- отсутствия утечки в соседние элементы

Это корректная инженерная позиция перед любым реальным UI override.

## Hard-blocked кандидаты

Следующие кандидаты остаются заблокированными до доказательства безопасности:

- full_livearea_redraw
- global_page_lifecycle_patch
- global_layout_composition_patch
- shared_shell_state_mutation

## Fail-closed архитектура

Вся логика построена по модели "fail closed":

1. определить активную прошивку
2. проверить идентичность модуля `SceShell`
3. выбрать совместимый профиль прошивки
4. загрузить профиль темы
5. проверить metadata, палитру и ассеты
6. применять кастомный стиль только после успешной валидации
7. если что-то не прошло — включить стандартный LiveArea

## Итог

На данном этапе проект уже имеет:

- безопасный runtime bootstrap
- flow валидации, зависящий от прошивки
- hook matrix
- hook policy layer
- конкретный первый кандидат на review (`selected_icon_glow`)
- явный список заблокированных высокорисковых patch'ей глобального состояния

Это корректная серьёзная инженерная стадия до реального LiveArea override.
