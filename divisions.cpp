#include <iostream>
#include <ctime>
#include <cstdlib>
#include <stdlib.h>

#include "game.h"
#include "board.h"
#include "divisions.h"

using namespace std;

Divisions::Divisions() {
}

Divisions::Divisions(Board& b) {
	make(b);
	b.display();
}

Divisions::Divisions(int n, int height, int width, Board& b) {
	number = n;
	check(n, height, width);
	set(b);
}

void Divisions::make(Board& b) {
	int counter = 0;

	for (int i = 1; i <= b.height; i++)
	{
		for (int j = 1; j <= b.width; j++)
		{
			if (counter < number) {
				b.tab[i][j] = (rand() % 2);
				if (b.tab[i][j] == 1) {
					counter++;
				}
			}
			else {
				return;
			}
		}
	}
}

void Divisions::set(Board& b) {

	cout << "Enter the coordinates of living cells, and confirm each with enter (first row number, second column number): " << endl;

	for (int i = 0; i < number; i++) {
		cout << "Coordinates for " << i + 1 << " life: " << endl;
		cin >> h;
		cin >> w;
		b.tab[h][w] = 1;
	}
	b.display();
}

void Divisions::check(int n, int h, int w) {
	if ((h * w) <= number) {
		cout << endl << "The number of living cells is greater than the available table!" << endl;
		exit(0);
	}
};

int Divisions::count(Board& b, int i, int j) {

	int counter = 0;
	
	for (int k = -1; k < 2; k++) {
		for (int l = -1; l < 2; l++) {
			if ((k == 0) && (l == 0)) {
			}
			else{
				if (b.tab[i + k][j + l] == 1) {
					counter++;
				}
			}
		}
	}
	return counter;
}

void Divisions::change(Board& b, int x, int move) {
	while (x < move) {
		cout << "Move: " << x + 1 << endl;

		int aa = 0;

		for (int i = 0; i < (b.height + 2); i++)
		{
			for (int j = 0; j < (b.width + 2); j++)
			{
				b.tmp[i][j] = b.tab[i][j];
			}
		}

		int c = 0;

		for (int i = 1; i <= b.height; i++)
		{
			for (int j = 1; j <= b.width; j++)
			{
				c = 0;
				c = count(b, i, j);

				if (b.tmp[i][j] == 0) //dead
				{
					if (c == 3) // revival
					{
						b.tmp[i][j] = 1;
						aa++;
					}
				}
				if (b.tmp[i][j] == 1) // alive
				{
					if (c < 2)
					{
						b.tmp[i][j] = 0; // he dies of loneliness
						aa++;
					}
					if (c >= 4)
					{
						b.tmp[i][j] = 0; // he is dying of overpopulation
						aa++;
					}
				}
			}
		}
		for (int i = 1; i <= b.height; i++) {
			for (int j = 1; j <= b.width; j++) {
				b.tab[i][j] = b.tmp[i][j];
			}
		}

		if (aa == 0)
		{
			cout << endl << "Nobody will come back or die anymore. Number of movements: " << x << endl;
			exit(0);
		}
		else
		{
			aa = 0;
		}

		b.display();
		x++;
		cout << endl;
	}
}
