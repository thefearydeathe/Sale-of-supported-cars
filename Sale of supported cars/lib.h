#pragma once
#include <string>
#include <Windows.h>
struct ListItem
{
    int id;           // идентификатор 
    char name[30];    // название
    float price;      // цена за единицу
    float count;      // количество
    ListItem* next;   // указатель на следующий элемент
};
using namespace std;

namespace crt 
{
    const int COLOR_BLACK = 0;  // Чёрный (обычно фон)
    const int COLOR_BLUE = 1;  // Синий
    const int COLOR_GREEN = 2;  // Зелёный
    const int COLOR_CYAN = 3;  // Голубой (циан)
    const int COLOR_RED = 4;  // Красный
    const int COLOR_MAGENTA = 5;  // Пурпурный (маджента)
    const int COLOR_BROWN = 6;  // Коричневый/жёлто-коричневый
    const int COLOR_GRAY = 7;  // Светло-серый (стандартный цвет текста)
    const int COLOR_DARK_GRAY = 8;  // Тёмно-серый (яркий чёрный)
    const int COLOR_LIGHT_BLUE = 9;  // Ярко-синий
    const int COLOR_LIGHT_GREEN = 10; // Ярко-зелёный
    const int COLOR_LIGHT_CYAN = 11; // Ярко-голубой
    const int COLOR_LIGHT_RED = 12; // Ярко-красный (розовый)
    const int COLOR_LIGHT_MAGENTA = 13; // Ярко-пурпурный
    const int COLOR_YELLOW = 14; // Жёлтый
    const int COLOR_WHITE = 15; // Белый
}
inline void SetTextColor(int color, int background = crt::COLOR_BLACK) 
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);  // Получаем дескриптор вывода
    SetConsoleTextAttribute(hConsole, color | (background << 4)); // Применяем атрибуты
}