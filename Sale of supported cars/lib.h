#pragma once
#include <string>
#include <Windows.h>


using namespace std;

namespace crt 
{
    const int COLOR_BLACK = 0;  // ×¸ðíûé (îáû÷íî ôîí)
    const int COLOR_BLUE = 1;  // Ñèíèé
    const int COLOR_GREEN = 2;  // Çåë¸íûé
    const int COLOR_CYAN = 3;  // Ãîëóáîé (öèàí)
    const int COLOR_RED = 4;  // Êðàñíûé
    const int COLOR_MAGENTA = 5;  // Ïóðïóðíûé (ìàäæåíòà)
    const int COLOR_BROWN = 6;  // Êîðè÷íåâûé/æ¸ëòî-êîðè÷íåâûé
    const int COLOR_GRAY = 7;  // Ñâåòëî-ñåðûé (ñòàíäàðòíûé öâåò òåêñòà)
    const int COLOR_DARK_GRAY = 8;  // Ò¸ìíî-ñåðûé (ÿðêèé ÷¸ðíûé)
    const int COLOR_LIGHT_BLUE = 9;  // ßðêî-ñèíèé
    const int COLOR_LIGHT_GREEN = 10; // ßðêî-çåë¸íûé
    const int COLOR_LIGHT_CYAN = 11; // ßðêî-ãîëóáîé
    const int COLOR_LIGHT_RED = 12; // ßðêî-êðàñíûé (ðîçîâûé)
    const int COLOR_LIGHT_MAGENTA = 13; // ßðêî-ïóðïóðíûé
    const int COLOR_YELLOW = 14; // Æ¸ëòûé
    const int COLOR_WHITE = 15; // Áåëûé
}
inline void SetTextColor(int color, int background = crt::COLOR_BLACK) 
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);  // Ïîëó÷àåì äåñêðèïòîð âûâîäà
    SetConsoleTextAttribute(hConsole, color | (background << 4)); // Ïðèìåíÿåì àòðèáóòû
}