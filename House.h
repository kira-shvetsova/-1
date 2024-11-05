#ifndef HOUSE_H
#define HOUSE_H

#include <string>

using namespace std;

// Класс House для описания дома
class House {
private:
    int floors; // Количество этажей

public:
    // Конструктор
    House(int n);
    void print() const;
    // Метод для получения текстового представления дома
    string to_text() const;
    // Метод для получения количества этажей (только для чтения)
    int getFloors() const;
};

#endif // HOUSE_H
