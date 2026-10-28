# Матрица кандидатов hook для review безопасности LiveArea

## Цель

До любого реального переопределения UI каждый кандидат рендера LiveArea должен быть проверен по правилам fail-closed, используемым в `livearea_nolimits` v2.1.0:

- прошивка валидирована
- hook должен быть обратим
- hook должен быть изолирован
- fallback должен оставаться активным
- высокорисковые пути остаются заблокированными

## Матрица кандидатов

| Имя | Категория | Риск | Прошивка проверена | Обратим | Изолирован | Безопасен | Вердикт |
|------|-----------|------|-------------------|---------|-----------|-----------|--------|
| panel_background_redraw | background | low | no | no | no | no | blocked |
| selected_icon_glow | highlight | low | no | no | no | no | blocked |
| glass_overlay_layer | overlay | medium | no | no | no | no | blocked |
| icon_mask_alpha | icon rendering | medium | no | no | no | no | blocked |
| text_color_application | text | low | no | no | no | no | blocked |
| layout_spacing_override | layout | medium | no | no | no | no | blocked |
| full_livearea_redraw | shell layout | high | no | no | no | no | blocked |
| global_page_lifecycle_patch | shell lifecycle | high | no | no | no | no | blocked |

## Политика риска

### Low risk

Подходит для исследования только при выполнении всех условий:

- локальный widget / rendering path
- отсутствие глобального влияния на shell
- обратимый in-place patch или override
- доступен безопасный fallback

Примеры:
- подсветка выбранного элемента
- цвет текста локального элемента
- неглобальное оформление фона

### Medium risk

Требует более глубокой проверки до активации:

- стеклянные overlay эффекты
- маски/icon alpha pass
- локальные tweaks spacing layout

Hook среднего риска не блокируются автоматически, но требуют явной проверки прошивки и доказательства полной обратимости.

### High risk

Всегда блокируются до доказательства безопасности.

Примеры:
- полный redraw LiveArea
- патч жизненного цикла shell
- замена глобального render object
- всё, что изменяет общее состояние layout между страницами

## Обязательные проверки перед активацией любого hook

1. совместимость прошивки подтверждена
2. модуль shell совместим
3. hook изолирован до одного компонента
4. stock UI может быть восстановлен без reset
5. отсутствует глобальное повреждение визуального состояния
6. путь fallback остаётся активным

## Текущий статус

Эта матрица — список review, а не список активации. В данный момент ни один кандидат не считается безопасным для реального patching.

Это правильная стадия для проекта: безопасная каталогизация возможных hook перед реальными изменениями LiveArea.
