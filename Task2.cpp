#include "iostream"
#include "algorithm"

using namespace std;

int* max_multiply(int* array, int n)
{
	int* res;
	res = new int[3];
	sort(array, array + n);
	if (array[n-1] <= 0)
	{
		res[0] = array[n - 1];
		res[1] = array[n - 2];
		res[2] = array[n-3];
	}
	if (array[0] > 0)
	{
		res[0] = array[n - 1];
		res[1] = array[n - 2];
		res[2] = array[n - 3];
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

int main()
{
	int *array;
	int n;
	cout << "Enter the array" << endl;
	cin >> n;
	array = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> array[i];
	}
	int* result = max_multiply(array, n);
	cout << "The answer is" << endl;
	for (int i = 0; i < 3; i++)
		cout << result[i] << " ";
	cout << endl;
	getchar();
	getchar();
	return 0;
}