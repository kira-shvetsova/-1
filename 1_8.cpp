#include <iostream>
using namespace std;


bool isDivisor (int a, int b)
{
    //Проверяем, делит ли одно из чисел другое
    return (a % b == 0 or b % a == 0);
}

int main() 
{
    int NumberA;
    int NumberB;
    

    cout << "Введите a: ";
    cin >> NumberA; 
    cout << "Введите b: ";
    cin >> NumberB;
    
    // Проверка на корректность ввода
    if (cin.fail()) {
        cout << "Ошибка, проверьте правильность ввода" << endl;
        return 0; 
    }


    // Вывод результата
    bool result = isDivisor (NumberA, NumberB);
    cout << "Вывод: "  << boolalpha << result << endl;

    return 0;
}
