#ifndef TIME_H
#define TIME_H
using namespace std;
#include <iomanip>
#include <string>

// Класс Time для работы с временем в секундах
class Time {
public:
    // Конструктор, принимающий общее количество секунд
    Time(int seconds);

    // Метод для преобразования времени в строку
    string toString() const;
    // Метод для вывода времени на экран
    void print() const;

private:
    int totalSeconds; // Хранит общее количество секунд (в пределах суток)
};

#endif
