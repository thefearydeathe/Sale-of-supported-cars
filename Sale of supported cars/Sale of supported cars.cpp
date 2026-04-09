// Sale of supported cars.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <fstream>
#include <string>
#include "lib.h"
// #include "students.h"// подключаем свою библиотеку работы со связным списком
                        // список должен хранить данные о вашей предметной области
                        // и реализовывать функции, согласно вашему заданию

using namespace std;

// Имя файла, куда сохроняеться
Auto* head = nullptr;
string fileName = "autos.txt";
bool LOGIN_IN()
{
    string login, password;
    string fileLogin, filePass;

    ifstream passwordFile("password.txt");
    if (!passwordFile)
    {
        SetTextColor(4);
        cout << "Ошибка: нет файла password.txt!" << endl;
        SetTextColor(15);
        _getch();
        return false;
    }

    getline(passwordFile, fileLogin);
    getline(passwordFile, filePass);
    passwordFile.close();
    cout << "========================= ВХОД В СИСТЕМУ =========================" << endl;

    while (true)
    {
        cout << "\nВведите логин: ";
        getline(cin, login);

        cout << "Введите пароль: ";
        getline(cin, password);

        // Проверяем, что пользователь что-то ввёл
        if (login.empty() || password.empty())
        {
            SetTextColor(4);
            cout << "\nЛогин и пароль не могут быть пустыми!" << endl;
            SetTextColor(15);
            continue; // просим ввести заново
        }

        if (login == fileLogin && password == filePass)
        {
            return true;
        }
        else
        {
            SetTextColor(4);
            cout << "\nНеверный логин или пароль!" << endl;
            SetTextColor(15);
            cout << "Попробуйте ещё раз..." << endl;
        }
    }
}

void PrintData() {
    system("cls");
    SetTextColor(15);
    cout << "=== СПИСОК АВТОМОБИЛЕЙ ===\n\n";

    if (head == nullptr) {
        cout << "База данных пуста.\n";
    }
    else {
        Auto* temp = head;
        int count = 0;
        while (temp != nullptr) {
            count++;
            cout << "--- Автомобиль №" << count << " ---\n";
            cout << "VIN:" << temp->VIN << "\n";
            cout << "Марка:" << temp->marka << "\n";
            cout << "Модель:" << temp->model << "\n";
            cout << "Год выпуска:" << temp->god << "\n";
            cout << "Тип кузова:" << temp->kuzov << "\n";
            cout << "Цвет кузова:" << temp->color << "\n";
            cout << "Тип привода:" << temp->driveType << "\n";
            cout << "Цена:" << temp->cena << " руб.\n";
            cout << "--------------------------\n\n";
            temp = temp->next;
        }
        cout << "Всего автомобилей: " << count << "\n";
    }

    cout << "\nНажмите любую клавишу...";
    _getch();
}
void SaveData()
{
    ofstream file("autos.txt");

    // Считаем количество
    int count = 0;
    Auto* t = head;
    while (t != nullptr) {
        count++;
        t = t->next;
    }
    file << count << endl;

    // Пишем все поля
    t = head;
    while (t != nullptr) {
        file << t->VIN << endl;
        file << t->marka << endl;
        file << t->model << endl;
        file << t->god << endl;
        file << t->kuzov << endl;
        file << t->color << endl;
        file << t->driveType << endl;
        file << t->cena << endl;  // цена как текст
        t = t->next;
    }
    file.close();
}

