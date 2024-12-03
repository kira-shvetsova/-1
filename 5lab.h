#ifndef LAB5_H
#define LAB5_H

#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <string>
#include <sstream> 
using namespace std;

// Структура для хранения информации об игрушке
struct Toy {
    string name; // Название игрушки
    double price;     // Цена в рублях
    int minAge;      // Минимальный возраст
    int maxAge;      // Максимальный возраст
};

// Класс для обработки файлов
class FileProcessor {
public:
    // 1 задание
    // Метод для заполнения файла случайными числами
    void RandomNumbers(const string& filename, size_t count);
    // Метод для копирования чисел, начинающихся и заканчивающихся на одну и ту же цифру
    void copyNumbersWithSameStartEnd(const string& inputFilename, const string& outputFilename);

    //2 Задание
    // Метод для копирования элементов из файла в квадратную матрицу
    static void copyToMatrix(const std::string& inputFile, int n);
    // Метод для проверки, начинается ли число с заданной цифры
    static bool startsWithDigit(int number, int digit);


    //3 задание
    // Метод для заполнения бинарного файла данными об игрушках
    static void fillToyFile(const std::string& filename, const std::vector<Toy>& toys);
    // Метод для чтения игрушек из бинарного файла и вывода их на экран
    static void readToysFromFile(const std::string& filename);
    // Метод для анализа игрушек и нахождения средней стоимости кубиков
    static void analyzeToys(const std::string& filename);

    //4 задание
    // Метод для заполнения файла случайными целыми числами
    void fillFileWithRandomNumbers(const std::string& filename, int count);
    // Метод для уменьшения каждого элемента в файле в k раз
    void reduceFileElements(const std::string& inputFile, const std::string& outputFile, int k);

    //5 задание
    // Метод для заполнения файла случайными целыми числами
    void fillFileWithRandomNumbers5(const std::string& filename, int count, int numbersPerLine);
    // Метод для нахождения суммы первого и максимального элементов файла
    int sumFirstAndMaxElements(const std::string& filename);

    //6 задание
    // Метод для копирования строк, где первая или вторая буква соответствует заданной
    void copyLinesWithChar(const std::string& inputFilename, const std::string& outputFilename, char character);
};

#endif // LAB5_H


