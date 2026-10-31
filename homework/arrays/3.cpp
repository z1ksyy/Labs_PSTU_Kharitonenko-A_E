/*
Дан двумерный массив. Найти его максимальный элемент и индексы.
*/
#include <iostream>
#include <clocale>
using namespace std;
int main()
{
    setlocale(LC_ALL, ".UTF-8");
    int rows, cols;
    cout << "Введите количество строк ";
    cin >> rows;
    cout << "Введите количество столбцов ";
    cin >> cols;
    cout << endl;
    int arr[100][100];
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j ++)
        {
            cin >> arr[i][j];
        }
    }
    int max = arr[0][0];
    int maxrow = 0;
    int maxcol = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j ++)
        {
            if (arr[i][j] > max)
            {
                max = arr[i][j];
                maxrow = i;
                maxcol = j;
            }
        }
    }
    cout << "Максимальный элемент: " << max << endl;
    cout << "Индексы строки и столбца: " << maxrow << " " << maxcol;
    return 0;
}
