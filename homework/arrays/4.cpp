/*
Взять массив из 7 целых чисел, пошагово отсортировать его методом вставки
*/
#include <iostream>
#include <clocale>
using namespace std;
int main()
{
    setlocale(LC_ALL, ".UTF-8");
    const int n = 7;
    int arr[n];
    cout << "Введите " << n << " целых чисел: ";
    for (int i = 0; i < n; i++) 
    {
        cin >> arr[i];
    }
    cout << "Исходный массив: ";
    for (int i = 0; i < n; i++) 
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    for (int i = 1; i < n; i++) 
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) 
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
        cout << "Шаг " << i << ": ";
        for (int k = 0; k < n; k++) 
        {
            cout << arr[k] << " ";
        }
        cout << endl;
    }
    cout << "Отсортированный массив: ";
    for (int i = 0; i < n; i++) 
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
