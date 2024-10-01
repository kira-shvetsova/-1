#include <iostream>
#include <string>
using namespace std;

// Функция для определения слова в зависимости от возраста
string age(int x) 
{
    string result = to_string(x) + " "; // Начинаем с числа

    // Определяем правильное слово
    if (x % 10 == 1 and x % 100 != 11) {
        result += "год";
    } else if (x % 10 >= 2 and x % 10 <= 4 and 
    (x % 100 < 12 or x % 100 > 14)) {
        result += "года";
    } else {
        result += "лет";
    }

    return result;
}

int main() 
{
    int x; // Переменная для ввода

    cout << "Введите возраст (целое число): ";
    cin >> x;

    // Проверка на корректность ввода
    if (cin.fail()) {
        cout << "Ошибка, проверьте правильность ввода" << endl;
        return 0;
    }

    // Получаем результат проверки
    string result = age(x);

    // Вывод результата
    cout << "Вывод: " << result << endl;

    return 0;
}
