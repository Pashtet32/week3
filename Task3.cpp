#include<iostream>
#include<ctime>
using namespace std;

int max(int a, int b)
{
	if (a >= b)
		return a;
	else
		return b;
}

int min(int a, int b)
{
	if (a >= b)
		return b;
	else
		return a;
}

void outarray(int* array, int numb)
{
	for (int i = numb - 1; i > 0; i--)
	{
		cout << array[i] << "*x^" << i << " + ";
	}
	cout << array[0];
}

void polyplus(int *polynomial_1, int number_1, int *polynomial_2, int number_2, int *polynomial_res, int & number_res)
{
	int i;
	for (i = 0; i < min(number_1, number_2); i++)
		polynomial_res[i] = polynomial_1[i]+polynomial_2[i];
	if (number_2 == max(number_1, number_2))
	{
		while (i < number_2)
		{
			polynomial_res[i] = polynomial_2[i];
			i++;
		}
	}
	else
	{
		while (i < number_1)
		{
			polynomial_res[i] = polynomial_1[i];
			i++;
		}
	}
	number_res = max(number_1, number_2);
}

void polymultiply(int *polynomial_1, int number_1, int *polynomial_2, int number_2, int *polynomial_res, int & number_res)
{	
	number_res = number_1 + number_2 - 1;
	for (int i = 0; i < number_res; i++)
	{
		polynomial_res[i] = 0;
	}
	for (int i = 0; i < number_1; i++)
	{
		for (int j = 0; j < number_2; j++)
		{
			polynomial_res[j + i] += polynomial_1[i] * polynomial_2[j];
		}
	}
}

void Lesha() //Lesha's function to show that it all at least works
{
	int number_1, number_2, number_res;
	int *polynomial_1, *polynomial_2, *polynomial_res;
	srand(time(NULL));
	cin >> number_1;
	polynomial_1 = new int[number_1];
	for (int i = 0;i < number_1; i++)
	{
		*(polynomial_1 + i) = rand() % 20 + 1;
	}
	cin >> number_2;
	polynomial_2 = new int[number_2];
	for (int i = 0;i < number_2; i++)
	{
		*(polynomial_2 + i) = rand() % 20 + 1;
	}
	number_res = number_1 + number_2;
	polynomial_res = new int[number_res];
	cout << endl << "Addition: " << endl << endl;
	outarray(polynomial_1, number_1);
	cout << endl << "+" << endl;
	outarray(polynomial_2, number_2);
	cout << endl << "=" << endl;
	polyplus(polynomial_1, number_1, polynomial_2, number_2, polynomial_res, number_res);
	outarray(polynomial_res, number_res);
	cout << endl << endl << "Multiplication: " << endl << endl;
	outarray(polynomial_1, number_1);
	cout << endl << "*" << endl;
	outarray(polynomial_2, number_2);
	cout << endl << "=" << endl;
	polymultiply(polynomial_1, number_1, polynomial_2, number_2, polynomial_res, number_res);
	outarray(polynomial_res, number_res);
	cout << endl;
}

void main()
{
	Lesha();
}