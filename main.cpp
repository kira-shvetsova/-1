#include <iostream>
#include "Time.h"
#include "House.h"
#include <limits>
#include <Windows.h>
#include "Employee.h"
#include "Gun.h"
using namespace std;


int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int count;

    cout << "Лабораторная работа № 3." << endl;

    while (true) { // Бесконечный цикл, пока пользователь не введет 0
        cout << "Введите номер задания от 1 до 6. Введите 0, чтобы закончить." << endl;
        cin >> count;

        if (count == 0) {
            break; // Завершение программы, если введено 0
        }

        switch (count) {
        case 1: {
            cout << "1. Время" << endl;
            cout << "Необходимо создать и вывести на экран текстовую форму для следующих вариантов времени: 10 секунд, 10000 секунд, 100000 секунд" << endl;
            Time time1(10);
            cout << "10 секунд:" << endl;
            time1.print();

            Time time2(10000);
            cout << "10000 секунд:" << endl;
            time2.print();

            Time time3(100000);
            cout << "100000 секунд:" << endl;
            time3.print();

            break; // Завершаем программу
        }
        case 2: {
            cout << "2. Этажи" << endl;
            cout << "Создать и вывести на экран дома с 1, 5, 23 этажами." << endl;
            House house1(1);
            house1.print();

            House house2(5);
            house2.print();

            House house3(23);
            house3.print();

            break;
        }
        case 3:{
            cout << "3. Сотрудники" << std::endl;
            cout << "Необходимо выполнить следующие задачи: 1. Создать Сотрудников Петрова, Козлова, Сидорова работающих в отделе IT. 2. Сделать Козлова начальником IT отдела. 3. Вывести на экран текстовое представление всех трех Сотрудников(у всех троих должен один и тот же отдел и начальник)." << std::endl;

            // Создаем сотрудников
            Employee petrov("Петров", "IT");
            Employee kozlov("Козлов", "IT", true); // Козлов - начальник отдела IT
            Employee sidorov("Сидоров", "IT");

            // Выводим текстовое представление сотрудников
            cout << petrov.toString() << endl;
            cout << kozlov.toString() << endl;
            cout << sidorov.toString() << endl;

            break;
        }
        case 5: {
            cout << "5. Этажи" << endl;
            cout << "Создать и вывести на экран дома с 2, 35, 91 этажами." << endl;
            House house1(2);
            house1.print();

            House house2(35);
            house2.print();

            House house3(91);
            house3.print();

            break;
        }
        case 6: {
            Gun gun(3);
            gun.print();

            for (int i = 0; i < 5; i++) {
                gun.shoot();
            }

            gun.print();

        }
        default:
            cout << "Неверный номер задания. Пожалуйста, попробуйте снова." << endl;
            break; // Завершение default
        }
    }

    return 0;
}
