#include "House.h"
#include <iostream>
// Конструктор класса House
House::House(int n) : floors(n) {}

// Метод для получения текстового представления дома
string House::to_text() const {
    // Определяем правильное окончание слова "этаж"
    string ending;
    if (floors % 10 == 1 && floors % 100 != 11) {
        ending = "этажом";
    }
    else {
        ending = "этажами";
    }

    // Формируем строку с описанием дома
    return "Дом с " + to_string(floors) + " " + ending;
}
void House::print() const {
    cout << to_text() << endl;
}
