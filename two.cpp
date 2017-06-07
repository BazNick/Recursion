#include <iostream>
#include <ctime>

using namespace std;

void bleah(int* arr1, int* arr2)
{
	cout << *arr2 << ' ';
	if (*arr1 == *arr2)
	{
		return;
	}
	*arr2--;
	return bleah(arr1, arr2);
}


int main()
{
	srand(time(NULL));
	int number = 0;
	cout << "Enter number: ";
	cin >> number;

	int* arr = new int[number];
	for (int i = 0; i <= number; i++)
	{
		arr[i] = i + rand();
		cout << arr[i] << ' ';
	}

	cout << endl;
	bleah(arr, arr + number);


	cin.get();
	cin.ignore();
	return 0;
}
