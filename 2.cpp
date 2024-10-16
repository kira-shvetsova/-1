#include <iostream>
#include <list>
#include <vector>
#include <fstream>
#include <algorithm>
#include <numeric> 
#include <iterator> 
#include <set>
#include <Windows.h>
using namespace std;


void reverseList() { // Функция для обработки списка

    list<int> L; // Инициализация списка

    // Заполнение списка исходными числами
    int n;
    cout << "Введите количество целых чисел: ";
    cin >> n;

    cout << "Введите " << n << " целых числа: ";
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        L.push_back(x); // Добавляем число в конец списка
    }

    // Вывод элементов списка в исходном порядке
    cout << "Элементы списка в исходном порядке: ";
    for (auto index = L.begin(); index != L.end(); ++index) {
        cout << *index << " ";
    }
    cout << endl;

    // Вывод элементов списка в обратном порядке
    cout << "Элементы списка в обратном порядке: ";
    for (auto index = L.rbegin(); index != L.rend(); ++index) {
        cout << *index << " ";
    }
    cout << endl;
}


void insertZero() { // Функция для вставки нулей в вектор
    int n;
    cout << "Введите количество элементов в векторе (четное число): ";
    cin >> n;

    if (n % 2 != 0) { // Проверка на четность
        cout << "Ошибка! Введите четное количество элементов." << endl;
        return;
    }

    vector<int> V(n);
    cout << "Введите " << n << " целых числа: ";
    for (int i = 0; i < n; ++i) {
        cin >> V[i]; // Заполнение вектора
    }

    // Вставка 5 нулевых элементов в середину вектора
    V.insert(V.begin() + n / 2, 5, 0); // Вставка 5 нулей

    // Вывод элементов вектора после вставки
    cout << "Вектор после вставки нулей: ";
    for (const auto& elem : V) {
        cout << elem << " ";
    }
    cout << endl;
}

void combineLists() { // Функция для комбинирования двух списков

    list<int> L1, L2; // Инициализация списков

    int n;
    cout << "Введите количество элементов для списков: ";
    cin >> n;

    cout << "Введите элементы для списка L1: ";
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        L1.push_back(x); // Заполнение списка L1
    }

    cout << "Введите элементы для списка L2: ";
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        L2.push_back(x); // Заполнение списка L2
    }

    // Комбинирование списков
    auto i1 = L1.begin(); // Итератор для первого списка
    auto i2 = L2.begin(); // Итератор для второго списка

    list<int> L3; // Новый список для комбинированных элементов

    for (int i = 0; i < n; ++i) {
        L3.push_back(*i1++); // Добавляем элемент из L1
        L3.push_back(*i2++); // Добавляем элемент из L2
    }

    // Вывод комбинированного списка
    cout << "Комбинированный список: ";
    for (const auto& elem : L3) {
        cout << elem << " ";
    }
    cout << endl;
}
// Функция для записи чисел в файл с заменой 0 на 10
void writeNumbers() {
    string name;
    cout << "Введите имя файла: ";
    cin >> name;

    vector<int> numbers; // Вектор для хранения чисел
    int num;

    cout << "Введите целые числа (введите -1 для завершения ввода):" << endl;
    while (true) {
        cin >> num;
        if (num == -1) break; // Завершение ввода
        numbers.push_back(num); // Добавляем число в вектор
    }
    ofstream outFile(name); // Открытие файла с именем name

    if (!outFile) {
        cerr << "Ошибка при открытии файла!" << endl;
        return;
    }

    // Замены 0 на 10
    for (int num : numbers) {
        if (num == 0) {
            outFile << 10; // Заменяем 0 на 10
        }
        else {
            outFile << num; // Записываем число как есть
        }
        outFile << "  "; // Добавляем два пробела
    }

    outFile.close(); // Закрываем файл
    cout << "Числа успешно записаны в файл." << endl; // Подтверждение записи
}
// Функция для добавления нуля перед последним элементом первой половины, совпадающим с любым элементом из второй половины
void addZero() {
    vector<int> V;
    int size;

    cout << "Введите количество элементов в векторе (четное): ";
    cin >> size;

    if (size % 2 != 0) {
        cout << "Размер вектора должен быть четным!" << endl;
        return;
    }

    cout << "Введите элементы вектора:" << endl;
    for (int i = 0; i < size; ++i) {
        int num;
        cin >> num;
        V.push_back(num);
    }

    size_t halfSize = V.size() / 2; //Вычисление размера вектора
    //Создание двух векторов для 1 и 2 половины
    vector<int> firstHalf(V.begin(), V.begin() + halfSize);
    vector<int> secondHalf(V.begin() + halfSize, V.end());

    // Находим последний элемент первой половины, совпадающий с элементами второй половины
    auto ii = std::find_if(firstHalf.rbegin(), firstHalf.rend(),
        [&secondHalf](int value) {
            return std::find(secondHalf.begin(), secondHalf.end(), value) != secondHalf.end();
        });

    // Если нашли такой элемент, добавляем ноль перед ним
    if (ii != firstHalf.rend()) {
        size_t index = std::distance(firstHalf.begin(), ii.base()) - 1; // Индекс элемента в оригинальном векторе
        V.insert(V.begin() + index, 0);
    }

    cout << "Измененный вектор: ";
    for (int num : V) {
        cout << num << " ";
    }
    cout << endl;
}

