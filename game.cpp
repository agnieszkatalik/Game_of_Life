#include <iostream>
#include <memory>

#include "game.h"
#include "board.h"
#include "divisions.h"


using namespace std;

Game::Game() {
	//Board b1;
	unique_ptr < Board > b1(new Board());
	unique_ptr < Divisions > d1(new Divisions(*b1));

	int x = 0;
	cout << endl << "We begin. " << "Number of Moves: " << move << endl << endl;;
	
	int counter = move;

		d1->change(*b1, x, move);
}


Game::Game(int move)
{
	int w = 0;
	int h = 0;
	int n = 0;

	cout << "Enter the width of the board: " << endl;
	cin >> w;
	cout << "Enter the length of the board: " << endl;
	cin >> h;

	//Board b2(w, h);
	unique_ptr < Board > b2(new Board(w, h));

	cout << "Enter the number of living cells: " << endl;
	cin >> n;

	unique_ptr < Divisions > d2(new Divisions(n, w, h, *b2));

	int x = 0;
	cout << endl << "We're getting started. " << "Number of moves: " << move << endl << endl;;

	int counter = move;

		d2->change(*b2, x, move);
		cout << endl;
}

