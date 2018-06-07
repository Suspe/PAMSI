#include <iostream>
#include <math.h>
#include <stdio.h>
#include <cstdlib>

void plansza(char t[], int rozmiar, int n); //funkcja tworzy tablice charow i rysuje ja w odpowiedniej postaci coutami

bool remis(char t[], bool mm, int rozmiar, int n);  //funkcja sprawdzajaca poszczegolne komorki tablicy czy nie sa spacjami, jesli zadna nie jest - jest remis

bool wygrana(char t[], char g, bool mm, int rozmiar, int n, int ile);   //obszerna funkcja sprawdzajaca ciag znakow na kazdej prostej " - | \ / " - sprawdzanie wygranej

int minimax(char t[], char gracz, int rozmiar, int n, int ile, int alpha, int beta, int glebokosc);   // algorytm symulujacy sztuczna inteligencje - do 6 krokow w przod

int komputer(char t[], int rozmiar, int n, int ile);    // funkcja wykorzystujaca powyzszy algorytm podejmujaca decyzje odnosnie ruchu komputera

void ruch(char t[], char &gracz, int rozmiar, int n, int ile);  // funkcja sluzaca do wykonania ruchu zarowno w przypadku gracza jak i komputera
