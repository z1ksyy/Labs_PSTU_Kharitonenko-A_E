#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <windows.h>

using namespace std;

// проверка по маске с помощью метода find()
bool checkMask(string word, string mask) 
{
    // Если маска состоит только из *, подходит любое слово
    if (mask == "*") 
    {
        return true;
    }

    size_t star = mask.find('*');

    // Если в маске нет *, то слова должны быть идентичны маске
    if (star == string::npos) 
    {
        return word == mask;
    }

    // Если маска начинается с * и заканчивается на *
    // то слово просто должно содержать эту букву, последовательность
    if (mask.front() == '*' && mask.back() == '*') 
    {
        string part = mask.substr(1, mask.length() - 2);
        return word.find(part) != string::npos;
    }

    // Если * только в начале, то слово заканчивается на эту часть
    if (mask.front() == '*') 
    {
        string part = mask.substr(1);
        if (word.length() >= part.length()) 
        {
            return word.substr(word.length() - part.length()) == part;
        }
        return false;
    }

    // Если * только в конце, то слово начинается с этой части
    if (mask.back() == '*') 
    {
        string part = mask.substr(0, mask.length() - 1);
        return word.find(part) == 0;
    }

    return false;
}

int main() 
{
    // Для ввода-вывода кириллицы
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    string sentence, mask;

    cout << "Введите предложение (слова должны быть записаны через '_'): " << endl;
    cin >> sentence;

    cout << "Введите маску:" << endl;
    
    cin >> mask;

    // Разбиваем предложение на слова по символу '_'
    stringstream ss(sentence);
    string word;
    vector<string> result;

    while (getline(ss, word, '_')) 
    {
        if (checkMask(word, mask)) 
        {
            result.push_back(word);
        }
    }

    // Вывод
    cout << "Подходящие слова: ";
    if (result.empty()) 
    {
        cout << "нет";
    } else 
    {
        for (size_t i = 0; i < result.size(); ++i) 
        {
            cout << result[i];
            if (i < result.size() - 1) 
                cout << " | ";
        }
    }
    cout << endl;

    return 0;
}
