// Sale of supported cars.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <fstream>
#include <string>
#include <iomanip>
#include "lib.h"
// #include "students.h"// подключаем свою библиотеку работы со связным списком
                        // список должен хранить данные о вашей предметной области
                        // и реализовывать функции, согласно вашему заданию
struct Auto
{
    string id;           // номер в базе 
    string marka;        // марка
    string model;        // модель (Camry 3.5)
    int god;             // год выпуска
    string kuzov;        // седан, джип и т.д.
    string nomer;        // гос. номер или VIN
    int cena;            // цена в рублях
};

using namespace std;
// функция добавления данных

// Массив на 100 машин
Auto baza[100];
int countCars = 0;  // сколько машин сейчас в базе

// Имя файла, куда сохроняеться
string fileName = "autos.txt";

bool LOGIN_IN() {
    string login;
    string password;

    cout << "ВХОД В СИСТЕМУ " << endl;

    // Ввод логина
    cout << "Введите логин: ";
    getline(cin, login);

    // Ввод пароля
    cout << "Введите пароль: ";
    getline(cin, password);

    if (login == "Admin" && password == "0000") {
        cout << "\nУспешный вход! Добро пожаловать, " << login << "." << endl;
        return true;
    }
    else {
        cout << "\nОшибка: Неверный логин или пароль." << endl;
        return false;
    }
}

void AddData()
{
    system("cls");  // Очистка экрана
    cout << "Добавить автомабиль :\n";
    // здесь реализуете свой алгоритм

    cout << "Введите ID: ";
    getline(cin, baza[countCars].id);

    cout << "Введите Марку: ";
    getline(cin, baza[countCars].marka);

    cout << "Введите Модель: ";
    getline(cin, baza[countCars].model);

    cout << "Введите Год: ";
    cin >> baza[countCars].god;

    cin.ignore();

    cout << "Введите Кузов: ";
    getline(cin, baza[countCars].kuzov);

    cout << "Введите Номер: ";
    getline(cin, baza[countCars].nomer);

    cout << "Введите Цену: ";
    cin >> baza[countCars].cena;

    cin.ignore();

    countCars++;

    cout << "\nДобавлено! Нажмите клавишу...";
    _getch();
}

void PrintData()
{
    system("cls");
    cout << "Список автомобилей:\n\n";

    if (countCars == 0) {
        cout << "База пуста. Добавьте автомобили!\n";
    }
    else {
        for (int i = 0; i < countCars; i++) {
            cout << "--- Автомобиль №" << (i + 1) << " ---\n";
            cout << "ID:     " << baza[i].id << "\n";
            cout << "Марка:  " << baza[i].marka << "\n";
            cout << "Модель: " << baza[i].model << "\n";
            cout << "Год:    " << baza[i].god << "\n";
            cout << "Кузов:  " << baza[i].kuzov << "\n";
            cout << "Номер:  " << baza[i].nomer << "\n";
            cout << "Цена:   " << baza[i].cena << " руб.\n";
            cout << "--------------------------\n\n";
        }
        cout << "Всего автомобилей: " << countCars << "\n";
    }

    cout << "\nНажмите любую клавишу...";
    _getch();
}

