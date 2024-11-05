#include "Gun.h"
#include <iostream> 
using namespace std;


Gun::Gun(int bullets) : bullets(bullets) {
    // Инициализируем переменную bullets значением, переданным в конструктор
}

// Метод shoot() выстрел из оружия
void Gun::shoot() {
    // Проверяем, есть ли патроны
    if (bullets > 0) {
        cout << "Бах!" << endl; // Если патроны есть
        bullets--; // Уменьшаем количество патронов на 1
    }
    else {
        cout << "Клац!" << endl; // Если патронов нет
    }
}

// Метод print() выводит текущее состояние оружия
void Gun::print() const {
    cout << "Количество патронов: " << bullets << endl; // Выводим количество оставшихся патронов
}
