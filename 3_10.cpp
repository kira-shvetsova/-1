#include <iostream>
#include <limits>
#include <cstdlib> // Для rand() и srand()
#include <ctime>   // Для time()

using namespace std;

// Функция игры 
void guessGame()
{
    // Генератор случайных чисел
    srand(static_cast<unsigned int>(time(0)));
    // Случайное число от 0 до 9
    int secretNumber = rand() % 10; 
    int user;
    int x = 0;


    while (true) {
        cout << "Введите число от 0 до 9: ";
        cin >> user;

        // Проверка на корректность ввода
        if (cin.fail() || user < 0 || user > 9) {
            cout << "Ошибка: введите число от 0 до 9." << endl;
            cin.clear(); // Очищаем состояние потока
            // Игнорируем неверный ввод
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            continue; // Запрашиваем ввод снова
        }

        x++; // Увеличиваем количество попыток

        if (user == secretNumber) {
            cout << "Вы угадали!" << endl;
            break; // Выход из цикла, если угадали
        } else {
            cout << "Вы не угадали, введите число от 0 до 9:" << endl;
        }
    }

    cout << "Вы отгадали число за " << x << " попыток." << endl;
}

int main() 
{
    guessGame(); // Запуск игры
    return 0;
}
