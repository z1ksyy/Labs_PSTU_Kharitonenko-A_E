/*
Тот же массив из 7 чисел, пошагово отсортировать методом пузырька.
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
        cin >> arr[i];
    cout << "Исходный массив: ";
    for (int i = 0; i < n; i++) 
        cout << arr[i] << " ";
    cout << endl;
    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = 0; j < n - i - 1; j++) 
        {
            if (arr[j] > arr[j + 1]) 
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        cout << "Проход " << i + 1 << ": ";
        for (int k = 0; k < n; k++) 
            cout << arr[k] << " ";
        cout << endl;
    }
    cout << "Отсортированный массив: ";
    for (int i = 0; i < n; i++) 
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