void EditData()
{
    system("cls");
    cout << "Редактирование данных:\n\n";

    // Проверка
    if (countCars == 0) {
        cout << "База пуста! Нечего редактировать.\n";
        cout << "Нажмите любую клавишу...";
        _getch();
        return; // Выходит из функции 
    }

    // Просим ввести ID автомобиля, который хотим изменить
    cout << "Введите ID автомобиля для редактирования: ";
    string searchId;                        // Переменная для поиска
    std::getline(std::cin, searchId);       // Читаем строку (std:: обязательно!)

    // 8. Ищем автомобиль с таким ID в массиве
    int index = -1;                         // Переменная для номера найденной машины (-1 = не найдено)

    for (int i = 0; i < countCars; i++) {   // Перебираем все заполненные ячейки
        if (baza[i].id == searchId) {       // Если нашли совпадение по ID
            index = i;                      // Запоминаем номер ячейки
            break;                          // Выходим из цикла (дальше искать не надо)
        }
    }

    // Проверяем: нашли или нет?
    if (index == -1) {                      // Если index не изменился — не нашли
        cout << "\nАвтомобиль с ID '" << searchId << "' не найден!\n";
        cout << "Нажмите любую клавишу...";
        _getch();
        return;                             // Выходим, ничего не меняли
    }

    // Если нашли — показываем старые данные
    cout << "\nНайдено! Текущие данные:\n";
    cout << "Марка: " << baza[index].marka << "\n";
    cout << "Модель: " << baza[index].model << "\n";
    cout << "Год: " << baza[index].god << "\n";
    cout << "Кузов: " << baza[index].kuzov << "\n";
    cout << "Номер: " << baza[index].nomer << "\n";
    cout << "Цена: " << baza[index].cena << " руб.\n";

    // Теперь вводим новые значения
    cout << "\nВведите новые данные (оставьте пустым, чтобы не менять):\n";

    cout << "Новая марка [" << baza[index].marka << "]: ";
    string temp;                            // Временная переменная для ввода
    std::getline(std::cin, temp);           // Читаем ввод
    if (!temp.empty()) {                    // Если пользователь что-то ввёл
        baza[index].marka = temp;           // Заменяем старое значение на новое
    }

    cout << "Новая модель [" << baza[index].model << "]: ";
    std::getline(std::cin, temp);
    if (!temp.empty()) baza[index].model = temp;

    cout << "Новый год [" << baza[index].god << "]: ";
    std::getline(std::cin, temp);
    if (!temp.empty()) {
        baza[index].god = stoi(temp);       // stoi() — строку в число (string to int)
    }

    cout << "Новый кузов [" << baza[index].kuzov << "]: ";
    std::getline(std::cin, temp);
    if (!temp.empty()) baza[index].kuzov = temp;

    cout << "Новый номер [" << baza[index].nomer << "]: ";
    std::getline(std::cin, temp);
    if (!temp.empty()) baza[index].nomer = temp;

    cout << "Новая цена [" << baza[index].cena << "]: ";
    std::getline(std::cin, temp);
    if (!temp.empty()) {
        baza[index].cena = stoi(temp);      // Преобразуем строку в число
    }

    // Сообщение об успехе
    cout << "\n Данные обновлены!\n";
    cout << "Нажмите любую клавишу...";
    _getch();
}

void DeleteData()
{
    system("cls");
    cout << "Введите ID удаляемого автомобиля:\n";

    if (countCars == 0) {
        cout << "База пуста! Нечего удалять.\n";
        cout << "Нажмите любую клавишу...";
        _getch();
        return;
    }

    string delId;
    cout << "ID: ";
    getline(cin, delId);

    int index = -1;
    for (int i = 0; i < countCars; i++) {
        if (baza[i].id == delId) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << "\nАвтомобиль с ID '" << delId << "' не найден!\n";
        cout << "Нажмите любую клавишу...";
        _getch();
        return;
    }

    // Сдвигаем элементы влево
    for (int i = index; i < countCars - 1; i++) {
        baza[i] = baza[i + 1];
    }
    countCars--;

    cout << "\nАвтомобиль удалён!\n";
    cout << "Нажмите любую клавишу...";
    _getch();
}

void PrintFilteredData()
{
    system("cls");
    cout << "Автомобили дороже среднего:\n\n";

    if (countCars == 0) {
        cout << "База пуста!\n";
        cout << "Нажмите любую клавишу...";
        _getch();
        return;
    }

    // Считаем среднюю цену
    double sum = 0;
    for (int i = 0; i < countCars; i++) {
        sum += baza[i].cena;
    }
    double avg = sum / countCars;

    cout << "Средняя цена: " << avg << " руб.\n";
    cout << "----------------------------------------\n";

    bool found = false;
    for (int i = 0; i < countCars; i++) {
        if (baza[i].cena > avg) {
            cout << "ID: " << baza[i].id << "\n"
                << "Марка: " << baza[i].marka << "\n"
                << "Модель: " << baza[i].model << "\n"
                << "Год: " << baza[i].god << "\n"
                << "Кузов: " << baza[i].kuzov << "\n"
                << "Номер: " << baza[i].nomer << "\n"
                << "Цена: " << baza[i].cena << " руб.\n"
                << "----------------------------------------\n";
            found = true;
        }
    }

    if (!found) {
        cout << "Нет автомобилей дороже среднего.\n";
    }

    cout << "\nНажмите любую клавишу...";
    _getch();
}

