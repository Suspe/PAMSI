#include <iostream>
#include <math.h>
#include <stdio.h>
#include <cstdlib>
#include "alg.h"

using namespace std;


int main()
{
	int rozmiarPlanszy, ile, n;
	char gra;
	cout << "Witaj!" << endl;
	cout << "Nacisnij dowolny przycisk aby rozpoczac rozgrywke " << endl;
	getchar();
	system("cls");
	while(1){

	cout << "Podaj rozmiar planszy " << endl;
	cin >> rozmiarPlanszy;
	system("cls");
	cout << "Podaj ilosc znakow ustawionych w rzedzie potrzebnych do wygranej: " << endl;
	cin >> ile;
	n = rozmiarPlanszy * rozmiarPlanszy;

	char *t = new char[n+1], gracz;
	for (int i = 1; i <= n; i++)
		t[i] = ' ';
	gracz = 'O';
	while (1)
	{
		ruch(t, gracz, rozmiarPlanszy, n, ile);
		plansza(t, rozmiarPlanszy, n);
		if (wygrana(t, 'X', false, rozmiarPlanszy, n, ile) ||
			wygrana(t, 'O', false, rozmiarPlanszy, n, ile) ||
			remis(t, false, rozmiarPlanszy, n))
			break;
	}
	cout << "KONIEC GRY, Czy chcesz zagrac ponownie? (T/N)" << endl;
	cin >> gra;
	system("cls");
	if(!(gra == 'T' || gra =='t')) break;
}
	cout << "Gra skonczona, do zobaczenia" << endl;
	system("pause");
}
