#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

int main() 
{
    // Для корректного ввода и вывода кириллицы
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    int n;
    cout << "Введите количество строк: ";
    cin >> n;
    cin.ignore();

    // Создание динамического массива
    string* arr = new string[n];

    cout << "Введите строки: " << endl;
    for (int i = 0; i < n; i++) 
    {
        cout << (i + 1) << ": ";
        getline(cin, arr[i]);
    }

    int index;
    cout << "Введите номер строки для удаления (от 1 до " << n << "): ";
    cin >> index;

    // Переводим номер строки (с 1) в индекс массива (с 0)
    int index1 = index - 1;

    if (index1 < 0 || index1 >= n) 
    {
        cout << "Некорректный номер строки" << endl;
        delete[] arr;
        return 1;
    }

    // Создание нового динамического массива
    string* newarr = new string[n - 1];
    int k = 0;

    // Копируем все элементы, кроме удаляемого
    for (int i = 0; i < n; i++) 
    {
        if (i == index1) continue; // Пропуск нужной строки
        newarr[k] = arr[i];
        k++;
    }

    // Освобождение памяти изначального массива
    delete[] arr;
    arr = newarr;
    n--;

    cout << endl << "Массив после удаления: " << endl;
    for (int i = 0; i < n; i++) 
    {
        cout << (i + 1) << ": " << arr[i] << endl;
    }

    delete[] arr;

    cout << endl << "Нажмите Enter, чтобы выйти";
    cin.ignore();
    cin.get();

    return 0;
}