bool SaveData()
{
    ofstream outFile(fileName);
    if (!outFile.is_open()) {
        cout << "Ошибка: не удалось открыть файл для записи!\n";
        return false;
    }

    outFile << countCars << endl;

    for (int i = 0; i < countCars; i++) {
        outFile << baza[i].id << endl;
        outFile << baza[i].marka << endl;
        outFile << baza[i].model << endl;
        outFile << baza[i].god << endl;
        outFile << baza[i].kuzov << endl;
        outFile << baza[i].nomer << endl;
        outFile << baza[i].cena << endl;
    }

    outFile.close();
    cout << "Данные сохранены в файл " << fileName << endl;
    return true;
}

// Функция центрирования текста
std::string CenterText(const std::string& text, size_t width, char filler = ' ')
{

    const int LX = 80;
    const int LY = 60;





    //задаем ширину и высоту только после этого у нас будет работать!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!



    // Вычисляем отступы
    size_t totalIndent = width - text.length();
    size_t leftIndent = totalIndent / 2;           // Левый отступ
    size_t rightIndent = totalIndent - leftIndent; // Правый отступ 

    // Формируем результирующую строку
    return std::string(leftIndent, filler) + text + std::string(rightIndent, filler);
}

int alignment()
{
    std::string title = "МЕНЮ";

    std::string option = "Выбрать автомобиль";

    const size_t consoleWidth = 0;
    std::cout << CenterText(title, consoleWidth, '=') << std::endl;
    std::cout << CenterText("2. Выход", consoleWidth) << std::endl;
    std::cout << std::string(consoleWidth, '=') << std::endl;
    return 0;

}


void PrintHelp()
{
   

    // Выводите текст справки на экран
    // Рекомендую создать текстовый файл справки
    // а здесь прочитать текст из него и вывести в консоль
    system("cls");
    cout << "========================= СПРАВКА =========================\n";
    cout << "1. Добавить автомобиль – введите данные о новом автомобиле.\n";
    cout << "2. Вывод списка – показывает все машины в табличном виде.\n";
    cout << "3. Поиск по номеру – находит автомобиль по госномеру/VIN.\n";
    cout << "4. Поиск по марке – показывает все автомобили указанной марки.\n";
    cout << "5. Поиск по модели – показывает все автомобили указанной модели.\n";
    cout << "6. Поиск по кузову – показывает все автомобили с указанным типом кузова.\n";
    cout << "7. Удалить по ID – удаляет запись по уникальному идентификатору.\n";
    cout << "8. Выйти – завершает работу и сохраняет данные.\n";
    cout << "==========================================================\n";
    cout << "\nНажмите любую клавишу...";
    cout << "Справка:\n"; // например выводим только отличников
    // здесь реализуете свой алгоритм справки
    _getch();
}

