#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <windows.h>

using namespace std;

// Структура для автомобиля
struct Car 
{
    char brand[50];
    char serialNumber[20];
    char regNumber[20];
    int year;
};

// Функция для формирования файла
void createFile(const char* filename) 
{
    ofstream file(filename, ios::binary);
    if (!file) 
    {
        cerr << "Ошибка. Не удалось открыть файл для записи" << endl;
        return;
    }

    int n;
    cout << "Введите количество автомобилей: ";
    cin >> n;

    Car car;
    for (int i = 0; i < n; ++i) 
    {
        cout << endl;
        cout << "Автомобиль №" << i + 1 << endl;
        cout << "Марка: "; cin >> car.brand;
        cout << "Серийный номер: "; cin >> car.serialNumber;
        cout << "Регистрационный номер: "; cin >> car.regNumber;
        cout << "Год выпуска: "; cin >> car.year;
        file.write(reinterpret_cast<char*>(&car), sizeof(Car));
    }
    file.close();
    cout << "Файл успешно сформирован" << endl;
}

// Функция для печати содержимого файла
void printFile(const char* filename) 
{
    ifstream file(filename, ios::binary);
    if (!file) 
    {
        cerr << "Ошибка. Не удалось открыть файл" << endl;
        return;
    }

    Car car;
    cout << endl << "Содержимое" << endl;
    while (file.read(reinterpret_cast<char*>(&car), sizeof(Car))) 
    {
        cout << "Марка: " << car.brand 
             << " | Серийный: " << car.serialNumber 
             << " | Рег. номер: " << car.regNumber 
             << " | Год: " << car.year << endl;
    }
    file.close();
}

// Функция для удаления n элементов из начала файла
void deleteFromStart(const char* filename, int countToDelete) 
{
    ifstream fileIn(filename, ios::binary);
    if (!fileIn) 
    {
        cerr << "Ошибка. Не удалось открыть файл" << endl;
        return;
    }

    // Определяем размер файла и количество записей
    fileIn.seekg(0, ios::end);
    streampos fileSize = fileIn.tellg();
    fileIn.seekg(0, ios::beg);
    int totalRecords = fileSize / sizeof(Car);

    if (countToDelete >= totalRecords) 
    {
        cout << "Удаление невозможно, элементов в файле меньше или равно запрошенному" << endl;
        fileIn.close();
        return;
    }

    // Пропускаем записи, которые нужно удалить
    fileIn.seekg(countToDelete * sizeof(Car), ios::beg);

    // Создаем временный файл для записи оставшихся данных
    ofstream fileOut("temp.bin", ios::binary);
    Car car;
    while (fileIn.read(reinterpret_cast<char*>(&car), sizeof(Car))) 
    {
        fileOut.write(reinterpret_cast<char*>(&car), sizeof(Car));
    }
    fileIn.close();
    fileOut.close();

    // Заменяем старый файл новым
    remove(filename);
    rename("temp.bin", filename);
    cout << "Удалено элементов из начала: " << countToDelete << endl;
}

// Функция поиска и добавления элемента после заданного регистрационного номера
void addAfterRegNumber(const char* filename, const char* targetRegNum) 
{
    ifstream fileIn(filename, ios::binary);
    if (!fileIn) 
    {
        cerr << "Ошибка. Не удалось открыть файл" << endl;
        return;
    }

    ofstream fileOut("temp.bin", ios::binary);
    Car car;
    bool found = false;

    while (fileIn.read(reinterpret_cast<char*>(&car), sizeof(Car))) 
    {
        fileOut.write(reinterpret_cast<char*>(&car), sizeof(Car)); // Копируем текущий

        // Если нашли нужный номер и еще не добавляли
        if (strcmp(car.regNumber, targetRegNum) == 0 && !found) 
        {
            Car newCar;
            cout << endl << "Введите данные нового автомобиля:" << endl;
            cout << "Марка: "; cin >> newCar.brand;
            cout << "Серийный номер: "; cin >> newCar.serialNumber;
            cout << "Регистрационный номер: "; cin >> newCar.regNumber;
            cout << "Год выпуска: "; cin >> newCar.year;
            
            fileOut.write(reinterpret_cast<char*>(&newCar), sizeof(Car));
            found = true;
        }
    }
    fileIn.close();
    fileOut.close();

    if (!found) 
    {
        cout << "Автомобиль с рег. номером '" << targetRegNum << "' не найден. Добавление не выполнено." << endl;
        remove("temp.bin");
    } else 
    {
        remove(filename);
        rename("temp.bin", filename);
        cout << "Элемент успешно добавлен." << endl;
    }
}

int main() 
{

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    const char* filename = "cars.bin";

    // Формирование файла
    createFile(filename);

    // Печать исходного файла
    cout << endl << "Исходный файл:";
    printFile(filename);

    // Удаление 3 элементов из начала файла
    deleteFromStart(filename, 3);
    
    cout << endl << "Файл после удаления:";
    printFile(filename);

    // Добавление элемента после заданного рег. номера
    char target[20];
    cout << endl << "Введите регистрационный номер, после которого нужно добавить элемент: ";
    cin >> target;
    addAfterRegNumber(filename, target);

    cout << endl << "Итоговый файл:";
    printFile(filename);

    return 0;
}
