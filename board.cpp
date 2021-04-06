#include <iostream>

#include "game.h"
#include "board.h"


using namespace std;

Board::Board() {
	tab = create_board(height, width);
	tmp = create_board(height, width);

}

Board::Board(int h, int w) {

	this->height = h;
	this->width = w;

	tab = create_board(height, width);
	tmp = create_board(height, width);

}

int** Board::create_board(int height, int width) {
	this->height = height;
	this->width = width;
	height += 2;
	width += 2;


	int** tab = new int* [width];
	for (int i = 0; i < height; ++i)
	{
		tab[i] = new int[height];
		for (int j = 0; j < width; ++j) {
			tab[i][j] = 0;
		}
	}
	return tab;
}

void Board::display()
{
	for (int i = 1; i <= height; i++)
	{
		cout << endl;
		for (int j = 1; j <= width; j++)
		{
			cout << tab[i][j] << "  ";
		}
	}
	cout << endl << endl;
}

void Board::clear() {
	for (int i = 1; i <= height; i++) {
		for (int j = 1; j <= width; ++j) {
			tmp[i][j] = 0;
		}
	}
}
