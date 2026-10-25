#include <iostream>
#include <cmath>
#include <clocale>
using namespace std;

int main() 
{
    // Функция для корректной работы кириллицы
    setlocale(LC_ALL, ".UTF-8");
    int N = 13; // Количество членов ряда
    double sum = 0; // Итоговая сумма
    double current_log_fact = 0; // Переменная для хранения ln(n!)
    // Цикл для вычисления суммы
    for (double n = 1; n <= N; n++) 
    {
        // Рекуррентное вычисление ln(n!):
        current_log_fact += log(n);
        // Вычисление текущего члена ряда a_n
        double a_n = current_log_fact / (n * n);
        // Добавление к сумме
        sum += a_n;
    }
    // Вывод суммы
    cout << "Сумма тринадцати членов ряда = " << sum;
    return 0;
}
