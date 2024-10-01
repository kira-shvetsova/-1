#include <iostream>
using namespace std;

bool isPositive (int x)
{
	return x > 0;
}

int main()
{
	int Number;
	
	cout << "Введите число: ";
	cin >> Number;
	
	//Проверка на корректность ввода
	if (cin.fail()) 
	{
	    cout << "Ошибка, проверьте правильность ввода" << endl;
	    return 0;
	}

  //Вывод результата
	bool Result = isPositive(Number);
	cout << "Вывод: " << boolalpha << Result << endl;
	
	return 0;
}
