#include "iostream"
#include "algorithm"

using namespace std;

int* max_multiply(int* array, int n)
{
	int* res;
	res = new int[3];
	sort(array, array + n);
	if (array[n - 1] <= 0)
	{
		res[0] = array[n - 1];
		res[1] = array[n - 2];
		res[2] = array[n - 3];
		return res;
	}
	if (array[0] > 0)
	{
		res[0] = array[n - 1];
		res[1] = array[n - 2];
		res[2] = array[n - 3];
		return res;
	}
	if (array[0] * array[1] > array[n - 2] * array[n - 3])
	{
		res[0] = array[n - 1];
		res[1] = array[0];
		res[2] = array[1];
	}
	else
	{
		res[0] = array[n - 1];
		res[1] = array[n - 2];
		res[2] = array[n - 3];
	}
	return res;

}

void testitself(int* ar, int n, int* aranswer, int &j)
{
	bool right = 1;
	int* result = max_multiply(ar, 10);
	for (int i = 0; i<3; i++)
	{
		if (result[i] != aranswer[i])
			right = 0;
	}
	if (right)
		cout << "Test " << j << " work propelry" << endl;
	else
		cout << "Test " << j << " work with mistakes." << endl;
	j++;
}

void test()
{
	int j = 1;
	int ar1[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int n1 = 9;
	int ar1answer[3] = { 9, 8, 7 };
	testitself(ar1, n1, ar1answer, j);
	int ar2[10] = { 10, 20, 40, 50, 44, 100 };
	int n2 = 6;
	int ar2answer[3] = { 100, 50, 44 };
	testitself(ar2, n2, ar2answer, j);
	int ar3[10] = { 100, 501, 99, 1, 2, 3, 20 };
	int n3 = 7;
	int ar3answer[3] = { 501, 100, 99 };
	testitself(ar3, n3, ar3answer, j); 
	int ar4[10] = { 10, 12, 13, 14, 20, 29, 1, 10 };
	int n4 = 8;
	int ar4answer[3] = { 29, 20, 14 };
	testitself(ar4, n4, ar4answer, j);
	int ar5[10] = { -10, 12, 13, -140, 20, 29, -110, 80 };
	int n5 = 8;
	int ar5answer[3] = { 80, -140, -110 };
	testitself(ar5, n5, ar5answer, j);
}

int main()
{
	test();
	getchar();
	getchar();
	return 0;
}