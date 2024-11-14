#include <iostream>
#include <limits>
#include "LineSegment.h"

using namespace std;

double getInput(const string& prompt) {
    double value; // Переменная для хранения введенного значения
    cout << prompt; // Выводим запрос пользователю
    cin >> value; // Читаем значение с консоли
    return value; // Возвращаем введенное значение
}

// Функция для получения координат отрезка с проверкой
void getSegmentCoordinates(double& x1, double& x2) {
    while (true) {
        x1 = getInput("Введите координату начала отрезка: ");
        x2 = getInput("Введите координату конца отрезка: ");
        if (x1 < x2) {
            break; // Если введенные значения корректные, выходим из цикла
        } else {
            cout << "Ошибка: начало отрезка должно быть меньше конца отрезка. Попробуйте снова." << endl;
        }
    }
}

int main() {
    double x1, x2;

    // Получаем координаты первого отрезка с проверкой
    getSegmentCoordinates(x1, x2);
    LineSegment segment1(x1, x2);

    // Получаем координаты второго отрезка с проверкой
    getSegmentCoordinates(x1, x2);
    LineSegment segment2(x1, x2);

    // Выводим информацию о первом и втором отрезках
    cout << "Первый " << segment1 << endl;
    cout << "Второй " << segment2 << endl;

    // Находим пересечение двух отрезков
    LineSegment* intersection = segment1.intersect(segment2);

    // Проверяем, есть ли пересечение
    if (intersection) {
        cout << "Пересечение: " << *intersection << endl;
        delete intersection; // Освобождаем память, выделенную под пересечение
    } else {
        cout << "Отрезки не пересекаются." << endl;
    }
    LineSegment modifiedSegment = !segment1; // Унарная операция 
    cout << "Новый первый отрезок: " << modifiedSegment << endl;

    int intValue = segment2; // Неявное преобразование в int
    cout << "Целая часть координаты y второго отрезка: " << intValue << endl;

    double doubleValue = static_cast<double>(segment1); // Явное преобразование в double
    cout << "Координата x первого отрезка: " << doubleValue << endl;

    LineSegment incrementedSegment = segment1 + 1; // Бинарная операция 
    cout << "Первый отрезок после увеличения x на 1: " << incrementedSegment << endl;

    return 0; // Завершаем программу
}
