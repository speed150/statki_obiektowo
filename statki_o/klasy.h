#pragma once
#include<string>
using namespace std;
class gracz;
class plansza {
	int board[10][10]{};
public:
	//friend void rysowanieStatkow(plansza g1, plansza g2);
	friend void wypisz(plansza pl,plansza p2);
	friend void ustaw_statki(plansza& p1, int rodzaj);
	friend void brzegi(int x, int y, plansza& p, int l);
	friend void zeruj(plansza& p);
	friend void ai(plansza& gracz, plansza& g1, int poziom);
	friend void czysc(plansza& p);
	friend void gra(plansza& p1, plansza& p2, plansza& p1w, plansza& p2w, gracz& g1, gracz& g2,int Ai);
	plansza();
	friend void player(plansza& g1, plansza& plan, plansza& planw, gracz& grac);
	friend void menu();
};

//void komunikat(string, int, int);
class gracz
{
	int punkty;
public:
	string nazwa;
	friend void gra(plansza& p1, plansza& p2, plansza& p1w, plansza& p2w, gracz& g1, gracz& g2,int Ai);
	gracz();
	friend void player(plansza& g1, plansza& plan, plansza& planw, gracz& grac);
	friend void menu();
};

void ustaw_statki(plansza& p1, int rodzaj);
void wypisz(plansza pl,plansza p2);
void brzegi(int x, int y, plansza& p, int l);
void zeruj(plansza& p);
void czysc(plansza& p);
void ai(plansza& gracz, plansza& g1, int poziom);
void menu();
//void rysowanieMenu();
//void rysowanieStatkow(plansza p1, plansza p2);
//void rysowanie_planszy();
//void przypisyDoPlanszy();



//bool ustawStakiMenu(string nazwaGracza, plansza& p1, int iloscGraczyDoUtworzenia);
//std::string wyborPola(string nazwaGracza, bool czyUstawiane, plansza pl);
//int numerPola(plansza pl);
void player(plansza& g1, plansza& plan, plansza& planw, gracz& grac);
void gra(plansza& p1, plansza& p2, plansza& p1w, plansza& p2w, gracz& g1, gracz& g2,int Ai);