void AddData()
{
    system("cls");
    SetTextColor(15);
    cout << "=== ДОБАВЛЕНИЕ АВТОМОБИЛЯ ===\n\n";

    Auto* newAuto = new Auto;
    newAuto->next = nullptr;
    cout << "Введите уникальный номер VIN (17 символов): ";
    getline(cin, newAuto->VIN);
    cout << "Введите марку (до 15 символов): ";
    getline(cin, newAuto->marka);
    cout << "Введите модель (до 25 символов): ";
    getline(cin, newAuto->model);
    cout << "Введите год выпуска: ";
    getline(cin, newAuto->god);  // <-- ТЕПЕРЬ СТРОКА
    cout << "Введите тип кузова (до 15 символов): ";
    getline(cin, newAuto->kuzov);
    cout << "Введите цвет кузова (до 12 символов): ";
    getline(cin, newAuto->color);
    cout << "Введите тип привода (до 10 символов): ";
    getline(cin, newAuto->driveType);
    cout << "Введите цену в рублях: ";
    getline(cin, newAuto->cena);  // <-- ТЕПЕРЬ СТРОКА
    // Добавление в конец связного списка
    if (head == nullptr) {
        head = newAuto;
    }
    else {
        Auto* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newAuto;
    }
    SetTextColor(2);
    cout << "\nАвтомобиль успешно добавлен!\n";
    SetTextColor(15);
    SaveData();  
    cout << "Нажмите любую клавишу...";
    _getch();
}
// Редактирование данных автомобиля по VIN
void EditData() {
    system("cls");
    SetTextColor(15);
    cout << "=== РЕДАКТИРОВАНИЕ АВТОМОБИЛЯ ===\n\n";

    if (head == nullptr) {
        cout << "База данных пуста.\nНажмите любую клавишу...";
        _getch();
        return;
    }

    string searchVin;
    cout << "Введите VIN автомобиля для редактирования: ";
    getline(cin, searchVin);

    // Ищем автомобиль с таким VIN в списке
    Auto* temp = head;
    while (temp != nullptr) {
        if (temp->VIN == searchVin) {
            break;  // Нашли
        }
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "\nАвтомобиль с VIN \"" << searchVin << "\" не найден.\n";
        cout << "\nНажмите любую клавишу...";
        _getch();
        return;
    }

    // Показываем текущие данные
    cout << "\n--- Текущие данные ---\n";
    cout << "Марка:" << temp->marka << endl;
    cout << "Модель:" << temp->model << endl;
    cout << "Год выпуска:" << temp->god << endl;
    cout << "Тип кузова:" << temp->kuzov << endl;
    cout << "Цвет кузова:" << temp->color << endl;
    cout << "Тип привода:" << temp->driveType << endl;
    cout << "Цена:" << temp->cena << " руб." << endl;

    // Ввод новых значений (Enter оставляет старое)
    cout << "\n--- Введите новые значения (Enter - оставить без изменений) ---\n";

    string input;

    cout << "Марка [" << temp->marka << "]: ";
    getline(cin, input);
    if (!input.empty()) temp->marka = input;
    cout << "Модель [" << temp->model << "]: ";
    getline(cin, input);
    if (!input.empty()) temp->model = input;
    cout << "Год выпуска [" << temp->god << "]: ";
    getline(cin, input);
    if (!input.empty()) temp->god = input;  // <-- Просто строка
    cout << "Тип кузова [" << temp->kuzov << "]: ";
    getline(cin, input);
    if (!input.empty()) temp->kuzov = input;
    cout << "Цвет кузова [" << temp->color << "]: ";
    getline(cin, input);
    if (!input.empty()) temp->color = input;
    cout << "Тип привода [" << temp->driveType << "]: ";
    getline(cin, input);
    if (!input.empty()) temp->driveType = input;
    cout << "Цена [" << temp->cena << "]: ";
    getline(cin, input);
    if (!input.empty()) temp->cena = input;  // <-- Просто строка
    SetTextColor(2);
    cout << "\nДанные успешно обновлены!\n";
    SetTextColor(15);
    SaveData();  
    cout << "\nНажмите любую клавишу...";
    _getch();
}


