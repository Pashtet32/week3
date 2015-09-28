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
		polynomial_res[i] = polynomial_1[i] + polynomial_2[i];
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
	for (int i = 0; i < number_1; i++)
	{
		*(polynomial_1 + i) = rand() % 20 + 1;
	}
	cin >> number_2;
	polynomial_2 = new int[number_2];
	for (int i = 0; i < number_2; i++)
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


void tests()
{
	int** polynominal_1;
	int** polynominal_2;
	int** polynominal_res_addition;
	int** polynominal_res_multiplication;
	int** polynominal_test_addition;
	int** polynominal_test_multiplication;
	int* number_test_addition;
	int* number_test_multiplication;
	int* number_res_addition;
	int* number_res_multiplication;
	polynominal_1 = new int*[10];
	polynominal_2 = new int*[10];
	polynominal_res_addition = new int*[10];
	polynominal_res_multiplication = new int*[10];
	polynominal_test_addition = new int*[10];
	polynominal_test_multiplication = new int*[10];
	number_test_addition = new int[10];
	number_test_multiplication = new int[10];
	number_res_addition = new int[10];
	number_res_multiplication = new int[10];

	// test0
	polynominal_1[0] = new int[1];
	polynominal_2[0] = new int[1];
	polynominal_res_addition[0] = new int[1];
	polynominal_res_multiplication[0] = new int[1];


	polynominal_1[0][0] = 1;
	polynominal_2[0][0] = 1;
	polynominal_res_addition[0][0] = 2;
	polynominal_res_multiplication[0][0] = 1;
	number_res_addition[0] = 1;
	number_res_multiplication[0] = 1;
	
	//test1
	polynominal_1[1] = new int[3];
	polynominal_2[1] = new int[2];
	polynominal_res_addition[1] = new int[3];
	polynominal_res_multiplication[1] = new int[4];

	polynominal_1[1][0] = 1000; polynominal_1[1][1] = 1000; polynominal_1[1][2] = 1000;
	polynominal_2[1][0] = 1000; polynominal_2[1][1] = 1000;
	polynominal_res_addition[1][0] = 2000; polynominal_res_addition[1][1] = 2000; polynominal_res_addition[1][2] = 1000;
	polynominal_res_multiplication[1][0] = 1000000; polynominal_res_multiplication[1][1] = 2000000; polynominal_res_multiplication[1][2] = 2000000; polynominal_res_multiplication[1][3] = 1000000;
	number_res_addition[1] = 3;
	number_res_multiplication[1] = 4;

	// test2
	polynominal_1[2] = new int[3];
	polynominal_2[2] = new int[3];
	polynominal_res_addition[2] = new int[3];
	polynominal_res_multiplication[2] = new int[5];

	polynominal_1[2][0] = 1; polynominal_1[2][1] = 16; polynominal_1[2][2] = 14;
	polynominal_2[2][0] = 12; polynominal_2[2][1] = 16; polynominal_2[2][2] = 5;
	polynominal_res_addition[2][0] = 13; polynominal_res_addition[2][1] = 32; polynominal_res_addition[2][2] = 19;
	polynominal_res_multiplication[2][0] = 12; polynominal_res_multiplication[2][1] = 208; polynominal_res_multiplication[2][2] = 429; polynominal_res_multiplication[2][3] = 304; polynominal_res_multiplication[2][4] = 74;
	number_res_addition[1] = 3;
	number_res_multiplication[1] = 5;

	//test3
	polynominal_1[3] = new int[6];
	polynominal_2[3] = new int[2];
	polynominal_res_addition[3] = new int[6];
	polynominal_res_multiplication[3] = new int[7];

	polynominal_1[3][0] = 1; polynominal_1[3][1] = 2; polynominal_1[3][2] = 0; polynominal_1[3][3] = 0; polynominal_1[3][4] = 3; polynominal_1[3][5] = 1;
	polynominal_2[3][0] = 0; polynominal_2[3][1] = 1;
	polynominal_res_addition[3][0] = 1; polynominal_res_addition[3][1] = 3; polynominal_res_addition[3][2] = 0; polynominal_res_addition[3][3] = 0; polynominal_res_addition[3][4] = 3; polynominal_res_addition[3][5] = 1;
	polynominal_res_multiplication[3][0] = 0; polynominal_res_multiplication[3][1] = 1; polynominal_res_multiplication[3][2] = 2; polynominal_res_multiplication[3][3] = 0; polynominal_res_multiplication[3][4] = 0; polynominal_res_multiplication[3][5] = 3; polynominal_res_multiplication[3][6] = 1;
	number_res_addition[1] = 6;
	number_res_multiplication[1] = 7;


	//testing
	for (int i = 0; i < 1; i++)
	{
		polyplus(polynominal_1[i], 1, polynominal_2[i], 1, polynominal_test_addition[i], number_test_addition[i]);
		polymultiply(polynominal_1[i], 1, polynominal_2[i], 1, polynominal_test_multiplication[i], number_test_multiplication[i]);
		//addiion
		if (number_res_addition[i] != number_test_addition[i])
		{
			cout << "addition FAIL" << endl;
			continue;
		}
		bool flag = true;
		for (int j = 0; j < number_res_addition[i]; j++)
		{
			if (polynominal_res_addition[i][j] != polynominal_test_addition[i][j])
			{
				flag = false;
				cout << "addition FAIL"<<endl;
				break;
			}
		}
		if (flag)
			cout << "addition OK" << endl;
		//multiplication
		if (number_res_multiplication[i] != number_test_multiplication[i])
		{
			cout << "multiplication FAIL" << endl;
			continue;
		}
		flag = true;
		for (int j = 0; j < number_res_multiplication[i]; j++)
		{
			if (polynominal_res_multiplication[i][j] != polynominal_test_multiplication[i][j])
			{
				flag = false;
				cout << "multiplication FAIL" << endl;
				break;
			}
		}
		if (flag)
			cout << "multiplication OK" << endl;

	}
	

}

void main()
{
	Lesha();
	//tests();
	system("PAUSE");
}
