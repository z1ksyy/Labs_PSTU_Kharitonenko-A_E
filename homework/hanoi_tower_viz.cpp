#include <iostream>
#include <vector>
#include <string>
#include <clocale>
using namespace std;

// Три стержня
vector<int> rods[3];

// Отрисовка текущего состояния всех стержней
void draw(int n, int step) {
    cout << "\n Ход " << step << "\n";
    for (int level = n - 1; level >= 0; level--) 
    {
        for (int r = 0; r < 3; r++) 
        {
            if (level < (int)rods[r].size()) 
            {
                // Рисуем диск
                int sz = rods[r][level];
                string disk(sz * 2 - 1, '=');
                int pad = (n * 2 - 1 - (int)disk.size()) / 2;
                cout << string(pad, ' ') << disk
                     << string(pad, ' ') << "  ";
            } else 
            {
                // Пустое место
                cout << string(n * 2 - 1, ' ') << "  ";
            }
        }
        cout << "\n";
    }
    cout << "\n"; 
}

// Рекурсивный алгоритм с отрисовкой после каждого хода
void han(int n, int start, int end, int temp, int &step, int total) 
{
    if (n <= 0) return;

    han(n - 1, start, temp, end, step, total);

    // Выполняем ход
    int disk = rods[start].back();
    rods[start].pop_back();
    rods[end].push_back(disk);
    step++;
    draw(total, step);

    han(n - 1, temp, end, start, step, total);
}

int main() {
    setlocale(LC_ALL, ".UTF-8");

    int n;
    cout << "Введите количество колец: ";
    cin >> n;

    // Кладём все диски на первый стержень
    for (int i = n; i >= 1; i--)
        rods[0].push_back(i);

    int step = 0;
    draw(n, step);
    han(n, 0, 2, 1, step, n);
    cout << "Всего ходов: " << step << "\n";

    return 0;
}
