#include <iostream>
using namespace std;

// Функция для удаления отрицательных элементов из массива
int* deleteNegative(int arr[], int size, int& newSize) 
{
    // Подсчитываем количество неотрицательных элементов
    newSize = 0;
    for (int i = 0; i < size; ++i) {
        if (arr[i] >= 0) {
            newSize++;
        }
    }

    // Создаем новый массив нужного размера
    int* result = new int[newSize];
    int index = 0;

    // Копируем неотрицательные элементы в новый массив
    for (int i = 0; i < size; ++i) {
        if (arr[i] >= 0) {
            result[index++] = arr[i];
        }
    }

    return result; // Возвращаем указатель на новый массив
}

int main() {
    int size;

    cout << "Введите количество элементов в массиве: ";
    cin >> size;

    // Проверка на корректность ввода
    if (size <= 0) {
        cout << "Количество элементов должно быть положительным!" << endl;
        return 1;
    }

    int* arr = new int[size]; // Создаем массив динамически

    cout << "Введите элементы массива:\n";
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }

    int newSize;
    // Вызов функции удаления отрицательных элементов
    int* result = deleteNegative(arr, size, newSize);

    // Вывод нового массива без отрицательных элементов
    cout << "Результат: ";
    for (int j = 0; j < newSize; ++j) {
        cout << result[j] << " ";
    }
    cout << endl;

    return 0;
}