// Поиск по номеру (VIN)
void SearchByVin() {
    system("cls");
    SetTextColor(15);
    cout << "=== ПОИСК ПО НОМЕРУ (VIN) ===\n\n";

    if (head == nullptr) {
        cout << "База данных пуста.\nНажмите любую клавишу...";
        _getch();
        return;
    }

    string searchVin;
    cout << "Введите VIN для поиска: ";
    getline(cin, searchVin);

    Auto* temp = head;
    bool found = false;
    while (temp != nullptr) {
        if (temp->VIN == searchVin) {
            cout << "\n--- Найден автомобиль ---\n";
            cout << "VIN:" << temp->VIN << endl;
            cout << "Марка:" << temp->marka << endl;
            cout << "Модель:" << temp->model << endl;
            cout << "Год выпуска:" << temp->god << endl;
            cout << "Тип кузова:" << temp->kuzov << endl;
            cout << "Цвет кузова:" << temp->color << endl;
            cout << "Тип привода:" << temp->driveType << endl;
            cout << "Цена:" << temp->cena << " руб." << endl;
            found = true;
            break;
        }
        temp = temp->next;
    }

    if (!found) {
        cout << "\nАвтомобиль с VIN \"" << searchVin << "\" не найден.\n";
    }

    cout << "\nНажмите любую клавишу...";
    _getch();
}

// Поиск по марке (частичное совпадение, без учёта регистра)
void SearchByBrand() {
    system("cls");
    SetTextColor(15);
    cout << "=== ПОИСК ПО МАРКЕ ===\n\n";

    if (head == nullptr) {
        cout << "База данных пуста.\nНажмите любую клавишу...";
        _getch();
        return;
    }

    string searchBrand;
    cout << "Введите марку (или её часть): ";
    getline(cin, searchBrand);

    string lowerSearch = searchBrand;
    for (char& c : lowerSearch) c = tolower(c);

    Auto* temp = head;
    int foundCount = 0;
    while (temp != nullptr) {
        string lowerBrand = temp->marka;
        for (char& c : lowerBrand) c = tolower(c);

        if (lowerBrand.find(lowerSearch) != string::npos) {
            foundCount++;
            cout << "\n--- Автомобиль №" << foundCount << " ---\n";
            cout << "VIN:" << temp->VIN << endl;
            cout << "Марка:" << temp->marka << endl;
            cout << "Модель:" << temp->model << endl;
            cout << "Год выпуска:" << temp->god << endl;
            cout << "Тип кузова:" << temp->kuzov << endl;
            cout << "Цвет кузова:" << temp->color << endl;
            cout << "Тип привода:" << temp->driveType << endl;
            cout << "Цена:" << temp->cena << " руб." << endl;
        }
        temp = temp->next;
    }

    if (foundCount == 0)
        cout << "\nАвтомобилей марки \"" << searchBrand << "\" не найдено.\n";
    else
        cout << "\nВсего найдено: " << foundCount << "\n";

    cout << "\nНажмите любую клавишу...";
    _getch();
}

// Поиск по модели (частичное совпадение, без учёта регистра)
void SearchByModel()
{
    system("cls");
    SetTextColor(15);
    cout << "=== ПОИСК ПО МОДЕЛИ ===\n\n";

    if (head == nullptr) {
        cout << "База данных пуста.\nНажмите любую клавишу...";
        _getch();
        return;
    }

    string searchModel;
    cout << "Введите модель (или её часть): ";
    getline(cin, searchModel);

    // Если пользователь ничего не ввёл — отменяем поиск
    if (searchModel.empty()) {
        cout << "\nПоиск отменён (пустой запрос).\n";
        cout << "\nНажмите любую клавишу...";
        _getch();
        return;
    }

    string lowerSearch = searchModel;
    for (char& c : lowerSearch) c = tolower(c);

    Auto* temp = head;
    int foundCount = 0;
    while (temp != nullptr) {
        string lowerModel = temp->model;
        for (char& c : lowerModel) c = tolower(c);

        if (lowerModel.find(lowerSearch) != string::npos) {
            foundCount++;
            cout << "\n--- Автомобиль №" << foundCount << " ---\n";
            cout << "VIN:" << temp->VIN << endl;
            cout << "Марка:" << temp->marka << endl;
            cout << "Модель:" << temp->model << endl;
            cout << "Год выпуска:" << temp->god << endl;
            cout << "Тип кузова:" << temp->kuzov << endl;
            cout << "Цвет кузова:" << temp->color << endl;
            cout << "Тип привода:" << temp->driveType << endl;
            cout << "Цена:" << temp->cena << " руб." << endl;
        }
        temp = temp->next;
    }

    if (foundCount == 0)
        cout << "\nАвтомобилей модели \"" << searchModel << "\" не найдено.\n";
    else
        cout << "\nВсего найдено: " << foundCount << "\n";

    cout << "\nНажмите любую клавишу...";
    _getch();
}

