#include <iostream>
#include <cmath>       // Для возведения в степень
#include <iomanip>     // Для управления количеством знаков после точки в действительных числах
#include <windows.h>
using namespace std;
int main() {
    // Задание 1
    // FLOAT
    float a_f = 100;
    float b_f = 0.001;
    float num1_f, num2_f, num3_f, num4_f, num5_f;

    num1_f = pow((a_f - b_f), 4);
    num2_f = pow(a_f, 4) - (4 * pow(a_f,3) * b_f + 6 * pow(a_f,2) * pow(b_f,2));
    num3_f = num1_f - num2_f;
    num4_f = pow(b_f, 4) - 4 * a_f * pow(b_f,3);
    num5_f = num3_f / num4_f;
    cout << fixed << setprecision(12) << num1_f << endl << num2_f << endl << num3_f << endl << num4_f << endl << num5_f << endl << endl; 

    // Задание 1
    // DOUBLE
    double a_d = 100;
    double b_d = 0.001;
    double num1_d, num2_d, num3_d, num4_d, num5_d;

    num1_d = pow((a_d - b_d), 4);
    num2_d = pow(a_d, 4) - 4 * pow(a_d,3) * b_d + 6 * pow(a_d,2) * pow(b_d,2);
    num3_d = num1_d - num2_d;
    num4_d = pow(b_d, 4) - 4 * a_d * pow(b_d,3);
    num5_d = num3_d / num4_d;
    cout << fixed << setprecision(12) << num1_d << endl << num2_d << endl << num3_d << endl << num4_d << endl << num5_d << endl << endl; 
    
    // Задание 2
    int n, m;
    n = 5;
    m = 10;
    int res1, res2, res3;

    res1 = n++-m;
    res2 = m-- > n;
    res3 = n-- > m;    

    cout << res1 << endl << res2 << endl << res3 << endl;
    return 0;
}
