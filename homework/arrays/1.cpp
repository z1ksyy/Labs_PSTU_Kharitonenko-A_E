/* 
Дан одномерный массив целых чисел. Найти максимальный и минимальный
элементы. Вывести их значения, индексы первого встретившегося максимального и минимального
элементов, а также посчитать количество элементов, равных максимальному и минимальному (если их
несколько). Исходный массив создать самостоятельно (не использовать rand), чтобы можно было
проверить все случаи.
*/
#include <iostream>
#include <clocale>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[100];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    int max = arr[0], min = arr[0];
    int imax = 0, imin = 0, cmax = 0, cmin = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
            imax = i;
        }
        if (arr[i] < min)
        {
            min = arr[i];
            imin = i;
        }
    }
    for (int i = 0; i< n; i++)
    {
        if (arr[i] == max)
            cmax++;
        if (arr[i] == min)
            cmin++;
    }
    cout << endl;
    cout << " Max: " << max << " Index: " << imax << " Count: " << cmax;
    cout << endl;
    cout << " Min: " << min << " Index: " << imin << " Count: " << cmin;
    return 0;

}
