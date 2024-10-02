#include <iostream>
using namespace std;

// Функция проверяет все ли цифры числа одинаковы
bool equalNum(int x) 
{
    // Получаем последнюю цифру числа
    int lastDigit = x % 10;

    x /= 10; // Удаляем последнюю цифру из числа

    // Проверяем остальные цифры
    while (x > 0) {
        // Если текущая цифра не равна последней, возвращаем false
        if (x % 10 != lastDigit) {
            return false;
        }
        // Убираем последнюю цифру
        x /= 10;
    }

    // Если все цифры одинаковы, возвращаем true
    return true;
}

int main() 
{
    int x;

    cout << "Введите число: ";
    cin >> x;
    
    // Проверка на корректность ввода
    if (cin.fail()) {
        cout << "Ошибка, проверьте правильность ввода" << endl;
        return 0;
    }

    // Получаем результат и выводим его
    bool result = equalNum(x);
    cout << "Результат: " << boolalpha << result << endl;

    return 0;
}
