#include <iostream>
using namespace std;

// Функция проверки, можно ли сложить 2 числа так, чтобы получить 3
bool sum3(int x, int y, int z) 
{
    // Проверяем все комбинации
    return (x + y == z) or (x + z == y) or (y + z == x);
}

int main() 
{
    int x, y, z; // Переменные для ввода

    cout << "Введите x (целое число): ";
    cin >> x; 
    cout << "Введите y (целое число): ";
    cin >> y; 
    cout << "Введите z (целое число): ";
    cin >> z; 

    // Проверка на корректность ввода
    if (cin.fail()) {
        cout << "Ошибка, проверьте правильность ввода" << endl;
        return 0; 
    }

    // Получаем результат проверки
    bool result = sum3(x, y, z);

    // Вывод результата
    cout << "Вывод: " << boolalpha << result << endl;

    return 0;
}
