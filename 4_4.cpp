#include <iostream>
#include <vector>
using namespace std;

// Функция для добавления элемента x в массив на позицию pos
int* add(int arr[], int size, int x, int pos) 
{
    // Создаем новый массив размером size + 1
    int* newArr = new int[size + 1];

    // Копируем элементы до позиции pos
    for (int i = 0; i < pos; ++i) {
        newArr[i] = arr[i];
    }

    // Вставляем новый элемент x
    newArr[pos] = x;

    // Копируем оставшиеся элементы
    for (int i = pos; i < size; ++i) {
        newArr[i + 1] = arr[i];
    }

    return newArr; // Возвращаем указатель на новый массив
}

int main() 
{
    int n;
    cout << "Введите размер массива: ";
    cin >> n;

    int* arr = new int[n]; // Создаем динамический массив

    cout << "Введите элементы массива:\n";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i]; // Ввод элементов массива
    }

    int x, pos;
    cout << "Введите число для добавления: ";
    cin >> x; // Ввод числа для добавления
    cout << "Введите позицию для вставки: ";
    cin >> pos; // Ввод позиции для вставки

    if (pos < 0 || pos > n) {
        cout << "Ошибка: позиция вне диапазона." << endl;
        delete[] arr; // Освобождаем память
        return 1;
    }

    // Вызов функции добавления элемента
    int* newArr = add(arr, n, x, pos);

    // Вывод нового массива
    cout << "Новый массив: ";
    for (int i = 0; i < n + 1; ++i) {
        cout << newArr[i] << " ";
    }
    cout << endl;

    // Освобождаем память
    delete[] arr;
    delete[] newArr;

    return 0;
}
