#ifndef LINESEGMENT_H
#define LINESEGMENT_H

#include <iostream>
#include <algorithm>

class LineSegment {
private:
    double x; // Координата начала отрезка
    double y; // Координата конца отрезка

public:
    // Конструктор по умолчанию
    LineSegment() : x(0), y(0) {}

    // Конструктор с параметрами
    LineSegment(double x1, double x2) {
        if (x1 > x2) {
            x = x2;
            y = x1;
        } else {
            x = x1;
            y = x2;
        }
    }

    // Конструктор копирования
    LineSegment(const LineSegment& result) : x(result.x), y(result.y) {}
    
    // Метод для определения пересечения двух отрезков
    LineSegment* intersect(const LineSegment& result) const;

    // Перегрузка оператора вывода
    friend std::ostream& operator<<(std::ostream& os, const LineSegment& segment);

    // Унарная операция
    LineSegment operator!() const {
        return LineSegment(0, y); // Устанавливаем начало отрезка в 0
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
        return LineSegment(x + value, y); // Увеличивает координату x на value
    }

};

// Метод для определения пересечения двух отрезков
LineSegment* LineSegment::intersect(const LineSegment& result) const {
    double newx = std::max(this->x, result.x);
    double newy = std::min(this->y, result.y);

    if (newx < newy) {
        return new LineSegment(newx, newy); // Возвращаем новый отрезок
    }
    return nullptr; // Нет пересечения
}

// Перегрузка оператора вывода
std::ostream& operator<<(std::ostream& os, const LineSegment& segment) {
    os << "Отрезок: [" << segment.x << ", " << segment.y << "]";
    return os;
}

#endif // LINESEGMENT_H
