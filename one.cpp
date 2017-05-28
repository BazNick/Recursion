#include <iostream>

using namespace std;

int bleah(int x, int y)
{
	if (y == 0)
	{
		return 1;
	}
	
	return x*bleah(x, y - 1);
}

int main() 
{
	cout << bleah(2,5);

	cin.get();
	cin.ignore();
	return 0;
}
