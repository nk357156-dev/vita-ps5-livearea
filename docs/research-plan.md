# Руководство по стилю UI PS5 для Vita LiveArea

## Цель

Этот документ задаёт PS5-inspired визуальный язык для redesign проекта Vita LiveArea. Цель — захватить атмосферу и ясность интерфейса PS5, сохраняя технические и конструктивные ограничения shell Vita.

Этот style guide предназначен как reference для кастомной LiveArea темы в этом репозитории и намеренно адаптирован под более низкое разрешение, более слабый контраст и более ограниченный shell.

## Философия дизайна

Визуальная система должна ощущаться:
- премиальной и чистой
- высококонтрастной и читаемой
- слоистой и атмосферной
- минималистичной, но выразительной
- футуристичной, но не шумной

Интерфейс не должен ощущаться как прямой port PS5. Вместо этого он должен быть Vita-native интерпретацией языка дизайна PS5.

## Ключевая визуальная идентичность

### 1. Базовая цветовая палитра

Использовать тёмную основу с умеренными неоновыми акцентами.

Основные цвета:
- Background base: #090B12
- Surface dark: #121821
- Card panel: #181F2B
- Panel frost: #1E2A3A
- Primary accent: #5BC0FF
- Secondary accent: #7F9BFF
- Glow cyan: #72E5FF
- Text primary: #F5F7FB
- Text secondary: #B7C2D9
- Muted emphasis: #7D8AA7
- Success accent: #7BE0A0
- Warning accent: #FFCC66

### 2. Стратегия контраста

- держать фоны тёмными и слоистыми
- использовать акцентные цвета дозированно, в основном для selected states, focus rings и highlight элементов
- сохранять сильную читаемость для названий приложений и labels
- избегать ярких full-screen neon эффектов, снижающих читабельность

### 3. Обработка поверхностей

Использовать layered glass-like панели:
- низкая непрозрачность тёмной заливки
- мягкие градиенты с лёгкой прозрачностью
- мягкое edge lighting
- чистое разделение между UI surfaces и контентом

Цель — создать псевдо-glass treatment без слишком тяжёлого или шумного вида shell Vita.

## Язык layout

### 1. Структура страницы

Vita LiveArea сохраняет компактную композицию с сеткой. Кастомный дизайн должен учитывать:
- spacing сетки иконок
- выравнивание страниц и границы страниц
- геометрию папок
- layout названий приложений
- поведение focus state

Система не должна принципиально менять layout shell, если не валидирован конкретный shell hook.

### 2. Ритм панелей

Использовать последовательный ритм для:
- app tiles
- групп папок
- page headers
- page overlays
- action focus states

Оставлять поля достаточно широкими для читаемости, но плотными, чтобы не терять Vita-эстетику.

### 3. Иерархия пространства

Интерфейс должен иметь ясную иерархию:
- background = окружение
- cards and panels = мебель
- selected app = визуальный фокус
- accent glow = метка активного элемента или selected state

Это особенно важно на Vita, где пространство экрана ограничено, а плотность информации высока.

## Язык иконок

### 1. Shell иконок

Иконки должны оставаться компактными, узнаваемыми и легко сканируемыми. Кастомный рендер должен избегать серьёзных изменений aspect ratio иконок.

Рекомендуемая обработка:
- мягкое скругление углов
- тёмная base plate за иконкой
- чистый accent glow вокруг focus/selection
- низкоинтенсивная border или outline на активном состоянии

### 2. Focus state

Выбранная или сфокусированная app tile должна быть визуально очевидной, но не подавлять остальную страницу.

Обработка selected tile:
- более яркое ambient glow
- cyan/blue border или rim
- elevated surface или panel lift
- тонкая тень или highlight edge

### 3. Появление папок

Папки должны чувствоваться отличными, но согласованными:
- чуть более насыщенные focus states
- нейтральный base с accent border
- чёткое разделение от обычных app tiles
- минимальная визуальная разница, чтобы пользователь всё ещё понимал структуру

