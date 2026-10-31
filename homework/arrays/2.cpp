/*
Дан одномерный массив целых чисел. Проверить, упорядочен ли он по
возрастанию. Использовать флажок.
*/
#include <iostream>
#include <clocale>
using namespace std;
int main()
{
    setlocale(LC_ALL, ".UTF-8");
    int n;
    cin >> n;
    int arr[100];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    bool f = true;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < arr[i - 1])
        {
            f = false;
        }
    }
    if (f) {
        cout << "Массив упорядочен по возрастанию" << endl;
    } else {
        cout << "Массив не упорядочен по возрастанию" << endl;
    }
    return 0;
}