bool LoadData()
{
    ifstream inFile(fileName);
    if (!inFile.is_open()) {
        cout << "Файл базы данных не найден. Будет создана новая база.\n";
        return false;
    }

    int loadedCount;
    inFile >> loadedCount;
    if (loadedCount > 100) {
        cout << "Ошибка: в файле больше записей, чем может вместить программа.\n";
        inFile.close();
        return false;
    }

    countCars = 0;
    for (int i = 0; i < loadedCount; i++) {
        string temp;
        getline(inFile, temp); // скипаем перевод строки после числа

        if (!getline(inFile, baza[i].id)) break;
        if (!getline(inFile, baza[i].marka)) break;
        if (!getline(inFile, baza[i].model)) break;
        if (!(inFile >> baza[i].god)) break;
        inFile.ignore();
        if (!getline(inFile, baza[i].kuzov)) break;
        if (!getline(inFile, baza[i].nomer)) break;
        if (!(inFile >> baza[i].cena)) break;
        inFile.ignore();

        countCars++;
    }

    inFile.close();
    cout << "Загружено " << countCars << " записей из файла " << fileName << endl;
    return true;
}
// вывод в консоль меню программы
char MainMenu()
{
    while (true) // бесконечный цикл
    {
        system("cls"); // чистим экран
        cout << " УЧЕТ ПОДДЕРЖАННЫХ АВТОМОБИЛЕЙ \n\n"; // выводим название программы, оно у каждого буде свое
        // выводим строки меню, цивра в скобках - клавиша, которую нужно нажать для выбора соответствующего действия
        cout << "[1] Добавить автомобиль" << endl;
        cout << "[2] Вывод списка автомобилей" << endl;
        cout << "[3] Поиск автомобиля по номеру" << endl;
        cout << "[4] Поиск автомобиля по марке" << endl;
        cout << "[5] Поиск автомобиля по модели" << endl;
        cout << "[6] поиск автомобиля по типу кузова" << endl;
        cout << "[7] Удалить автомобиль по номеру" << endl;
        cout << "[8] Выйти из программы\n" << endl;
        cout << "Выш выбор > ";
        char choice = _getch(); // считываем нажатую пользователем клавишу
        if (choice < '1' || choice > '8') // проверяем, соответствует ли клавиша пунктам меню
        {       // если нет, то требуем повторить ввод
            cout << "Такого варианта не существует! Нажмите любую клавишу...";
            _getch();
        }
        else
        {       // если соответствует, то возвращаем в вызываемую программу символ
                // соответствующий нажатой клавише
            return choice;
        }

    }

}
// обработка действий пользователя
void HandleEvents()
{
    char choice = 0;
    while (choice != '8') // цикл пока пользователь не нажал ВЫХОД
    {
        choice = MainMenu(); // определяем, какой пункт меню выбрал пользователь
        // переменная choice будет хранить символ, соответствующий
        // выбранному пункту меню
        switch (choice) // проверяем какую клавишу нажал пользователь
        {
        case '1': // если 1 то вызываем функцию добавления данных
            AddData();
            break;
        case '2': // если 2 то вызываем функцию вывода данных
            PrintData();
            break;
        case '3': // если 3 то вызываем функцию редактирования данных
            EditData();
            break;
        case '4': // если 4 то вызываем функцию удаления данных
            DeleteData();
            break;
        case '5': // если 5 то вызываем функцию вывода данных по критерию отбора
            PrintFilteredData();
            break;
        case '6': // если 6 то вызываем функцию сохранения данных
            SaveData();
            break;
        case '7': // если 7 то вызываем функцию вывода справочной информации по пользованию программой
            PrintHelp();
            break;
        case '8': // // если 1 то выходим
            return;

        }

    }

}
int main()
{
    SetConsoleOutputCP(1251); // Установка кодировки для Windows

    // Сначала проверяем вход
    if (!LOGIN_IN()) {
        cout << "\nПрограмма завершена из-за неудачной попытки входа." << endl;
        _getch();
        return 0; // Выход из программs   если пароль неверный
    }
    setlocale(LC_ALL, "");
    AddData();
    PrintData();
    if (!LoadData()) // если чтение базы данных неудачно, то продолжение выполнения программы невозможно
    {       // выводим сообщение об ошибке и выходим с кодом 1
        cout << "Ошибка чтения базы данных\n";
        return 1;
        // как вариант, если базу прочитать невозможно, вы можете создать новую базу данных и продолжить работу
        // с программой
    }
    HandleEvents(); // вызываем функцию обработки нажатий клавиш пользователем
    SaveData(); // при выходе сохраняем данные в базе данных
}