#include "Time.h"
#include <iostream>
#include <iomanip>
using namespace std;

Time::Time(int seconds) {
    totalSeconds = seconds % 86400; // Используем остаток от деления на 86400
}

// Метод toString преобразует общее количество секунд в строку 
string Time::toString() const {
    int hours = totalSeconds / 3600; // Вычисляем часы
    int minutes = (totalSeconds % 3600) / 60; // Вычисляем минуты
    int seconds = totalSeconds % 60; // Вычисляем секунды

    // Формируем строку времени с добавлением ведущих нулей при необходимости
    return to_string(hours) + ":" +
        (minutes < 10 ? "0" : "") + to_string(minutes) + ":" +
        (seconds < 10 ? "0" : "") + to_string(seconds);
}

void Time::print() const {
    cout << toString() << endl;
}
