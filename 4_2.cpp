#include <iostream>
#include <vector>
using namespace std;

// Функция для поиска последнего вхождения числа x в массив
int findLast(const vector<int>& arr, int x) 
{
    for (int i = arr.size() - 1; i >= 0; --i) {
        if (arr[i] == x) {
            return i; // Возвращаем индекс последнего вхождения
        }
    }
    return -1; // Если x не найден, возвращаем -1
}

int main() {
    int n;
    cout << "Введите размер массива: ";
    cin >> n;

    vector<int> arr(n); // Создаем вектор заданного размера

    cout << "Введите элементы массива:\n";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i]; // Ввод элементов массива
    }

    int x;
    cout << "Введите число для поиска: ";
    cin >> x; // Ввод числа для поиска

    int index = findLast(arr, x); // Вызов функции

    if (index != -1) {
        cout << "Результат: " << index << endl;
    } else {
        cout << "Число " << x << " не найдено в массиве." << endl;
    }

    return 0;
}
