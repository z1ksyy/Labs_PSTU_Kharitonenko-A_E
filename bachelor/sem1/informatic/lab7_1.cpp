#include <iostream>
#include <vector>
#include <string>
#include <clocale>

using namespace std;

// Для массива: считаем отрицательные числа
int findCount(const vector<int>& arr) 
{
    int count = 0;
    for (int x : arr) 
    {
        if (x < 0) count++;
    }
    return count;
}

// Для строки: считаем слова с одинаковой первой и последней буквой
int findCount(const string& str) 
{
    int count = 0;
    string word = "";

    // Проходим по строке и собираем слова
    for (int i = 0; i <= str.length(); i++) 
    {
        // Если текущий символ буква (не пробел и не конец строки)
        if (i < str.length() && str[i] != ' ') 
        {
            word += str[i]; // Добавляем букву в слово
        } 
        else 
        {
            // Если слово закончилось (встретился пробел или конец строки)
            if (word.length() > 0) 
            {
                // Сравниваем первую и последнюю буквы
                char first = tolower(word[0]);
                char last = tolower(word[word.length() - 1]);
                
                if (first == last) 
                    count++;
                word = ""; // Сбрасываем слово для следующего
            }
        }
    }
    return count;
}

int main() 
{
    setlocale(LC_ALL, ".UTF-8");
  
    // Ввод массива
    int n;
    cout << "Введите количество элементов массива: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Введите " << n << " целых чисел: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Отрицательных чисел в массиве: " << findCount(nums) << endl;

    // Ввод строки
    cin.ignore(); // очищаем буфер после ввода числа

    string text;
    cout << "Введите строку: ";
    getline(cin, text);

    cout << "Слово c одинаковой первой и последней буквой: " << findCount(text) << endl;

    return 0;
}
