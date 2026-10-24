#include <iostream>
#include <cmath>
#include <iomanip>
#include <clocale>
using namespace std;
int main() 
{
    setlocale(LC_ALL, ".UTF-8");
    int N = 13;
    double sum = 0;
    double ln_fct = 0;
    for (int n = 1; n <= N; n++)
    {
        ln_fct += log(n);
        double a_n = ln_fct / (n * n);
        sum += a_n;
    }
    cout << fixed << setprecision(6);
    cout << "Сумма первых 13 членов ряда: " << sum;
    return 0;
}
