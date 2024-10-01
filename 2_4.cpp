#include <iostream>
#include <string> // Для использования типа string
using namespace std;

// Функция для сравнения двух чисел и возврата строки с результатом
string makeDecision(int x, int y) 
{
    if (x > y) {
        return to_string(x) + " > " + to_string(y);
    } else if (x < y) {
        return to_string(x) + " < " + to_string(y);
    } else {
        return to_string(x) + " == " + to_string(y);
    }
}

int main() 
{
    int x, y; // Переменные для ввода

    cout << "Введите x (целое число): ";
    cin >> x; 
    cout << "Введите y (целое число): ";
    cin >> y; 

    // Проверка на корректность ввода
    if (cin.fail()) {
        cout << "Ошибка, проверьте правильность ввода" << endl;
        return 0; 
    }

    // Получаем результат сравнения
    string result = makeDecision(x, y);

    // Вывод результата
    cout << "Результат: " << result << endl;

    return 0;
}
