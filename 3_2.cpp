#include <iostream>
#include <string>
#include <sstream>

using namespace std;

// Функция, которая возвращает строку с числами от x до 0
string reverseListNums(int x) 
{
    ostringstream oss; //ostringstream для формирования строки
    for (int i = x; i >= 0; --i) {
        oss << i; // Добавляем число к строке
        if (i > 0) {
            oss << " "; //пробел, если это не последнее число
        }
    }
    return oss.str(); // Возвращаем сформированную строку
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
    string result = reverseListNums(x);
    cout << "Результат: " << result << endl;

    return 0;
}
