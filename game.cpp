#include <iostream>
#include <cstdlib>
#include <ctime>
#include "game.h"

using namespace std;

#define size 12

Game::Game(int l, int move, int n)
{
	this->l = l;
	this->move = move;
	this->n = n;
	
}

void Game::check(int l)
{
	if ((n * n) <= l)
	{
		cout << endl << "Liczba zywych komorek jest wieksza niz dostepna tablica!" << endl;
		system("PAUSE");
	}
}

void Game::display(int tab[size][size])
{
	for (int i = 1; i <= n; i++)
	{
		cout << endl;
		for (int j = 1; j <= n; j++)
		{
			cout << tab[i][j] << "  ";
		}
	}
	cout << endl;
}

void Game::make(int l, int tab[size][size])
{
	int counter = 0;
	int a = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (counter < l)
			{
				tab[i][j] = (rand() % 2);
				if (tab[i][j] == 1)
					counter++;
			}

			else
				return;
		}
	}
}

int Game::count(int tab[size][size], int i, int j)
{
	int counter = 0;

	if (tab[i][j - 1] == 1) counter++;
	if (tab[i][j + 1] == 1) counter++;
	if (tab[i + 1][j] == 1) counter++;
	if (tab[i - 1][j] == 1) counter++;
	if (tab[i - 1][j - 1] == 1) counter++;
	if (tab[i + 1][j - 1] == 1) counter++;
	if (tab[i - 1][j + 1] == 1) counter++;
	if (tab[i + 1][j + 1] == 1) counter++;
	return counter;
}

void Game::change(int tab[size][size])
{
	int** tmp = new int* [size];
	for (int i = 0; i < size; i++)
	{
		tmp[i] = new int[size];
		for (int j = 0; j < size; j++)
		{
			tmp[i][j] = tab[i][j];
		}
	}

	int x = 0;
	int aa = 0;
	cout << endl << " Rozpoczynamy. " << " Liczba ruchow: " << move << endl;
	while (x < move)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				int c = count(tab, i, j);
				if (tmp[i][j] == 0) //martwy
				{
					if (c == 3) //o¿ywienie
					{
						tmp[i][j] = 1;
						aa++;
					}

				}
				if (tmp[i][j] == 1) // zywy
				{
					if (c < 2)
					{
						tmp[i][j] = 0; // umiera z samotnosci
						aa++;
					}
					if (c >= 4)
					{
						tmp[i][j] = 0; // umiera z przeludnienia
						aa++;
					}

				}

			}

		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				tab[i][j] = tmp[i][j];
			}
		}

		if (aa == 0)
		{
			cout << endl << "Nikt juz nie ozyje ani nie umrze. Ilosc ruchow: " << x << endl;
			return;
		}
		else
		{
			aa = 0;
		}
		x++;
		display(tab);
	}
	delete[] tmp;

}