// Функция для заполнения векторов
void fillVectors(int A, int B) {
    vector<int> V1(10); // Вектор V1 с 10 элементами
    vector<int> V2(10); // Вектор V2 с 10 элементами

    // Заполнение первых 5 элементов V1 значением A
    fill(V1.begin(), V1.begin() + 5, A);
    // Заполнение последних 5 элементов V1 значением B
    fill(V1.begin() + 5, V1.end(), B);

    // Заполнение первых 5 элементов V2 значением A
    fill_n(V2.begin(), 5 , A);
    // Заполнение последних 5 элементов V2 значением B
    fill_n(V2.begin() + 5, 5, B);

    // Вывод результатов
    cout << "Вектор V1: ";
    for (const auto& val : V1) {
        cout << val << " ";
    }
    cout << endl;

    cout << "Вектор V2: ";
    for (const auto& val : V2) {
        cout << val << " ";
    }
    cout << endl;
}

void number(vector<int>& V) {
    // Используем  stable_partition для перемещения отрицательных и нулевых элементов
    auto neg_end = stable_partition(V.begin(), V.end(), [](int x) {
        return x < 0; // Условие для отрицательных элементов
        });
    stable_partition(neg_end, V.end(), [](int x) {
        return x == 0; // Условие для нулевых элементов
        });
}
void calculate(const vector<int>& L, vector<double>& V) {
    if (L.size() < 2) return; // Если вектор L содержит менее 2 элементов, ничего не делаем

    // Вычисляем средние значения
    for (size_t i = 0; i < L.size() - 1; ++i) {
        double  x = (L[i] + L[i + 1]) / 2.0;
        V.push_back(x);
    }

    // Вывод результата
    cout << "Средние арифметические значения: ";
    for (double y : V) {
        cout << y << " ";
    }
    cout << endl;
}
// Функция для подсчета количества векторов, содержащих все элементы вектора V0
int countVectorsV0(const vector<int>& V0, const vector<vector<int>>& vectors) {
    multiset<int> msV0(V0.begin(), V0.end()); // Создаем множество из элементов V0
    int count = 0;// Счетчик для хранения количества векторов, содержащих V0

    // Проходим по каждому вектору из списка векторов
    for (const auto& vec : vectors) {
        multiset<int> msVec(vec.begin(), vec.end()); // Создаем множество из текущего вектора
        if (includes(msVec.begin(), msVec.end(), msV0.begin(), msV0.end())) { // Проверяем, содержит ли текущий вектор все элементы из V0
            count++; //Увеличиваем счетчик
        }
    }

    return count;
}
// Главная функция
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int count;

    cout << "Лабораторная работа № 2." << endl;

    while (true) { // Бесконечный цикл, пока пользователь не введет 0
        cout << "Введите номер задания от 1 до 9. Введите 0, чтобы закончить." << endl;
        cin >> count;

        if (count == 0) {
            break; // Завершение программы, если введено 0
        }

        switch (count) {
            case 1:
                cout << "1. Список" << endl;
                cout << "Дан набор целых чисел. Заполнить список L исходными числами и вывести элементы списка L в начале в исходном, а затем в обратном порядке." << endl;
                reverseList(); // Вызов функции для обработки списка
                break;

            case 2:
                cout << "2. Вектор" << endl;
                cout << "Дан вектор V с четным количеством элементов. Добавить в середину вектора 5 нулевых элементов.Использовать один вызов функции - члена insert." << endl;
                insertZero(); // Вызов функции для вставки нулей в вектор
                break;

            case 3:
                cout << "3. Комбинирование списков" << endl;
                cout << "Даны два списка L1 и L2 с одинаковым количеством элементов N. Получить в списке L2 комбинированный набор элементов исходных списков." << endl;
                combineLists(); // Вызов функции для комбинирования списков
                break;

            case 4:
                cout << "4. Текстовый файл" << endl;
                cout << "Дана строка name и набор целых чисел. Записать в текстовый файл с именем name все числа из исходного набора в том же порядке, заменяя каждое число 0 на число 10 и добавляя после каждого числа два пробела." << endl;
                writeNumbers(); // Вызов функции для записи чисел в файл
                break;

            case 5:
                cout << "5. Добавление нуля" << endl;
                cout << "Дан вектор V с четным количеством элементов. Добавить нулевой элемент перед последним элементом в первой половине вектора, совпадающим с каким-либо элементом из второй половины этого же вектора." << endl;
                addZero(); // Вызов функции для добавления нуля перед совпадением
                break;
            case 6:
                cout << "6. Половина А, половина B" << endl;
                cout << "Даны числа A и B и векторы V1 и V2, каждый из которых содержит не менее 10 элементов. Заполнить первые 5 элементов каждого вектора значениями A, а последние 5 — значениями B." << endl;
                int A, B;

                cout << "Введите значение A: ";
                cin >> A; // Ввод значения A

                cout << "Введите значение B: ";
                cin >> B; // Ввод значения B

                fillVectors(A, B); // Вызов функции для заполнения векторов
                break;
            case 7: {
                cout << "7. Перегруппировка" << endl;
                cout << "Дан вектор V, количество элементов которого делится на 3. Известно, что каждая треть вектора уже упорядочена по возрастанию.Решить для исходного вектора задачу 7.7" << endl;
                int n;
                cout << "Введите количество элементов вектора: ";
                cin >> n;

                vector<int> V(n);
                cout << "Введите элементы вектора: ";
                for (int i = 0; i < n; ++i) {
                    cin >> V[i];
                }

                cout << "Исходный вектор: ";
                for (int num : V) {
                    cout << num << " ";
                }
                cout << endl;

                number(V); // Вызов функции перегруппировки

                cout << "Перегруппированный вектор: ";
                for (int num : V) {
                    cout << num << " ";
                }
                cout << endl;
                break;}
            case 8: {
                cout << "8. Среднее арифметическое" << endl;
                cout << "Дан список L. Получить вектор V вещественных чисел, содержащий значения среднего арифметического для всех пар соседних элементов исходного списка" << endl;
                vector<int> L = { 1, 3, 4, 6 }; // Исходный список
                vector<double> V; // Вектор для хранения средних значений

                calculate(L, V); // Вызов функции для вычисления средних значений
                break;}
            case 9: {
                cout << "9. Векторы" << endl;
                cout << "Дан вектор V0, целое число N (> 0) и набор векторов V1, …, VN. Известно, что размер вектора V0 не превосходит размера любого из векторов V1, …, VN.Найти количество векторов VI, I = 1, …, N, в которых содержатся все элементы вектора V0(с учетом их повторений)." << endl;
                int n;
                cout << "Введите количество элементов в векторе V0: ";
                cin >> n;

                vector<int> V0(n);
                cout << "Введите элементы вектора V0: ";
                for (int i = 0; i < n; ++i) {
                    cin >> V0[i];
                }

                int m;
                cout << "Введите количество векторов V1, ..., VN: ";
                cin >> m;

                vector<vector<int>> vectors(m);
                for (int i = 0; i < m; ++i) {
                    int size;
                    cout << "Введите количество элементов в векторе V" << (i + 1) << ": ";
                    cin >> size;

                    vectors[i].resize(size);
                    cout << "Введите элементы вектора V" << (i + 1) << ": ";
                    for (int j = 0; j < size; ++j) {
                        cin >> vectors[i][j];
                    }
                }

                int result = countVectorsV0(V0, vectors); // Вызов функции
                cout << "Количество векторов, содержащих все элементы V0: " << result << endl;
                break;
            }
            default:
                cout << "Неверный номер задания. Попробуйте снова." << endl;
                break;
        }
    }

    return 0; // Возврат из main
}
