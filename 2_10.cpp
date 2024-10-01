#include <iostream>
#include <string>
using namespace std;

void printDays(string x) {
    // Массив с днями недели
    const string days[] = {
        "понедельник", "вторник", "среда", 
        "четверг", "пятница", "суббота", 
        "воскресенье"
    };

    // Приводим строку к нижнему регистру для корректного сравнения
    for (auto &c : x) c = tolower(c);

    // Переменная для хранения индекса дня недели
    int index = -1;

    // Используем switch для определения индекса дня недели
    for (int i = 0; i < 7; ++i) {
        switch (index) {
            case -1:
                if (x == days[i]) {
                    index = i;
                }
                break;
            default:
                break;
        }
    }

    // Если индекс не был изменен, значит, это не день недели
    if (index == -1) {
        cout << "это не день недели" << endl;
    } else {
        // Выводим текущий и последующие дни недели
        for (int i = index; i < 7; ++i) {
            cout << days[i] << endl;
        }
    }
}

int main() {
    string x; // Переменная для ввода

    cout << "Введите название дня недели: ";
    cin >> x;

    // Вызываем функцию для вывода дней недели
    printDays(x);

    return 0;
}
