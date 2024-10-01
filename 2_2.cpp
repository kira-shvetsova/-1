#include <iostream>
using namespace std;

// Функция для безопасного деления
double safeDiv(int x, int y) {
    if (y == 0) {
        return 0.0; // Возвращаем 0 при делении на 0
    }
    return static_cast<double>(x) / y; // Приводим x к типу double для корректного деления
}

int main() {
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

    // Вычисляем результат деления
    double result = safeDiv(x, y);

    // Вывод результата
    cout << "Вывод: " << result << endl;

    return 0;
}
