#include "lab5.h"
#include <iostream>
#include <algorithm>
#include <Windows.h>

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int count;

    cout << "Лабораторная работа № 5." << endl;

    while (true) { // Бесконечный цикл, пока пользователь не введет 0
        cout << "Введите номер задания от 1 до 6. Введите 0, чтобы закончить." << endl;
        cin >> count;

        if (count == 0) {
            break; // Завершение программы, если введено 0
        }

        switch (count) {
        case 1: {
            cout << "1. Одинаковая цифра" << endl;
            cout << "Переписать в новый файл компоненты исходного, начинающиеся и заканчивающиеся на одну и ту же цифру" << endl;
            FileProcessor processor; // Создаем объект FileProcessor

            string inputFilename = "input.bin"; // Имя входного бинарного файла
            string outputFilename = "output.bin"; // Имя выходного бинарного файла

            size_t count = 20; // Количество случайных чисел для генерации

            try {
                processor.RandomNumbers(inputFilename, count); // Заполняем файл случайными числами

                // Читаем и выводим содержимое входного файла на консоль
                ifstream inputFile(inputFilename, ios::binary);
                if (!inputFile) {
                    throw runtime_error("Не удалось открыть входной файл для чтения");
                }

                int number;
                cout << "Числа из входного файла:\n";
                while (inputFile.read(reinterpret_cast<char*>(&number), sizeof(number))) {
                    cout << number << " "; // Выводим числа на консоль
                }
                cout << endl;
                inputFile.close(); // Закрываем входной файл

                // Копируем числа, начинающиеся и заканчивающиеся на одну и ту же цифру
                processor.copyNumbersWithSameStartEnd(inputFilename, outputFilename);

                // Читаем и выводим результат на консоль
                ifstream resultFile(outputFilename, ios::binary);
                if (!resultFile) {
                    throw runtime_error("Не удалось открыть выходной файл для чтения");
                }
                cout << "Числа из выходного файла:\n";
                while (resultFile.read(reinterpret_cast<char*>(&number), sizeof(number))) {
                    cout << number << " "; // Выводим числа на консоль
                }
                cout << endl;
                resultFile.close(); // Закрываем файл результата

            }
            catch (const std::exception& e) {
                std::cerr << "Ошибка: " << e.what() << std::endl; // Обработка ошибок
            }
            break;
        }
        case 2: {
            cout << "2. Матрицы" << endl; // Исправлено на "2."
            cout << "Скопировать элементы заданного файла в квадратную матрицу размером. Заменить все элементы, начинающиеся с заданной цифры, на эту цифру" << endl;
            const std::string inputFile = "matrix.dat"; // Имя файла для хранения данных
            const int n = 3; // Размерность матрицы n x n

            // Создаем объект класса FileProcessor
            FileProcessor processor;
            // Заполняем файл случайными числами
            processor.RandomNumbers(inputFile, n * n);

            // Копируем элементы из файла в матрицу и обрабатываем их
            processor.copyToMatrix(inputFile, n);

            break;
        }
        case 3: {
            cout << "3. Игрушки" << endl; // Исправлено на "2."
            cout << "Файл содержит сведения об игрушках: название игрушки, ее стоимость в рублях и возрастные границы.Для детей какого возраста предназначены кубики ? Указать их среднюю стоимость" << endl;
            // Создаем несколько игрушек и добавляем их в вектор
            vector<Toy> toys = {
                {"Кубики", 500.0, 2, 5},  // Игрушка: Кубики, цена: 500 рублей, возраст: от 2 до 5 лет
                {"Машинка", 300.0, 3, 7},  // Игрушка: Машинка, цена: 300 рублей, возраст: от 3 до 7 лет
                {"Кукла", 700.0, 4, 10},   // Игрушка: Кукла, цена: 700 рублей, возраст: от 4 до 10 лет
                {"Конструктор", 800.0, 5, 12}, // Игрушка: Конструктор, цена: 800 рублей, возраст: от 5 до 12 лет
                {"Кубики", 700.0, 2, 5}, // Игрушка: Кубики, цена: 600 рублей, возраст: от 2 до 5 лет
                {"Слайм", 350.0, 7, 12}
            };

            const std::string filename = "toys.dat"; // Имя файла для хранения данных об игрушках
            // Создаем объект класса FileProcessor
            FileProcessor processor;
            // Заполняем файл данными об игрушках
            processor.fillToyFile(filename, toys);

            // Читаем игрушки из файла и выводим их на экран
            std::cout << "Содержимое файла:" << std::endl;
            processor.readToysFromFile(filename);

            // Анализируем игрушки и находим среднюю стоимость кубиков
            processor.analyzeToys(filename);

            break; // Завершаем программу успешно
        }
        case 4: {
            cout << "4. Уменьшене в k раз" << endl;
            cout << "Получить новый файл, уменьшив каждый элемент исходного в k раз." << endl;
            const std::string inputFilename = "input.txt";  // Имя входного файла
            const std::string outputFilename = "output.txt"; // Имя выходного файла
            const int count = 10;// Количество случайных чисел
            int k;// Переменная для хранения значения уменьшения
            // Создаем объект класса FileProcessor
            FileProcessor processor;
            // Заполняем файл случайными числами
            processor.fillFileWithRandomNumbers(inputFilename, count);

            // Запрашиваем у пользователя значение k
            std::cout << "Введите число, на которое нужно уменьшить элементы файла: ";
            std::cin >> k;

            // Уменьшаем элементы файла на k раз и записываем в новый файл
            processor.reduceFileElements(inputFilename, outputFilename, k);

            std::cout << "Файлы успешно обработаны." << std::endl;
            break;
        }
        case 5: {
            cout << "5.Сумма" << endl;
            cout << "Найти сумму первого и максимального элементов" << endl;
            FileProcessor processor; // Создаем объект класса FileProcessor
            const std::string filename = "random_numbers.txt"; // Имя файла для хранения случайных чисел
            int count = 20; // Общее количество случайных чисел для генерации
            int numbersPerLine = 5; // Количество чисел в одной строке

            try {
                // Заполнение файла случайными числами
                processor.fillFileWithRandomNumbers5(filename, count, numbersPerLine);
                std::cout << "Файл '" << filename << "' успешно заполнен случайными числами." << std::endl;

                // Нахождение суммы первого и максимального элементов файла
                int sum = processor.sumFirstAndMaxElements(filename);
                std::cout << "Сумма первого и максимального элементов: " << sum << std::endl;

            }
            catch (const std::exception& e) {
                std::cerr << "Ошибка: " << e.what() << std::endl; // Обработка исключений при работе с файлами
            }
            break;
        }
        case 6: {
            cout << "6.Текст" << endl;
            cout << "В файле хранится произвольный текст. Переписать в другой файл строки, в которых первой или второй буквой является бука, введенная пользователем." << endl;
            FileProcessor processor; // Создаем объект класса FileProcessor
            std::string inputFilename = "text.txt"; // Имя входного файла с текстом
            std::string outputFilename = "textoutput.txt"; // Имя выходного файла для записи результатов

            char character;
            std::cout << "Введите букву для поиска: ";
            std::cin >> character; // Ввод символа от пользователя

            try {
                processor.copyLinesWithChar(inputFilename, outputFilename, character); // Копируем строки
                std::cout << "Строки успешно скопированы в '" << outputFilename << "'." << std::endl;
            }
            catch (const std::exception& e) {
                std::cerr << "Ошибка: " << e.what() << std::endl; // Обработка ошибок при работе с файлами
            }

            break;
        }
        default:
            cout << "Неверный номер задания. Пожалуйста, попробуйте снова." << endl;
            break;
        }
    }

    return 0;
}
