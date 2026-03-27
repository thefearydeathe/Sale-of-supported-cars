#pragma once
#include <string>
struct ListItem
{
    int id;           // идентификатор 
    char name[30];    // название
    float price;      // цена за единицу
    float count;      // количество
    ListItem* next;   // указатель на следующий элемент
};
