# Модель профиля прошивки

## Цель

Создать простую, зависящую от прошивки модель выбора UI-поведения без предположения, что все сборки Vita ведут себя одинаково.

## Структура модели профиля

Каждый профиль должен включать:
- версию прошивки
- класс железа (retail, PSTV, testkit, devkit)
- module NID
- ожидаемый размер text segment
- состояние валидации
- статус совместимости patch
- включён/выключен fallback

## Пример модели

```c
typedef struct FirmwareProfile {
    const char *name;
    uint32_t firmware_version;
    uint32_t module_nid;
    uint32_t expected_text_size;
    int supports_theme_engine;
    int supports_custom_assets;
    int requires_fallback;
} FirmwareProfile;
```

## Рекомендуемый порядок профилей

Использовать такой порядок при тестировании:
1. retail 3.60
2. retail 3.65
3. retail 3.73
4. PSTV 3.74, если доступно
5. devkit/testkit профили позже

## Правила

- один неподдерживаемый профиль не должен блокировать все остальные
- одного известного рабочего профиля достаточно как baseline milestone
- неподдерживаемые профили используют только stock theme rendering
- держать модель явной и легко расширяемой