// Поиск по году выпуска (точное совпадение)
void SearchByYear() {
    system("cls");
    SetTextColor(15);
    cout << "=== ПОИСК ПО ГОДУ ВЫПУСКА ===\n\n";
    if (head == nullptr) {
        cout << "База данных пуста.\nНажмите любую клавишу...";
        _getch();
        return;
    }
    string searchYear;  // <-- ТЕПЕРЬ СТРОКА
    cout << "Введите год выпуска: ";
    getline(cin, searchYear);  // <-- Читаем через getlin
    Auto* temp = head;
    int foundCount = 0;
    while (temp != nullptr) {
        if (temp->god == searchYear) {  // <-- Сравниваем строки
            foundCount++;
            cout << "\n--- Автомобиль №" << foundCount << " ---\n";
            cout << "VIN:" << temp->VIN << endl;
            cout << "Марка:" << temp->marka << endl;
            cout << "Модель:" << temp->model << endl;
            cout << "Год выпуска:" << temp->god << endl;
            cout << "Тип кузова:" << temp->kuzov << endl;
            cout << "Цвет кузова:" << temp->color << endl;
            cout << "Тип привода:" << temp->driveType << endl;
            cout << "Цена:" << temp->cena << " руб." << endl;
        }
        temp = temp->next;
    }
    if (foundCount == 0)
        cout << "\nАвтомобилей " << searchYear << " года выпуска не найдено.\n";
    else
        cout << "\nВсего найдено: " << foundCount << "\n";
    cout << "\nНажмите любую клавишу...";
    _getch();
}

// Поиск по типу кузова (точное совпадение)
void SearchByBodyType()
{
    system("cls");
    SetTextColor(15);
    cout << "=== ПОИСК ПО ТИПУ КУЗОВА ===\n\n";

    if (head == nullptr) {
        cout << "База данных пуста.\nНажмите любую клавишу...";
        _getch();
        return;
    }

    string searchType;
    cout << "Введите тип кузова: ";
    getline(cin, searchType);

    // Если пользователь ничего не ввёл — отменяем поиск
    if (searchType.empty()) {
        cout << "\nПоиск отменён.\n";// пустой запрос
        cout << "\nНажмите любую клавишу...";
        _getch();
        return;
    }

    Auto* temp = head;
    int foundCount = 0;
    while (temp != nullptr) {
        if (temp->kuzov == searchType) {
            foundCount++;
            cout << "\n--- Автомобиль №" << foundCount << " ---\n";
            cout << "VIN:" << temp->VIN << endl;
            cout << "Марка:" << temp->marka << endl;
            cout << "Модель:" << temp->model << endl;
            cout << "Год выпуска:" << temp->god << endl;
            cout << "Тип кузова:" << temp->kuzov << endl;
            cout << "Цвет кузова:" << temp->color << endl;
            cout << "Тип привода:" << temp->driveType << endl;
            cout << "Цена:" << temp->cena << " руб." << endl;
        }
        temp = temp->next;
    }

    if (foundCount == 0)
        cout << "\nАвтомобилей с типом кузова " << searchType << " не найдено.\n";
    else
        cout << "\nВсего найдено: " << foundCount << "\n";

    cout << "\nНажмите любую клавишу...";
    _getch();
}

