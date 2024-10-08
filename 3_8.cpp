#include <iostream>
using namespace std;

// Функция, которая выводит левый треугольник
void leftTriangle(int x) 
{
    // Проходим по каждой строке от 1 до x
    for (int i = 1; i <= x; ++i) {
        // В каждой строке выводим i символов '*'
        for (int j = 0; j < i; ++j) {
            cout << '*';
        }
        // Переход на новую строку
        cout << endl;
    }
}

int main() {
    int x;

    cout << "Введите высоту треугольника: ";
    cin >> x;
    
    // Проверка на корректность ввода
        if (cin.fail() || x <= 0) {
            cout << "Ошибка, проверьте правильность ввода" << endl;}

    // Вызываем функцию для построения треугольника
    leftTriangle(x);

    return 0;
}
