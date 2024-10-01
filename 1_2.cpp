#include <iostream>
using namespace std;
int sumLastNums(int x)
{   
    //Берем модуль числа, чтобы сумма была корректной
    x=abs(x);
    
    int LD = x % 10;// Последняя цифра
	  x /= 10; //Удаляем последнюю цифру
	  int SLD = x % 10; // Предпоследняя цифра
	
	  return LD + SLD;// Возвращаем сумму цифр
}
int main()
{
	int Number;
	
	cout << "Введите число(не меньше двух знаков в числе): ";
	cin >> Number;
	
	//Проверка на кол-во знаков в числе
	if (abs(Number) < 10) 
	{
	    cout << "Ошибка, проверьте правильность ввода" << endl;
	    return 0;
	}
	
	int Result = sumLastNums(Number);
	cout << "Сумма последних цифр числа: " << Result << endl;
	
	return 0;
}
