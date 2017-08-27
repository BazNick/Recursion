#include <iostream>

using namespace std;

int numberofMoves = 0;

void towerofHanoi(int discs, char peg1, char peg2, char peg3)
{
	numberofMoves++;
	if (discs == 1)
	{
		cout << "Move " << "disc " << discs << " from " << peg1 << " to " << peg3 << endl;
	}
	else
	{
		towerofHanoi(discs - 1, peg1, peg3, peg2);
		cout << "Move " << "disc " << discs << " from " << peg1 << " to " << peg3 << endl;
		towerofHanoi(discs - 1, peg2, peg1, peg3);
	}
}

int main()
{
	towerofHanoi(3, 'A', 'B', 'C');
	cout << "It took " << numberofMoves << " move\n";

	cin.ignore();
	cin.get();
	return 0;
}
