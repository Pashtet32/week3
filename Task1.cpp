#include "iostream"
#include "algorithm"

using namespace std;


int** multiply_matrix(int** matrix_a, int** matrix_b, int n_a, int m_a, int n_b, int m_b)
{
	int** matrix_c;
	int n_c = n_a;
	int m_c = m_b;
	matrix_c = new int*[n_c];
	for (int i = 0; i < n_c; i++)
	{
		matrix_c[i] = new int[m_c];
		for (int j = 0; j < m_c; j++)
		{
			matrix_c[i][j] = 0;
			for (int k = 0; k < m_a; k++)
			{
				matrix_c[i][j] += matrix_a[i][k] * matrix_b[k][j];
			}

		}
	}
	return matrix_c;
}

void testtest(int** matrix_1, int** matrix_2, int **matrix_4, int n_1, int m_1, int n_2, int m_2, int &c)
{
	int **result = multiply_matrix(matrix_1, matrix_2, n_1, m_1, n_2, m_2);
	bool thesame = 1;
	for (int i = 0; i < n_1; i++)
	{
		for (int j = 0; j < m_2; j++)
		{
			//cout << result[i][j] << " - " << matrix_4[i][j] << endl;
			if (result[i][j] != matrix_4[i][j])
				thesame = 0;
		}
	}
	if (thesame != 0)
		cout << "Test " << c << " was passed." << endl;
	else
		cout << "Test " << c << " was failed." << endl;
	c++;
}

