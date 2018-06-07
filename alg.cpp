#include <iostream>
#include <math.h>
#include <stdio.h>
#include <cstdlib>
#include "alg.h"





using namespace std;

//*****************************************************************************************

void plansza(char t[], int rozmiar, int n)      // funkcja tworzaca i drukujaca tablice znakow tj. nasza plansze
{
	for (int i = 1; i <= n; i++)
	{

		if (i == 1)
		{
			for (int k = 1; k <= rozmiar; k++)
				cout << " " << k << "  ";
                cout << "K/W \n";
		}

            cout << " " << t[i] << " ";
		if (!(i % rozmiar))
			cout << "  " << (i / rozmiar);
		if (i % rozmiar)
			cout << "|";
		else if (i != n)
		{
			for (int j = 1; j <= rozmiar; j++)
			{
				if (j == 1)
					cout << "\n---+";
				else if (j == rozmiar)
					cout << "---\n";
				else
					cout << "---+";
			}
		}
		else cout << endl;
	}
}
//*****************************************************************************************


bool remis(char t[], bool drukujemy, int rozmiar, int n)
{

	for (int i = 1; i <= n; i++)
		if (t[i] == ' ')                // sprawdzanie wolnych miejsc - spacji
			return false;

	if (!drukujemy)                     // drukujemy tylko po wykonaniu ruchu, w algorytmie minimax - nie
	{
		getchar();
		system("cls");
		plansza(t, rozmiar, n);
		cout << "\nREMIS !!!\n\n";
	}
	return true;
}
//*****************************************************************************************
bool wygrana(char t[], char g, bool mm, int rozmiar, int n, int ile)
{
	char spr;
	int i, j, k;
	bool test = false;

	// sprawdzanie w pionie


	for (i = 1; i < n; i += rozmiar)
	{
		for (j = i; j <= (rozmiar - ile + i); j++)
		{
			for (k = j; k <= (j + ile - 1); k++)
			{
				spr = t[k];
				if (spr != g)
				{
					test = false;
					break;
				}
				else test = true;
			}
			if (test == true)
			{
				if (!mm)
				{
					getchar();
					system("cls");
					plansza(t, rozmiar, n);
					cout << "Wygrywa " << g << endl;
				}
				return true;
			}
		}
	}

    // sprawdzanie w poziomie


	for (i = 1; i <= rozmiar; i++)
	{
		for (j = i; j <= (i + n - (ile*rozmiar)); j += rozmiar)
        {

			for (k = j; k <= ((j + (ile - 1)*rozmiar)); k += rozmiar)
			{
				spr = t[k];
				if (spr != g)
				{
					test = false;
					break;
				}
				else test = true;
			}
			if (test == true)
			{
				if (!mm)
				{
					getchar();
					system("cls");
					plansza(t, rozmiar, n);
					cout << "Wygrywa " << g << endl;
				}
				return true;
			}
		}
	}


	// sprawdzanie po przekatnej

	for (i = ile; i <= n - ((ile - 1)*rozmiar); i++)
	{
		if (t[i] == g)
		{
			for (j = i; j <= (ile - 1)*rozmiar + i - ile + 1; j = j + rozmiar - 1)
			{
				spr = t[j];
				if (spr != g)
				{
					test = false;
					break;
				}
				else test = true;
			}
			if (test == true)
			{
				if (!mm)
				{
					getchar();
					system("cls");
					plansza(t, rozmiar, n);
					cout << "Wygrywa " << g << endl;
				}
				return true;
			}
		}
		if (i % rozmiar) {}
		else for (k = 1; k<ile; k++) i++;
	}

	// Sprawdzanie po drugiej przekatnej

	for (i = n - ((ile - 1)*rozmiar) - ile + 1; i >= 1; i--)
	{
		if (i % rozmiar) {}
		else for (k = 1; k<ile; k++) i--;

		if (t[i] == g)
		{
			for (j = i; j <= (ile - 1)*rozmiar + i + ile - 1; j = j + rozmiar + 1)
			{
				spr = t[j];
				if (spr != g)
				{
					test = false;
					break;
				}
				else test = true;
			}
			if (test == true)
			{
				if (!mm)
				{
					getchar();
					system("cls");
					plansza(t, rozmiar, n);
					cout << "Wygrywa " << g << endl;
				}
				return true;
			}
		}
	}
	return false;
}

//*****************************************************************************************





int minimax(char t[], char gracz, int rozmiar, int n, int ile, int alpha, int beta, int glebokosc)
{
	if(glebokosc == 6) return 0;

	if (wygrana(t, gracz, true, rozmiar, n, ile))
		return (gracz == 'X') ? 1 : -1;


	if (remis(t, true, rozmiar, n))
		return 0;

	gracz = (gracz == 'X') ? 'O' : 'X';

	int m, mmx = (gracz == 'O') ? 2 : -2;


	for (int i = 0; i <= n; i++)
		if (t[i] == ' ')
		{
			t[i] = gracz;
			m = minimax(t, gracz, rozmiar, n, ile, alpha, beta, glebokosc + 1);
			t[i] = ' ';
			if (((gracz == 'O') && (m < mmx)) || ((gracz == 'X') && (m > mmx)))
				mmx = m;
		}
	return mmx; // parametr wskazujacy wartosc danego scenariusza
}
//*****************************************************************************************



int komputer(char t[], int rozmiar, int n, int ile)
{
	int ruch, i, m, mmx;
	int alpha = 22222;
	int beta = -22222;

	mmx = -22222;
	m = -22222;
	for (i = 1; i <= n; i++)
		if (t[i] == ' ')
		{
			t[i] = 'X';
			m = minimax(t, 'X', rozmiar, n, ile,  alpha, beta, 0);
			t[i] = ' ';
			if (m > mmx)
			{
				mmx = m;
				ruch = i;
			}
			if (m == 1)
				return ruch;
		}
	return ruch;
}



//*****************************************************************************************


void ruch(char t[], char &gracz, int rozmiar, int n, int ile)
{
	int r, k, w;
	system("cls");
	plansza(t, rozmiar, n);
	if (gracz == 'O')
	{
		cout << "\n Twoj ruch: ";
		while (1)
		{
			cout << "\nNr Kolumny: ";
			cin >> k;
			if (k <= rozmiar && k > 0)
				break;
			cout << "\nPoza zakresem, sprobuj ponownie, kolumna:";
		}
		while (1)
		{
			cout << "Nr Wiersza: ";
			cin >> w;
			if (w <= rozmiar && w > 0)
				break;
            else
			cout << "\nPoza zakresem, sprobuj ponownie, wiersz :";
		}
		r = (rozmiar*w) + k - rozmiar;
	}
	else
	{
		r = komputer(t, rozmiar, n, ile);
	}
	cout << "---------------------------\n\n";
	if ((r >= 1) && (r <= n) && (t[r] == ' '))
		t[r] = gracz;
	else if (t[r] != ' ')
	{
    ruch(t, gracz, rozmiar, n, ile);

	}
	gracz = (gracz == 'O') ? 'X' : 'O';
}

//*****************************************************************************************

