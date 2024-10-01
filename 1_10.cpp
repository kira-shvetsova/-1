#include <iostream>
using namespace std;

int lastNumSum(int a, int b) 
{
    // Суммируем последние цифры двух чисел
    return (a % 10) + (b % 10);
}

int main() 
{
    int summ = 0; // Переменная суммы
    int Number;

    // Выполняем последовательное сложение пяти чисел
    for (int i = 0; i < 5; ++i) {
        cout << "Введите число " << (i + 1) << ": ";
        cin >> Number;

        // Проверка на корректность ввода
        if (cin.fail()) {
            cout << "Ошибка, проверьте правильность ввода" << endl;
            return 0; 
        }

        // Сложение текущей суммы с последней цифрой введенного числа
        summ = lastNumSum(summ, Number);
    }

    // Вывод результата
    cout << "Итого: " << summ << endl;

    return 0;
}