## Типография

### 1. Поведение type

UI должен использовать читаемый, геометрический sans-serif с чистым современным профилем. Он должен ощущаться премиальным и tech-forward, но не playful.

Рекомендуемые принципы:
- высокая читаемость на тёмных фонах
- минимальный letter spacing для названий
- больший вес для активного selection
- меньшее акцентирование для metadata или secondary info

### 2. Иерархия labels

- app titles: primary text
- folder labels: medium emphasis
- secondary metadata: low emphasis, short and minimal
- active selection: brighter weight and stronger contrast

### 3. Accessibility

При использовании cyan и white-on-dark комбинаций необходимо:
- достаточный контраст
- отсутствие нечитаемого текста при слабом освещении
- отсутствие избыточного glow, ухудшающего читаемость

## Motion и interaction design

### 1. Характеристики motion

Держать motion мягким и целенаправленным:
- короткий fade-in для selection / focus
- плавные переходы страниц
- минимальные bounce или overshoot
- отсутствие резких flashing или neon pulses

### 2. Ожидания от взаимодействия

Selection должен ощущаться мгновенным и контролируемым:
- короткий glow ramp на focus
- тонкий panel lift или увеличение тени
- плавное движение при навигации между страницами

### 3. Ограничения производительности

На Vita motion должен оставаться лёгким. Приоритет:
- low-cost transitions
- минимальные particle effects
- ограниченное alpha blending
- сокращённые эффекты при высокой загрузке системы

## PS5-inspired flavor, адаптированный под Vita

Проект должен брать следующие cues PS5, не нарушая ограничения Vita:

- dark base + bright accent framing
- layered translucent panels
- UI depth via subtle gradients and soft lighting
- high-legibility selected states
- premium industrial look with minimal ornament
- controlled glow as a focus and highlight signal

Избегать:
- чрезмерно ярких full-color backgrounds
- избыточного neon noise
- тяжёлых motion effects или animated background clutter
- сложной glass layering, ухудшающей читабельность или производительность
- неплановых изменений geometry и layout иконок Vita

## Поведение fallback

Когда тема не может быть валидирована или custom asset отсутствует:
- откатиться к stock Vita LiveArea layout
- отключить custom glow или accent overlays
- вернуть default state иконок и page composition
- оставить систему в стабильном fallback mode

Fallback обязателен и должен рассматриваться как first-class design requirement.

## Пример таблицы состояний стиля

### Default state
- background: dark charcoal
- panels: translucent slate
- accent: subtle blue cyan
- selection: brighter cyan rim
- text: near-white, high contrast

### Focused state
- border glow: cyan or soft blue
- panel slightly elevated
- selected icon brighter and more saturated
- text weight increases slightly

### Folder state
- muted panel background
- accent on folder header or selected edge
- folder icon glow with smaller intensity than active app tiles

### Disabled or fallback state
- stock Vita rendering
- no custom accent or overlays
- no custom UI composition

## Руководство по реализации

При реализации этого стиля в проекте:

- держать rule set модульным
- разделять color spec и shell patch logic
- держать кастомный rendering layer optional
- делать theme profile-selectable по firmware
- поддерживать asset и theme fallback paths

## Критерии принятия дизайна

PS5-inspired theme должен быть принят только если:
- Vita shell остаётся читаемой и стабильной
- selected state чётко виден
- app icons остаются узнаваемыми и легко сканируемыми
- интерфейс ощущается премиальным и целостным без чрезмерного визуального шума
- fallback mode остаётся надёжным и безопасным

## Итог

PS5-inspired стиль должен чувствоваться как Vita-native reinterpretation of PS5 design language: тёмный, чистый, премиальный, выразительный и понятный. Основное внимание не на том, чтобы сделать Vita похожей на PS5 буквально, а на том, чтобы сохранить ограничения Vita и при этом заимствовать ключевые cues PS5.
