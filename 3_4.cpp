#include <iostream>
using namespace std;

// Функция, которая возвращает x в степени y
int pow(int x, int y) 
{
    int result = 1; // Начальное значение результата
    for (int i = 0; i < y; ++i) {
        result *= x; // Умножаем результат на x y раз
    }
    return result; // Возвращаем результат
}

int main() 
{
    int x, y;

    cout << "Введите x: ";
    cin >> x;
    cout << "Введите y: ";
    cin >> y;

    // Проверка на корректность ввода
    if (cin.fail() || y < 0) {
        cout << "Ошибка, проверьте правильность ввода" << endl;
        return 0;
    }

    // Получаем результат и выводим его
    int result = pow(x, y);
    cout << "результат: " << result << endl;

    return 0;
}
