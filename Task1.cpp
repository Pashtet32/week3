#include "iostream"
#include "algorithm"

using namespace std;


int** multiply_matrix(int** matrix_a, int** matrix_b, int n_a, int m_a, int n_b, int m_b)
{
	int** matrix_c;
	int n_c = n_a;
	int m_c =  m_b;
	matrix_c = new int*[n_c];
	for (int i = 0; i < n_c; i++)
	{
		matrix_c[i] = new int [m_c];
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

int main()
{
	int **matrix_a, **matrix_b;
	int n_a, n_b, m_a, m_b;

	cout << "Enter first matrix"<<endl;
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

	cout << "Enter second matrix"<<endl;
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
	}
	getchar();
	getchar();
	return 0;
}