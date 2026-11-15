#include <iostream>
#include <clocale>

using namespace std;

// Рекурсивная функция перемещния n дисков
void han(int n, int start, int end, int temp)
{
    if (n <= 0 ) // Если дисков не осталось, то выходим из рекурсии
        return;
    han(n - 1,start,temp,end);
    cout << start << "-->" << end << endl;
    han(n - 1, temp, end, start);
}

int main()
{
    setlocale(LC_ALL, ".UTF-8");
    int n;
    cout << "Введите количество колец: ";
    cin >> n;
    han(n, 1, 3, 2); // Запуск с первого стержня на третий через второй
    return 0;
}