void test()
{	
	int c = 1;
	int** matrix_1_1, **matrix_1_2, **matrix_1_4;
	int n_1_1 = 3, m_1_1 = 4, n_1_2 = 4, m_1_2 = 3;
	matrix_1_1 = new int*[n_1_1];
	matrix_1_1[0] = new int[m_1_1];
	matrix_1_1[1] = new int[m_1_1];
	matrix_1_1[2] = new int[m_1_1];
	matrix_1_1[0][0] = 1;
	matrix_1_1[0][1] = 2;
	matrix_1_1[0][2] = 3;
	matrix_1_1[0][3] = 4;
	matrix_1_1[1][0] = 10;
	matrix_1_1[1][1] = 13;
	matrix_1_1[1][2] = 20;
	matrix_1_1[1][3] = 50;
	matrix_1_1[2][0] = 200;
	matrix_1_1[2][1] = 80;
	matrix_1_1[2][2] = 50;
	matrix_1_1[2][3] = 11;
	matrix_1_2 = new int*[n_1_2];
	matrix_1_2[0] = new int[m_1_2];
	matrix_1_2[1] = new int[m_1_2];
	matrix_1_2[2] = new int[m_1_2];
	matrix_1_2[3] = new int[m_1_2];
	matrix_1_2[0][0] = 20;
	matrix_1_2[0][1] = 4;
	matrix_1_2[0][2] = 3;
	matrix_1_2[1][0] = 8;
	matrix_1_2[1][1] = 7;
	matrix_1_2[1][2] = 40;
	matrix_1_2[2][0] = 50;
	matrix_1_2[2][1] = 1;
	matrix_1_2[2][2] = 3;
	matrix_1_2[3][0] = 100;
	matrix_1_2[3][1] = 11;
	matrix_1_2[3][2] = 6;
	matrix_1_4 = new int*[n_1_1];
	matrix_1_4[0] = new int[m_1_2];
	matrix_1_4[1] = new int[m_1_2];
	matrix_1_4[2] = new int[m_1_2];
	matrix_1_4[0][0] = 586;
	matrix_1_4[0][1] = 65;
	matrix_1_4[0][2] = 116;
	matrix_1_4[1][0] = 6304;
	matrix_1_4[1][1] = 701;
	matrix_1_4[1][2] = 910;
	matrix_1_4[2][0] = 8240;
	matrix_1_4[2][1] = 1531;
	matrix_1_4[2][2] = 4016;
	testtest(matrix_1_1, matrix_1_2, matrix_1_4, n_1_1, m_1_1, n_1_2, m_1_2, c);
	int** matrix_2_1, **matrix_2_2, **matrix_2_4;
	int n_2_1 = 4, m_2_1 = 2, n_2_2 = 2, m_2_2 = 5;
	matrix_2_1 = new int*[n_2_1];
	matrix_2_1[0] = new int[m_2_1];
	matrix_2_1[1] = new int[m_2_1];
	matrix_2_1[2] = new int[m_2_1];
	matrix_2_1[3] = new int[m_2_1];
	matrix_2_1[0][0] = 11;
	matrix_2_1[0][1] = 40;
	matrix_2_1[1][0] = 20;
	matrix_2_1[1][1] = 1;
	matrix_2_1[2][0] = 30;
	matrix_2_1[2][1] = 17;
	matrix_2_1[3][0] = 101;
	matrix_2_1[3][1] = 99;
	matrix_2_2 = new int*[n_1_2];
	matrix_2_2[0] = new int[m_2_2];
	matrix_2_2[1] = new int[m_2_2];
	matrix_2_2[0][0] = 20;
	matrix_2_2[0][1] = 21;
	matrix_2_2[0][2] = 22;
	matrix_2_2[0][3] = 100;
	matrix_2_2[0][4] = 34;
	matrix_2_2[1][0] = 35;
	matrix_2_2[1][1] = 3;
	matrix_2_2[1][2] = 4;
	matrix_2_2[1][3] = 20;
	matrix_2_2[1][4] = 19;
	matrix_2_4 = new int*[n_2_1];
	matrix_2_4[0] = new int[m_2_2];
	matrix_2_4[1] = new int[m_2_2];
	matrix_2_4[2] = new int[m_2_2];
	matrix_2_4[3] = new int[m_2_2];
	matrix_2_4[0][0] = 1620;
	matrix_2_4[0][1] = 351;
	matrix_2_4[0][2] = 402;
	matrix_2_4[0][3] = 1900;
	matrix_2_4[0][4] = 1134;
	matrix_2_4[1][0] = 435;
	matrix_2_4[1][1] = 423;
	matrix_2_4[1][2] = 444;
	matrix_2_4[1][3] = 2020;
	matrix_2_4[1][4] = 699;
	matrix_2_4[2][0] = 1195;
	matrix_2_4[2][1] = 681;
	matrix_2_4[2][2] = 728;
	matrix_2_4[2][3] = 3340;
	matrix_2_4[2][4] = 1343;
	matrix_2_4[3][0] = 5485;
	matrix_2_4[3][1] = 2418;
	matrix_2_4[3][2] = 2618;
	matrix_2_4[3][3] = 12080;
	matrix_2_4[3][4] = 5315;
	testtest(matrix_2_1, matrix_2_2, matrix_2_4, n_2_1, m_2_1, n_2_2, m_2_2, c);
}

int main()
{/*
	int **matrix_a, **matrix_b;
	int n_a, n_b, m_a, m_b;

	cout << "Enter first matrix" << endl;
	cin >> n_a >> m_a;
	matrix_a = new int*[n_a];
	for (int i = 0; i < n_a; i++)
	{
		matrix_a[i] = new int[m_a];
		for (int j = 0; j < m_a; j++)
		{
			cin >> matrix_a[i][j];
		}
	}

	cout << "Enter second matrix" << endl;
	cin >> n_b >> m_b;
	matrix_b = new int*[n_b];
	for (int i = 0; i < n_b; i++)
	{
		matrix_b[i] = new int[m_b];
		for (int j = 0; j < m_b; j++)
		{
			cin >> matrix_b[i][j];
		}
	}

	int **result = multiply_matrix(matrix_a, matrix_b, n_a, m_a, n_b, m_b);

	cout << "The answer is" << endl;
	for (int i = 0; i < n_a; i++)
	{
		for (int j = 0; j < m_b; j++)
		{
			cout << result[i][j] << " ";
		}
		cout << endl;
	}*/
	test();
	getchar();
	getchar();
	return 0;
}