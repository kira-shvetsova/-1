#ifndef LINESEGMENT_H
#define LINESEGMENT_H

#include <iostream>
#include <algorithm>

class LineSegment {
private:
    double x; // Координата начала отрезка
    double y; // Координата конца отрезка

public:
    // Конструкторы
    LineSegment() : x(0), y(0) {} // Конструктор, где хранятся нулевые значения
    LineSegment(double x1, double x2) : x(x1), y(x2) {} // Конструктор с координатами
    LineSegment(const LineSegment& result) : x(result.x), y(result.y) {} // Конструктор копирования

    // Метод для определения пересечения двух отрезков
    LineSegment* intersect(const LineSegment& result) const;

    // Перегрузка оператора вывода
    friend std::ostream& operator<<(std::ostream& os, const LineSegment& segment);

    // Унарная операция 
    LineSegment operator!() const {
        return LineSegment(0, y); // Устанавливаем соответствующую координату в 0
    }

    // Операция приведения типа int (неявная)
    operator int() const {
        return static_cast<int>(y); // Возвращает целую часть координаты y
    }

    // Операция приведения типа double (явная)
    explicit operator double() const {
        return x; // Возвращает координату x
    }

    // Бинарная операция 
    LineSegment operator+(int value) const {
        return LineSegment(x + value, y);
    }


};

#endif // LINESEGMENT_H
