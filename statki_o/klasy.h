#pragma once
#include<string>
using namespace std;
class gracz;
class plansza {
	int board[10][10]{}; 
public:
	friend void rysowanieStatkow(plansza g1, plansza g2);
	friend void wypisz(plansza pl);
	friend void ustaw_statki(plansza& p1, int rodzaj);
	friend void brzegi(int x, int y, plansza& p, int l);
	friend void zeruj(plansza& p);
	friend void ai(plansza& gracz, plansza& g1, int poziom);
	friend void czysc(plansza& p);
	friend void gra(plansza& p1, plansza& p2, plansza& p1w, plansza& p2w, gracz& g1, gracz& g2);
	plansza();
	friend void player(plansza& plan, plansza& planw, gracz& grac);
};

void komunikat(string,int ,int);
class gracz
{
	int punkty ;
public:
	friend void gra(plansza& p1, plansza& p2, plansza& p1w, plansza& p2w, gracz& g1, gracz& g2);
	gracz();
	friend void player(plansza& plan, plansza& planw, gracz& gra);
};

void ustaw_statki(plansza &p1, int rodzaj);
void wypisz(plansza pl);
void brzegi(int x, int y, plansza &p, int l);
void zeruj(plansza &p);
void czysc(plansza& p);
void ai(plansza &gracz,plansza &g1,int poziom);
void rysowanieMenu();
void rysowanieStatkow(plansza p1, plansza p2);
void rysowanie_planszy();
void przypisyDoPlanszy();

void gra(plansza& p1, plansza& p2, plansza& p1w, plansza& p2w, gracz& g1, gracz& g2);

void ustawStakiMenu(string nazwaGracza, plansza& p1);
std::string wyborPola(string nazwaGracza, bool czyUstawiane);
int numerPola();
void player(plansza& plan, plansza& planw, gracz& grac);
