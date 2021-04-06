#include <iostream>
#include <ctime>
#include <cstdlib>


using namespace std;


class Divisions {
	friend class Board;
public:
	int number = 10;
	int w = 0;
	int h = 0;
	int* neighboors = new int[10];


public:
	Divisions();
	Divisions(Board& b);
	Divisions(int number, int height, int width, Board& b);
	void make(Board& b);
	void set(Board& b);
	int count(Board& b, int i, int j);
	void check(int n, int w, int h);
	void change(Board& b, int x, int move);
};
