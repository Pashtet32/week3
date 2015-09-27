#include "iostream"
#include "algorithm"

using namespace std;

int max_multiply(int* array, int n)
{
	sort(array, array + n);
	if (array[n-1] <= 0)
	{
		return array[n-1] * array[n-2] * array[n-3];
	}
	if (array[0] > 0)
	{
		return array[n-1] * array[n-2] * array[n-3];
	}
	return array[n-1]*max(array[0]*array[1], array[n-2]*array[n-3]);

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
	int result = max_multiply(array, n);
	cout << "The answer is" << endl;
	cout << result;
	getchar();
	getchar();
	return 0;
}