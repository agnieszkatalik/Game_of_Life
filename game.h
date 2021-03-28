#pragma once
#define size 12
class Game
{
public:
	int l; // liczba zywych komorek
	int move; // liczba ruchow
	int n; // wielkosc tablicy

public:
	Game(int l, int move, int n);
	void check(int l);
	void display(int tab[size][size]);
	int count(int tab[size][size], int i, int j);
	void make(int l, int tab[size][size]);
	void change(int tab[size][size]);
};