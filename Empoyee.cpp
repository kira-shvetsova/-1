#include "Employee.h"
#include <iostream>

// Конструктор класса Employee, инициализирует имя, название отдела и начальника
Employee::Employee(const std::string& name, const std::string& departmentName, bool manager)
    : name(name), departmentName(departmentName), manager(manager) {}

// Метод для получения текстового представления сотрудника
// Возвращает строку с информацией о сотруднике в зависимости от его статуса (начальник или нет
std::string Employee::toString() const {
    if (manager) {
        return name + " - начальник отдела " + departmentName;
    }
    else {
        return name + " работает в отделе " + departmentName;
    }
}
void Employee::print() const {
    std::cout << toString() << std::endl;
}
