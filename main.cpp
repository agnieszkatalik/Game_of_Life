//Agnieszka Talik, 2021
#include <iostream>
#include <memory>

#include "game.h"
#include "board.h"
#include "divisions.h"

#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	srand(time(NULL));

	int x = 0;
	cout << "Select game version: " << endl << "1) 10x10 board, 10 living cells, 5 moves, random places of life. " << endl << "2) You decide." << endl;
	cin >> x;

	if (x == 1) {
		unique_ptr < Game > g1(new Game());
	}
	if (x == 2) {
		int n = 0;
		cout << "Enter the number of generations (movements): " << endl;
		cin >> n;
		unique_ptr < Game > g1(new Game(n));
	}
	else {
		return 0;
	}


	system("PAUSE");
	return 0;
}