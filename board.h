#include <iostream>

using namespace std;


class Board {
	friend class Divisions;

public:
	//int size = 10;
	int height = 10;
	int width = 10;
	int** tab;
	int** tmp;

public:
	Board();
	Board(int height, int width);

	int** create_board(int height, int width);
	void clear();
	void display();
};
