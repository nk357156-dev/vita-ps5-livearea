# Политика hook для проверки безопасности LiveArea

## Цель

Проект не должен применять никакое визуальное переопределение LiveArea до тех пор, пока candidate hook не пройдёт строгий policy gate. Это следует той же модели fail-closed, описанной в reference release:

- https://github.com/devnoname120/livearea_nolimits/releases/tag/v2.1.0

## Правила политики

Candidate hook допустим только если выполнены все условия:

- прошивка была проверена
- риск не является высоким
- hook обратим
- hook изолирован в локальном пути рендера
- hook считается безопасным
- fallback остаётся активным

Если какое-либо условие не выполнено, hook должен оставаться заблокированным.

## Состояния политики

- `HOOK_POLICY_BLOCKED` — небезопасно или не проверено
- `HOOK_POLICY_REVIEW` — кандидат существует, требуется валидация
- `HOOK_POLICY_ALLOWED` — валидирован и безопасен для активации

## Начальный набор кандидатов

Первые кандидаты для review должны быть ограничены локальными и изолированными визуальными элементами:

- selected_icon_glow
- text_color_application
- panel_background_frost
- icon_mask_alpha
- widget_glass_overlay
- local_list_item_theme

## Hard-blocked кандидаты

Следующие явно заблокированы до доказательства безопасности:

- full_livearea_redraw
- global_page_lifecycle_patch
- global_layout_composition_patch
- любая мутация shell-wide state
- любой patch, затрагивающий общие UI-контейнеры без пути отката

## Логика оценки

Политика должна отклонять hook, когда:

```c
if (policy->risk == 2)
    return -1;

if (!policy->firmware_checked)
    return -1;

if (!policy->reversible)
    return -1;

if (!policy->isolated)
    return -1;

if (!policy->safe)
    return -1;
```

## Модель безопасной активации

Только после того, как кандидат проходит policy gate, он может войти в активную стадию.
Hook всё равно должен оставаться под контролем fallback.

Эта политика существует, чтобы предотвратить небезопасные прямые изменения состояния Vita LiveArea.
