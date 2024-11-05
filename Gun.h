#ifndef GUN_H
#define GUN_H

class Gun {
public:
    // Конструктор класса Gun, который инициализирует количество патронов
    Gun(int bullets = 5);

    // Метод shoot() выстрел из оружия
    void shoot();

    // Метод print() выводит текущее состояние оружия (количество патронов)
    void print() const;

private:
    // Переменная bullets хранит текущее количество патронов в оружии
    int bullets;
};

#endif 
