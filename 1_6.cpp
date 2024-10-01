#include <iostream>
using namespace std;

// Функция для проверки, является ли символ заглавной буквой
bool isUpperCase(char x) 
{
    return (x >= 'A' && x <= 'Z');
}

int main() 
{
    char letter;

    cout << "Введите букву: ";
    
    // Проверка на корректность ввода
    if (!(cin >> letter)) {
        cout << "Ошибка, проверьте правильность ввода" << endl;
        return 0; 
    }

    // Проверка, является ли введенный символ буквой
    if (!isalpha(letter)) {
        cout << "Ошибка, введите только букву" << endl;
        return 0;
    }

    // Вывод результата
    bool result = isUpperCase(letter);
    cout << "Вывод: " << boolalpha << result << endl;

    return 0;
}
