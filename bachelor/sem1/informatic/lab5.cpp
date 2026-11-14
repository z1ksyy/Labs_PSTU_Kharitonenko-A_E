#include <iostream>

using namespace std;

// Функция для поиска максимального из повторяющихся элементов
int findMax(int matrix[][100], int rows, int cols) 
{
    int maxpovt  = -1000;    // Переменная, отвечающая за максимальный повторяющийся элемент
    bool found = false; // Флаг: нашли ли мы вообще повторяющийся элемент

    // Проходим по каждому элементу матрицы (внешние циклы)
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            int current = matrix[i][j]; // Текущее число
            int count = 0; // Счетчик его повторений

            // Считаем, сколько раз current встречается во всей матрице
            for (int r = 0; r < rows; r++) 
            {
                for (int c = 0; c < cols; c++) 
                {
                    if (matrix[r][c] == current) 
                    {
                        count++;
                    }
                }
            }

            // Если число повторяется (встретилось 2 и более раз)
            if (count > 1) 
            {
                // Если мы еще ничего не находили или нашли число больше текущего максимума
                if (!found || current > maxpovt) 
                {
                    maxpovt = current;
                    found = true;
                }
            }
        }
    }

    return maxpovt; // Вернем -1000, если повторяющихся нет
}

int main() 
{
    setlocale(LC_ALL, ".UTF-8");
    
    int rows, cols;

    // Ввод двумерного массива
    cout << "Введите количество строк: ";
    cin >> rows;
    cout << "Введите количество столбцов: ";
    cin >> cols;

    // Проверка, введен ли массив корректно
    if (rows <= 0 || cols <= 0 || rows > 100 || cols > 100) 
    {
        cout << "Ошибка: размеры должны быть от 1 до 100." << endl;
        return 1;
    }

    // Объявляем двумерный массив максимального размера (100x100)
    int matrix[100][100];

    // Ввод элементов матрицы
    cout << "Введите элементы матрицы (" << rows * cols << " чисел):" << endl;
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            cout << "Элемент [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }

    // Вывод введенной матрицы для проверки
    cout << "Введенная матрица:" << endl;
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            cout << matrix[i][j] << "\t"; // \t - табуляция для ровных столбцов
        }
        cout << endl;
    }

    // Вызов функции и вывод результата
    // Передаем матрицу как параметр в функцию
    int result = findMax(matrix, rows, cols);

    if (result == -1000) 
    {
        cout << "Повторяющихся элементов в матрице нет." << endl;
    } else 
    {
        cout << "Максимальный из повторяющихся элементов: " << result << endl;
    }

    return 0;
}