void SearchByColor() {
    system("cls");
    SetTextColor(15);
    cout << "=== ПОИСК ПО ЦВЕТУ КУЗОВА ===\n\n";

    if (head == nullptr) {
        cout << "База данных пуста.\nНажмите любую клавишу...";
        _getch();
        return;
    }

    string searchColor;
    cout << "Введите цвет (или его часть): ";
    getline(cin, searchColor);

    string lowerSearch = searchColor;
    for (char& c : lowerSearch) c = tolower(c);

    Auto* temp = head;
    int foundCount = 0;
    while (temp != nullptr) {
        string lowerColor = temp->color;
        for (char& c : lowerColor) c = tolower(c);

        if (lowerColor.find(lowerSearch) != string::npos) {
            foundCount++;
            cout << "\n--- Автомобиль №" << foundCount << " ---\n";
            cout << "VIN:" << temp->VIN << endl;
            cout << "Марка:" << temp->marka << endl;
            cout << "Модель:" << temp->model << endl;
            cout << "Год выпуска:" << temp->god << endl;
            cout << "Тип кузова:" << temp->kuzov << endl;
            cout << "Цвет кузова:" << temp->color << endl;
            cout << "Тип привода:" << temp->driveType << endl;
            cout << "Цена:" << temp->cena << " руб." << endl;
        }
        temp = temp->next;
    }

    if (foundCount == 0)
        cout << "\nАвтомобилей с цветом \"" << searchColor << "\" не найдено.\n";
    else
        cout << "\nВсего найдено: " << foundCount << "\n";

    cout << "\nНажмите любую клавишу...";
    _getch();
}
// Поиск по типу привода (частичное совпадение, без учёта регистра)
void SearchByDriveType() {
    system("cls");
    SetTextColor(15);
    cout << "=== ПОИСК ПО ТИПУ ПРИВОДА ===\n\n";

    if (head == nullptr) {
        cout << "База данных пуста.\nНажмите любую клавишу...";
        _getch();
        return;
    }

    string searchDrive;
    cout << "Введите тип привода (или его часть): ";
    getline(cin, searchDrive);

    string lowerSearch = searchDrive;
    for (char& c : lowerSearch) c = tolower(c);

    Auto* temp = head;
    int foundCount = 0;
    while (temp != nullptr) {
        string lowerDrive = temp->driveType;
        for (char& c : lowerDrive) c = tolower(c);

        if (lowerDrive.find(lowerSearch) != string::npos) {
            foundCount++;
            cout << "\n--- Автомобиль №" << foundCount << " ---\n";
            cout << "VIN:" << temp->VIN << endl;
            cout << "Марка:" << temp->marka << endl;
            cout << "Модель:" << temp->model << endl;
            cout << "Год выпуска:" << temp->god << endl;
            cout << "Тип кузова:" << temp->kuzov << endl;
            cout << "Цвет кузова:" << temp->color << endl;
            cout << "Тип привода:" << temp->driveType << endl;
            cout << "Цена:" << temp->cena << " руб." << endl;
        }
        temp = temp->next;
    }

    if (foundCount == 0)
        cout << "\nАвтомобилей с типом привода \"" << searchDrive << "\" не найдено.\n";
    else
        cout << "\nВсего найдено: " << foundCount << "\n";

    cout << "\nНажмите любую клавишу...";
    _getch();
}

// Поиск по цене (точное совпадение)
void SearchByPrice() {
    system("cls");
    SetTextColor(15);
    cout << "=== ПОИСК ПО ЦЕНЕ ===\n\n";
    if (head == nullptr) {
        cout << "База данных пуста.\nНажмите любую клавишу...";
        _getch();
        return;
    }
    string searchPrice;  // <-- ТЕПЕРЬ СТРОКА
    cout << "Введите цену в рублях: ";
    getline(cin, searchPrice);  // <-- Читаем через getline
    Auto* temp = head;
    int foundCount = 0;
    while (temp != nullptr) {
        if (temp->cena == searchPrice) {  // <-- Сравниваем строки
            foundCount++;
            cout << "\n--- Автомобиль №" << foundCount << " ---\n";
            cout << "VIN:" << temp->VIN << endl;
            cout << "Марка:" << temp->marka << endl;
            cout << "Модель:" << temp->model << endl;
            cout << "Год выпуска:" << temp->god << endl;
            cout << "Тип кузова:" << temp->kuzov << endl;
            cout << "Цвет кузова:" << temp->color << endl;
            cout << "Тип привода:" << temp->driveType << endl;
            cout << "Цена:" << temp->cena << " руб." << endl;
        }
        temp = temp->next;
    }
    if (foundCount == 0)
        cout << "\nАвтомобилей с ценой " << searchPrice << " руб. не найдено.\n";
    else
        cout << "\nВсего найдено: " << foundCount << "\n";
    cout << "\nНажмите любую клавишу...";
    _getch();
}

