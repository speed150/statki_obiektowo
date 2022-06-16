#pragma once
#include "funkcje.h"
class pole {
	int wartosc;//0-puste,1-1.mosztowiec,2-2.masztowiec...5-zatopiony
	int x, y;//miejsce w planszy
public:
	pole();
	pole(int w, int wiersz, int kolumna);
};
class gracz
{
};
class plansza {
	int board[10][10]{};
public:
	friend void wypisz(plansza pl);
	friend void ustaw_statki(plansza p1, int rodzaj);
	plansza();
};
class statek {
	int rozmiar;
	int trafienia;
	pole p1, p2, p3, p4;
public:
	statek(int r,pole a);
	statek(int r, pole a, pole b);
	statek(int r, pole a, pole b, pole c);
	statek(int r, pole a, pole b, pole c, pole d);

};
void ustaw_statki(plansza p1, int rodzaj);
void wypisz(plansza pl);
