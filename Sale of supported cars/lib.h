#pragma once
#include <string>
#include <Windows.h>


using namespace std;

namespace crt
{
    const int COLOR_BLACK = 0;        // чёрный
    const int COLOR_BLUE = 1;         // синий
    const int COLOR_GREEN = 2;        // зелёный
    const int COLOR_CYAN = 3;         // голубой
    const int COLOR_RED = 4;          // красный
    const int COLOR_MAGENTA = 5;      // фиолетовый
    const int COLOR_BROWN = 6;        // коричневый
    const int COLOR_GRAY = 7;         // серый
    const int COLOR_DARK_GRAY = 8;    // тёмно-серый
    const int COLOR_LIGHT_BLUE = 9;   // светло-синий
    const int COLOR_LIGHT_GREEN = 10; // светло-зелёный
    const int COLOR_LIGHT_CYAN = 11;  // светло-голубой
    const int COLOR_LIGHT_RED = 12;   // светло-красный
    const int COLOR_LIGHT_MAGENTA = 13; // светло-фиолетовый
    const int COLOR_YELLOW = 14;      // жёлтый
    const int COLOR_WHITE = 15;       // белый
}

inline void SetTextColor(int color, int background = crt::COLOR_BLACK) 
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);  // 
    SetConsoleTextAttribute(hConsole, color | (background << 4)); // 
}