// Функция удаления автомобиля по его уникальному номеру (VIN)
void DeleteByVin() {
    system("cls");
    SetTextColor(15);
    cout << "=== УДАЛЕНИЕ АВТОМОБИЛЯ ПО НОМЕРУ ===\n\n";

    // Проверяем, есть ли вообще машины в базе
    if (head == nullptr) {
        cout << "База данных пуста.\n";
        cout << "Нажмите любую клавишу...";
        _getch();
        return;
    }

    string delVin;
    cout << "Введите VIN удаляемого автомобиля: ";
    getline(cin, delVin);

    // Два указателя для перемещения по списку:
    // curr — текущий автомобиль, который мы проверяем
    // prev — предыдущий автомобиль
    Auto* curr = head;
    Auto* prev = nullptr;

    while (curr != nullptr) {
        if (curr->VIN == delVin) {
            if (prev == nullptr) {
                head = curr->next;
            }
            else {
                // Удаление из середины или конца
                prev->next = curr->next;
            }

            delete curr;

            SetTextColor(2);
            cout << "\nАвтомобиль успешно удалён.\n";
            SetTextColor(15);
            cout << "\nНажмите любую клавишу...";
            _getch();
            return;
        }

        prev = curr;
        curr = curr->next;
    }

    cout << "\nАвтомобиль с VIN \"" << delVin << "\" не найден.\n";
    cout << "\nНажмите любую клавишу...";
    _getch();
}


void PrintFilteredData()
{
    system("cls");
    cout << "Автомобили дороже среднего:\n\n";

    if (head == nullptr) {
        cout << "База пуста!\n";
        cout << "Нажмите любую клавишу...";
        _getch();
        return;
    }

    // Считаем сумму и количество по списку
    double sum = 0;
    int count = 0;
    Auto* temp = head;
    while (temp != nullptr) {
        // Простой перевод строки цены в число
        int price = 0;
        for (char c : temp->cena) {
            if (c >= '0' && c <= '9')
                price = price * 10 + (c - '0');
        }
        sum += price;
        count++;
        temp = temp->next;
    }
    if (count == 0) return;
    double avg = sum / count;
    cout << "Средняя цена: " << avg << " руб.\n";
    cout << "----------------------------------------\n";
    bool found = false;
    temp = head;
    while (temp != nullptr) {
        // Считаем цену машины
        int price = 0;
        for (char c : temp->cena) {
            if (c >= '0' && c <= '9')
                price = price * 10 + (c - '0');
        }
        if (price > avg) {
            cout << "VIN: " << temp->VIN << "\n"
                << "Марка: " << temp->marka << "\n"
                << "Модель: " << temp->model << "\n"
                << "Год: " << temp->god << "\n"
                << "Кузов: " << temp->kuzov << "\n"
                << "Цвет: " << temp->color << "\n"
                << "Привод: " << temp->driveType << "\n"
                << "Цена: " << temp->cena << " руб.\n"
                << "----------------------------------------\n";
            found = true;
        }
        temp = temp->next;
    }
    if (!found) {
        cout << "Нет автомобилей дороже среднего.\n";
    }
    cout << "\nНажмите любую клавишу...";
    _getch();
}



