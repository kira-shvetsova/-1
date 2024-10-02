#include <iostream>
using namespace std;

// Функция для реверса массива
void reverse(int arr[], int size) 
{
    int left = 0; // Начальная позиция
    int right = size - 1; // Конечная позиция

    while (left < right) {
        // Меняем местами элементы
        swap(arr[left], arr[right]);
        left++;
        right--;
    }
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

    // Вызов функции реверса массива
    reverse(arr, n);

    // Вывод нового массива
    cout << "Результат: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Освобождаем память
    delete[] arr;

    return 0;
}
