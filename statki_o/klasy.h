#pragma once
class pole {
	int wartosc;//0-puste,1-1.mosztowiec,2-2.masztowiec...5-zatopiony
	int x, y;//miejsce w planszy
public:
	pole();
	pole(int w, int wiersz, int kolumna);
	~pole() {};
};
class gracz
{
};
class plansza {
	int board[10][10]{};
public:
	friend void wypisz(plansza pl);
	friend void ustaw_statki(plansza &p1, int rodzaj);
	friend void brzegi(int x, int y, plansza &p, int l);
	friend void zeruj(plansza &p);
	friend void ai(plansza gracz,int poziom);
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
void ustaw_statki(plansza &p1, int rodzaj);
void wypisz(plansza pl);
void brzegi(int x, int y, plansza &p, int l);
void zeruj(plansza &p);
void ai(plansza gracz,int poziom);
void rysowanieMenu();
void rysowanieStatkow(int tab[10][10], int tab1[10][10]);
void rysowanie_planszy();
void przypisyDoPlanysz();
