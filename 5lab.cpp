#include "lab5.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <random>
#include <stdexcept>
#include <ctime>
#include <cctype>
using namespace std;

//1 задание
// Метод для заполнения файла случайными числами
void FileProcessor::RandomNumbers(const string& filename, size_t count) {
    ofstream outFile(filename, ios::binary); // Открываем файл для записи в бинарном формате
    if (!outFile) {
        throw runtime_error("Не удалось открыть файл для записи");
    }

    srand(static_cast<unsigned>(time(0))); // Инициализация генератора случайных чисел

    for (size_t i = 0; i < count; ++i) {
        int number = rand() % 1000; // Генерация случайного числа от 0 до 999
        outFile.write(reinterpret_cast<const char*>(&number), sizeof(number)); // Запись числа в файл
    }

    outFile.close(); // Закрываем файл
}

// Метод для копирования чисел, начинающихся и заканчивающихся на одну и ту же цифру
void FileProcessor::copyNumbersWithSameStartEnd(const string& inputFilename, const string& outputFilename) {
    ifstream inFile(inputFilename, ios::binary); // Открываем входной файл для чтения
    if (!inFile) {
        throw std::runtime_error("Не удалось открыть входной файл для чтения");
    }

    ofstream outFile(outputFilename, ios::binary); // Открываем выходной файл для записи
    if (!outFile) {
        throw runtime_error("Не удалось открыть выходной файл для записи");
    }

    int number;
    while (inFile.read(reinterpret_cast<char*>(&number), sizeof(number))) { // Читаем числа из входного файла
        int firstDigit = abs(number); // Получаем модуль числа
        while (firstDigit >= 10) {
            firstDigit /= 10; // Находим первую цифру
        }

        int lastDigit = abs(number) % 10; // Находим последнюю цифру

        // Если первая и последняя цифры совпадают, записываем число в выходной файл
        if (firstDigit == lastDigit) {
            outFile.write(reinterpret_cast<const char*>(&number), sizeof(number)); // Запись числа в выходной файл
        }
    }

    inFile.close(); // Закрываем входной файл
    outFile.close(); // Закрываем выходной файл
}

//2 задание
// Метод для копирования элементов из файла в квадратную матрицу
void FileProcessor::copyToMatrix(const string& inputFile, int n) {
    ifstream inFile(inputFile, ios::binary); // Открываем файл для чтения в бинарном режиме
    if (!inFile) { // Проверяем, удалось ли открыть файл
        cerr << "Ошибка открытия файла: " << inputFile << endl;
        return;
    }

    vector<vector<int>> matrix(n, vector<int>(n, 0)); // Создаем матрицу n x n, заполненную нулями
    int number;
    int index = 0; // Индекс для заполнения матрицы

    // Читаем числа из файла и заполняем матрицу
    while (inFile.read(reinterpret_cast<char*>(&number), sizeof(number)) && index < n * n) {
        matrix[index / n][index % n] = number; // Заполняем матрицу значениями из файла
        index++;
    }
    // Запрашиваем цифру для замены
    int digit;
    std::cout << "Введите цифру для замены (0-9): ";
    std::cin >> digit;

    // Заменяем элементы, начинающиеся с заданной цифры
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (startsWithDigit(matrix[i][j], digit)) { // Проверяем, начинается ли элемент с указанной цифры
                matrix[i][j] = digit; // Заменяем элемент на цифру
            }
        }
    }

    // Выводим матрицу на экран
    std::cout << "Результирующая матрица:" << std::endl;
    for (const auto& row : matrix) { // Проходим по каждой строке матрицы
        for (int val : row) { // Проходим по каждому элементу строки
            std::cout << val << " "; // Выводим элемент на экран
        }
        std::cout << std::endl; // Переходим на новую строку после вывода всех элементов строки
    }
}

// Метод для проверки, начинается ли число с заданной цифры
bool FileProcessor::startsWithDigit(int number, int digit) {
    return std::to_string(number).front() == '0' + digit; // Преобразуем число в строку и проверяем первую цифру
}

//3 задание
// Метод для заполнения бинарного файла данными об игрушках
void FileProcessor::fillToyFile(const std::string& filename, const std::vector<Toy>& toys) {
    // Открываем файл для записи в бинарном режиме
    std::ofstream outFile(filename, std::ios::binary);
    if (!outFile) { // Проверяем, удалось ли открыть файл
        std::cerr << "Ошибка открытия файла для записи!" << std::endl;
        return;
    }

    // Записываем каждую игрушку в файл
    for (const auto& toy : toys) {
        outFile.write(reinterpret_cast<const char*>(&toy), sizeof(Toy));
    }

    outFile.close(); // Закрываем файл после записи
}

// Метод для чтения игрушек из бинарного файла и вывода их на экран
void FileProcessor::readToysFromFile(const std::string& filename) {
    // Открываем файл для чтения в бинарном режиме
    std::ifstream inFile(filename, std::ios::binary);
    if (!inFile) { // Проверяем, удалось ли открыть файл
        std::cerr << "Ошибка открытия файла для чтения!" << std::endl;
        return;
    }

    Toy toy; // Создаем объект Toy для чтения данных
    // Читаем данные из файла до конца
    while (inFile.read(reinterpret_cast<char*>(&toy), sizeof(Toy))) {
        // Выводим информацию о каждой игрушке на экран
        std::cout << "Название: " << toy.name
            << ", Цена: " << toy.price
            << ", Возрастные границы: " << toy.minAge
            << "-" << toy.maxAge << " лет" << std::endl;
    }

    inFile.close(); // Закрываем файл после чтения
}

