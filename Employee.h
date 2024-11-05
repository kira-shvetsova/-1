#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

class Employee {
public:
    // Конструктор, принимающий имя, название отдела и информацию о том, является ли начальником
    Employee(const std::string& name, const std::string& departmentName, bool manager = false);

    // Метод для получения текстового представления сотрудника
    std::string toString() const;
    void print() const;
private:
    std::string name;           // Имя сотрудника
    std::string departmentName; // Название отдела
    bool manager;                // Является ли сотрудник начальником
};

#endif // EMPLOYEE_H
