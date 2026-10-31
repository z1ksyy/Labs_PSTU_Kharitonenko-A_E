#include <iostream>
#include <cmath>

using namespace std;

int main() 
{
    double a = 0.1; // начальное значение a
    double b = 1; // начальное значение b
    int k = 10; // количество заданных шагов
    int n = 40; // заданное количество членов ряда
    double e = 0.0001; // заданная точность
    
    // вычисление шага
    double h = (b - a) / k;

    // внешний цикл в котором происходит изменение x от a до b с шагом h
    for (int i = 0; i <= k; ++i) 
    {
        double x = a + i * h;

        // случай а: вычисление суммы для заданного n (SN)
        double SN = 0;
        double current_term = x; // Первый член ряда a_0 = x

        for (int j = 0; j < n; ++j) 
        {
            SN += current_term;
            // рекуррентная формула для перехода к следующему члену
            current_term *= (-1) * x * x * (2 * j + 1) / (2 * j + 3);
        }

        // случай б: вычисление суммы для заданной точности (SB)
        double SB = 0;
        current_term = x; // сбрасываем текущий член для нового цикла
        int j = 0;
        
        // цикл продолжается, пока модуль текущего члена >= e
        while (abs(current_term) >= e) 
        {
            SB += current_term;
            // Та же рекуррентная формула
            current_term *= (-1) * x * x * (2 * j + 1) / (2 * j + 3);
            j++;
        }

        // точное значение функции
        double Y = atan(x);
        cout << "X = " << x << "  SB = " << SB << "  SN = " << SN << "  Y = "  << Y << endl;
    }
    return 0;
}