// Метод для анализа игрушек и нахождения средней стоимости кубиков
void FileProcessor::analyzeToys(const std::string& filename) {
    // Открываем файл для чтения в бинарном режиме
    std::ifstream inFile(filename, std::ios::binary);
    if (!inFile) { // Проверяем, удалось ли открыть файл
        std::cerr << "Ошибка открытия файла для анализа!" << std::endl;
        return;
    }

    Toy toy; // Создаем объект Toy для чтения данных
    double totalPrice = 0.0; // Переменная для хранения общей стоимости кубиков
    int count = 0; // Счетчик количества кубиков

    // Читаем данные из файла до конца
    while (inFile.read(reinterpret_cast<char*>(&toy), sizeof(Toy))) {
        if (toy.name == "Кубики") { // Проверяем, является ли игрушка кубиками
            totalPrice += toy.price; // Добавляем цену кубиков к общей стоимости
            count++; // Увеличиваем счетчик кубиков
        }
    }

    inFile.close(); // Закрываем файл после анализа

    // Выводим среднюю стоимость кубиков, если они найдены
    if (count > 0) {
        std::cout << "Средняя стоимость кубиков: " << (totalPrice / count) << " рублей." << std::endl;
    }
    else {
        std::cout << "Кубики не найдены в файле." << std::endl; // Если кубики не найдены
    }
}

//4 задание
// Метод для заполнения файла случайными целыми числами
void FileProcessor::fillFileWithRandomNumbers(const std::string& filename, int count) {
    std::ofstream outFile(filename); // Открываем файл для записи
    if (!outFile) { // Проверяем, удалось ли открыть файл
        throw std::runtime_error("Не удалось открыть файл для записи");
    }

    std::random_device rd; // Генератор случайных чисел
    std::mt19937 gen(rd()); // Инициализация генератора
    std::uniform_int_distribution<> dis(1, 100); // Определяем диапазон случайных чисел (от 1 до 100)

    for (int i = 0; i < count; ++i) {
        outFile << dis(gen) << std::endl; // Записываем случайное число в файл по одной строке
    }
}
// Функция для уменьшения каждого элемента в файле на k раз
void FileProcessor::reduceFileElements(const std::string& inputFile, const std::string& outputFile, int k) {
    std::ifstream inFile(inputFile);
    std::ofstream outFile(outputFile);

    if (!inFile) {
        std::cerr << "Ошибка открытия входного файла!" << std::endl;
        return;
    }

    if (!outFile) {
        std::cerr << "Ошибка открытия выходного файла!" << std::endl;
        return;
    }

    int number;
    while (inFile >> number) {
        outFile << number / k << std::endl; // Уменьшаем число в k раз и записываем в новый файл
    }

    inFile.close();
    outFile.close();
}

//5 задание
// Метод для заполнения файла случайными целыми числами
void FileProcessor::fillFileWithRandomNumbers5(const std::string& filename, int count, int numbersPerLine) {
    std::ofstream outFile(filename); // Открываем файл для записи
    if (!outFile) { // Проверяем, удалось ли открыть файл
        throw std::runtime_error("Не удалось открыть файл для записи");
    }

    std::random_device rd; // Генератор случайных чисел
    std::mt19937 gen(rd()); // Инициализация генератора
    std::uniform_int_distribution<> dis(1, 100); // Определяем диапазон случайных чисел (от 1 до 100)

    for (int i = 0; i < count; ++i) {
        outFile << dis(gen); // Записываем случайное число
        // Если достигли количества чисел в строке, переходим на новую строку
        if ((i + 1) % numbersPerLine == 0) {
            outFile << std::endl;
        }
        else {
            outFile << " "; // Добавляем пробел между числами в одной строке
        }
    }
}

// Метод для нахождения суммы первого и максимального элементов файла
int FileProcessor::sumFirstAndMaxElements(const std::string& filename) {
    std::ifstream inFile(filename); // Открываем файл для чтения
    if (!inFile) { // Проверяем, удалось ли открыть файл
        throw std::runtime_error("Не удалось открыть файл для чтения");
    }

    int firstElement = 0;
    int maxElement = INT_MIN; // Начальное значение для максимального элемента
    bool isFirstElementFound = false;

    int number;
    while (inFile >> number) { // Читаем числа из файла
        if (!isFirstElementFound) {
            firstElement = number; // Сохраняем первое число
            isFirstElementFound = true;
        }
        if (number > maxElement) {
            maxElement = number; // Находим максимальное число
        }
    }

    if (!isFirstElementFound) { // Если файл пустой
        throw std::runtime_error("Файл пуст");
    }

    return firstElement + maxElement; // Возвращаем сумму первого и максимального элементов
}

//6 задание
// Метод для копирования строк, где первая или вторая буква соответствует заданной
void FileProcessor::copyLinesWithChar(const std::string& inputFilename, const std::string& outputFilename, char character) {
    std::ifstream inFile(inputFilename); // Открываем входной файл для чтения
    if (!inFile) { // Проверяем, удалось ли открыть файл
        throw std::runtime_error("Не удалось открыть входной файл для чтения");
    }

    std::ofstream outFile(outputFilename); // Открываем выходной файл для записи
    if (!outFile) { // Проверяем, удалось ли открыть файл
        throw std::runtime_error("Не удалось открыть выходной файл для записи");
    }

    std::string line; // Переменная для хранения строки
    char lowerChar = std::tolower(character); // Преобразуем введенный символ в нижний регистр

    while (std::getline(inFile, line)) { // Читаем строки из входного файла
        // Преобразуем первую и вторую буквы строки в нижний регистр и проверяем соответствие
        if (line.length() >= 2 && (std::tolower(line[0]) == lowerChar || std::tolower(line[1]) == lowerChar)) {
            outFile << line << std::endl; // Записываем строку в выходной файл
        }
    }

    // Закрываем файлы
    inFile.close();
    outFile.close();
}