void LoadData()
{
    ifstream file("autos.txt");
    if (!file) {
        cout << "Файл не найден.\n";
        return;
    }

    string line;
    getline(file, line);           // читаем количество как строку
    int count = 0;
    for (char c : line) {          // простой перевод строки в число (вручную)
        if (c >= '0' && c <= '9')
            count = count * 10 + (c - '0');
    }

    for (int i = 0; i < count; i++)
    {
        Auto* car = new Auto;

        // Читаем ВСЕ поля через getline — одинаково и просто
        getline(file, car->VIN);
        getline(file, car->marka);
        getline(file, car->model);
        getline(file, car->god);        // год как текст
        getline(file, car->kuzov);
        getline(file, car->color);
        getline(file, car->driveType);
        getline(file, car->cena);       // цена как текст

        car->next = head;  // вставляем в начало списка
        head = car;
    }

    file.close();
    cout << "Загружено " << count << " авто.\n";
}
// вывод в консоль меню программы
// Главное меню (выводит пункты и возвращает нажатую клавишу)
char MainMenu() {
    while (true) {
        system("cls");
        SetTextColor(15);
        cout << " УЧЕТ ПОДДЕРЖАННЫХ АВТОМОБИЛЕЙ \n\n";

        SetTextColor(2);
        cout << "[1]  Добавить автомобиль\n";
        cout << "[2]  Вывод списка автомобилей\n";
        cout << "[3]  Поиск по номеру (VIN)\n";
        cout << "[4]  Поиск по марке\n";
        cout << "[5]  Поиск по модели\n";
        cout << "[6]  Поиск по типу кузова\n";
        cout << "[7]  Поиск по году выпуска\n";
        cout << "[8]  Поиск по цвету кузова\n";
        cout << "[9]  Поиск по типу привода\n";
        cout << "[10] Поиск по цене\n";
        cout << "[11] Редактировать автомобиль\n";
        SetTextColor(4);
        cout << "[12] Удалить автомобиль по номеру\n";
        cout << "[13] Выйти из программы\n\n";

        SetTextColor(15);
        cout << "Ваш выбор > ";

        int choice;
        cin >> choice;
        cin.ignore(); // Очистка буфера после ввода числа

        if (choice >= 1 && choice <= 13) {
            return choice;   // Возвращаем ЧИСЛО, а не символ
        }
        else {
            cout << "Такого варианта не существует! Нажмите любую клавишу...";
            _getch();
        }
    }
}

// Обработка действий пользователя в главном цикле
void HandleEvents() {
    int choice = 0;                        // Хранит номер выбранного пункта
    while (choice != 13) {                 // 13 — это выход из программы
        choice = MainMenu();               // Получаем выбор от 1 до 13
        switch (choice) {
        case 1:  AddData(); break;          // Добавление автомобиля
        case 2:  PrintData(); break;        // Вывод списка всех авто
        case 3:  SearchByVin(); break;      // Поиск по VIN
        case 4:  SearchByBrand(); break;    // Поиск по марке
        case 5:  SearchByModel(); break;    // Поиск по модели
        case 6:  SearchByBodyType(); break; // Поиск по типу кузова
        case 7:  SearchByYear(); break;     // Поиск по году выпуска
        case 8:  SearchByColor(); break;    // Поиск по цвету кузова
        case 9:  SearchByDriveType(); break;// Поиск по типу привода
        case 10: SearchByPrice(); break;    // Поиск по цене
        case 11: EditData(); break;         // Редактирование автомобиля
        case 12: DeleteByVin(); break;      // Удаление по VIN
        case 13: return;                    // Завершение программы
        }
    }
}

int main() {
    SetConsoleOutputCP(1251);
    if (!LOGIN_IN()) {
        cout << "\nПрограмма завершена.\n";
        _getch();
        return 0;
    }
    setlocale(LC_ALL, "");
    LoadData();       // Загружаем базу из файла
    HandleEvents();   // Работа с меню
    SaveData();       // Сохраняем перед выходом
    return 0;
}