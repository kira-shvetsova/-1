#include <iostream>
using namespace std;

// Функция для объединения двух массивов
int* concat(int arr1[], int size1, int arr2[], int size2) 
{
    // Создаем новый массив, размером двух массивов
    int* result = new int[size1 + size2];

    // Копируем элементы первого массива в новый массив
    for (int i = 0; i < size1; ++i) {
        result[i] = arr1[i];
    }

    // Копируем элементы второго массива в новый массив
    for (int i = 0; i < size2; ++i) {
        result[size1 + i] = arr2[i];
    }

    return result; // Возвращаем указатель на новый массив
}

int main() {
    int n1, n2;

    cout << "Введите размер первого массива: ";
    cin >> n1;
    int* arr1 = new int[n1]; // Создаем первый динамический массив

    cout << "Введите элементы первого массива:\n";
    for (int i = 0; i < n1; ++i) {
        cin >> arr1[i]; // Ввод элементов первого массива
    }

    cout << "Введите размер второго массива: ";
    cin >> n2;
    int* arr2 = new int[n2]; // Создаем второй динамический массив

    cout << "Введите элементы второго массива:\n";
    for (int i = 0; i < n2; ++i) {
        cin >> arr2[i]; // Ввод элементов второго массива
    }

    // Вызов функции объединения массивов
    int* result = concat(arr1, n1, arr2, n2);

    // Вывод нового объединенного массива
    cout << "Результат: ";
    for (int i = 0; i < n1 + n2; ++i) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
