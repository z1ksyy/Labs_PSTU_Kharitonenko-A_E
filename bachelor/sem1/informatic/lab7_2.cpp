#include <iostream>
#include <cmath>
#include <cstdarg>

using namespace std;

const double PI = 3.14159265358979323846;

// Функция для нахождения одного угла треугольника по трем сторонам
double findAngle(double a, double b, double c) 
{
    double cosA = (b * b + c * c - a * a) / (2 * b * c);
    if (cosA > 1.0) cosA = 1.0;
    if (cosA < -1.0) cosA = -1.0;
    return acos(cosA) * 180.0 / PI;
}

// Функция с переменным числом параметров
void angles(int n, ...) 
{
    va_list args;
    va_start(args, n);

    double first_side = va_arg(args, double);
    bool isRegular = true; // Проверка: все ли стороны равны

    for (int i = 1; i < n; i++) 
    {
        double side = va_arg(args, double);
        if (abs(side - first_side) > 1e-9) 
        { // Если сторона отличается
            isRegular = false;
        }
    }
    va_end(args);

    cout << "Углы " << n << "-угольника: ";
    
    if (isRegular) 
    {
        // Формула правильного n-угольника: (n-2)*180/n
        double angle = (n - 2) * 180.0 / n;
        for (int i = 0; i < n; i++) 
        {
            cout << angle << " ";
        }
    } else 
    {
        cout << "Невозможно вычислить (многоугольник не является правильным).";
    }
    cout << endl;
}

int main() {
    setlocale(LC_ALL, ".UTF-8");
    // Вызов функции findAngle не менее трех раз (проверка на треугольнике 3-4-5)
    cout << "Угол против стороны 3: " << findAngle(3.0, 4.0, 5.0) << "°" << endl;
    cout << "Угол против стороны 4: " << findAngle(4.0, 3.0, 5.0) << "°" << endl;
    cout << "Угол против стороны 5: " << findAngle(5.0, 3.0, 4.0) << "°" << endl;
    cout << endl;
    
    // Для 3-угольника
    // Но чтобы показать работу, возьмем равносторонний треугольник    angles(3, 3.0, 3.0, 3.0); 
    
    // n = 9 (правильный девятиугольник)
    angles(9, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0);
    
    // n = 11 (правильный одиннадцатиугольник)
    angles(11, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0);

    return 0;
}
