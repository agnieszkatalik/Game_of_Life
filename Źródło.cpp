//Agnieszka Talik 2021
#include <iostream>
#include <time.h>
#include <cstdlib>
#include "game.h"

using namespace std;

#define size 12

int main()
{
	srand(time(NULL));
	int tab[size][size] = { 0 };
	int l, move;
	int n = size - 2;
	cout << endl << "Podaj liczbe zywych komorek: ";
	cin >> l;
	cout << endl << "Podaj ilosc ruchow: ";
	cin >> move;

	Game g1(l, move, n);
	g1.check(l);
	g1.make(l, tab);
	g1.display(tab);
	g1.change(tab);

	return 0;
}
