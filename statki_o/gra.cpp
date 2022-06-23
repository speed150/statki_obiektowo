#include "klasy.h"
#include "SFML/Graphics.hpp"
#include <iostream>
#include <random>
#include <ctime> 
using namespace std;
int trafienia, hitx, hity, tk;
int statek;
bool trafiony{ false };
bool k0{ false }, k1{ false }, k2{ false }, k3{ false }, trafionyk{ false };

void ai(plansza& gracz, plansza& g1, int poziom) {
	mt19937 generator(time(nullptr));
	uniform_int_distribution<int> x(0, 9);
	uniform_int_distribution<int> y(0, 9);
	uniform_int_distribution<int> k(0, 3);
	bool hit = true;
	int wiersz{ 0 }, kolumna{ 0 }, kierunek{};

	if (trafienia == 20) {
		cout << "przegrales";
		komunikat("przegrales", 100, 100);

	}
	else {
		while (hit == true) {
			wiersz = x(generator);
			kolumna = y(generator);
			//przerwanie szukania w pobli簑
			if (statek == gracz.board[hitx][hity]) {
				if (poziom == 3) {
					brzegi(hitx, hity, g1, 4 - statek);
					

				}
				trafiony = false;
				statek = 1;
				trafionyk = false;
				k0 = false;
				k1 = false;
				k2 = false;
				k3 = false;
			}
			if (trafiony == true && hit == true) {//po trafieniu szukaj kierunku


				kierunek = k(generator);
				if (trafionyk == true) {//kontynuacja kierunku
					kierunek = tk;
				}
				if (kierunek == 0 && (k0 == false || statek > 1)) {//lewo 
					if (hity - 1 > -1 && g1.board[hitx][hity - 1] == 0) {//zostaje w tablicy i nie by這 powt鏎ek
						if (gracz.board[hitx][hity - 1] == 0) {//pud這
							g1.board[hitx][hity - 1] = -1;
							k0 = true;
							hit = false;

						}
						else {//trafienie
							g1.board[hitx][hity - 1] = gracz.board[hitx][hity - 1];
							trafionyk = true;
							tk = kierunek;
							statek++;
							trafienia++;
							hity -= 1;//przesuni璚ie

						}
					}
					else if (((g1.board[hitx][hity - 1] == -1 && hity - 1 > -1) || hity - 1 == -1) && trafionyk == true) {//iana / znana warto(pud這)
						k0 = true;
						kierunek = 2;
						tk = kierunek;

					}
					else if (trafionyk == true && g1.board[hitx][hity - 1] == g1.board[hitx][hity]) {//znana warto(statek
						if (hity > 0) {
							hity -= 1;
						}
						tk = kierunek;
					}
				}
				else if (kierunek == 1 && (k1 == false || statek > 1)) {//g鏎a 
					if (hitx - 1 > -1 && g1.board[hitx - 1][hity] == 0) {
						if (gracz.board[hitx - 1][hity] == 0) {//pud這
							g1.board[hitx - 1][hity] = -1;
							k1 = true;
							hit = false;

						}
						else {//trafienie
							g1.board[hitx - 1][hity] = gracz.board[hitx - 1][hity];
							trafionyk = true;
							tk = kierunek;
							statek++;
							trafienia++;
							hitx -= 1;

						}
					}
					else if (((g1.board[hitx - 1][hity] == -1 && hity - 1 > -1) || hitx - 1 == -1) && trafionyk == true) {//iana / znana warto(pud這)
						k0 = true;
						kierunek = 3;
						tk = kierunek;

					}
					else if (trafionyk == true && g1.board[hitx - 1][hity] == g1.board[hitx][hity]) {//znana warto(statek
						if (hitx > 0) {
							hitx -= 1;
						}
						tk = kierunek;

					}
				}
				else if (kierunek == 2 && (k2 == false || statek > 1)) {//prawo 
					if (hity + 1 < 10 && g1.board[hitx][hity + 1] == 0) {
						if (gracz.board[hitx][hity + 1] == 0) {//pud這
							g1.board[hitx][hity + 1] = -1;
							k2 = true;
							hit = false;

						}
						else {//trafienie
							g1.board[hitx][hity + 1] = gracz.board[hitx][hity + 1];
							trafionyk = true;
							tk = kierunek;
							statek++;
							trafienia++;
							hity += 1;//przesuni璚ie

						}
					}
					else if (((g1.board[hitx][hity + 1] == -1 && hity + 1 < 10) || hity + 1 == 10) && trafionyk == true) {//iana / znana warto(pud這)
						k2 = true;
						kierunek = 0;
						tk = kierunek;

					}
					else if (trafionyk == true && g1.board[hitx][hity + 1] == g1.board[hitx][hity]) {//znana warto(statek
						if (hity < 10) {
							hity += 1;
						}
						tk = kierunek;

					}
				}
				else if (kierunek == 3 && (k3 == false || statek > 1)) {//d馧 
					if (hitx + 1 < 10 && g1.board[hitx + 1][hity] == 0) {
						if (gracz.board[hitx + 1][hity] == 0) {//pud這
							g1.board[hitx + 1][hity] = -1;
							k3 = true;
							hit = false;

						}
						else {//trafienie5
							g1.board[hitx + 1][hity] = gracz.board[hitx + 1][hity];
							trafionyk = true;
							tk = kierunek;
							statek++;
							trafienia++;
							hitx += 1;

						}
					}
					else if (((g1.board[hitx + 1][hity] == -1 && hity + 1 < 10) || hitx + 1 == 10) && trafionyk == true) {//iana / znana warto(pud這)
						k3 = true;
						kierunek = 1;
						tk = kierunek;

					}
					else if (trafionyk == true && g1.board[hitx + 1][hity] == g1.board[hitx][hity]) {//znana warto(statek
						if (hitx < 10) {
							hitx += 1;
						}
						tk = kierunek;

					}
				}
			}
			else if (g1.board[wiersz][kolumna] == 0 && hit == true) {//nie powta瘸lne kom鏎ki i nie trafiono statku
				{
					if (gracz.board[wiersz][kolumna] != 0) {//trafienie w statek
						//豉twy bot
						if (poziom == 1) {
							g1.board[wiersz][kolumna] = gracz.board[wiersz][kolumna];
							trafienia++;

						}
						//edni bot i trudny 
						else {
							g1.board[wiersz][kolumna] = gracz.board[wiersz][kolumna];
							trafienia++;
							if (statek < g1.board[wiersz][kolumna]) {
								trafiony = true;
								hity = kolumna;
								hitx = wiersz;

							}
							else if (statek == g1.board[wiersz][kolumna] && poziom == 3) {
								hity = kolumna;
								hitx = wiersz;
								brzegi(wiersz, kolumna, g1, 0);

							}
						}
					}
					else {
						g1.board[wiersz][kolumna] = -1;
						hit = false;


					}
				}
			}
		}
	}

}
void player(plansza& plan, plansza& planw, gracz& grac) {//plansza niewidoczna(sprawdzana),plansza widoczna,gracz
	
	bool hit{ 1 }, pp{ 0 };
	int px{ 0 }, py{ 0 };
	while (hit == 1) {
		if (grac.punkty == 20) {
			hit = 0;
		}
		else {
			//cin.clear();
			//cout << "wybierz pole";
			komunikat("wybierz pole", 100, 100);
			//cin >> pozycja;

			string poleLitera = wyborPola(grac.nazwa, false, planw);
			int poleCyfra = numerPola();
			if (poleLitera[0] <= 'j' && poleLitera[0] >= 'a') {
				py = poleLitera[0] - 'a';
			}
			else if (poleLitera[0] <= 'J' && poleLitera[0] >= 'A') {
				py = poleLitera[0] - 'A';
			}
			else {
				cout << "nie ma takiego pola";
				komunikat("nie ma takiego pola", 80, 80);
			}
			if ((poleCyfra + 1) - 1 <= 9 && (poleCyfra + 1) - 1 >= 0) {
				px = (poleCyfra + 1) - 1;
			}
			else {
				cout << "nie ma takiego pola";
				komunikat("nie ma takiego pola", 80, 80);
			}
			if (planw.board[px][py] == 0) {
				if (plan.board[px][py] != 0) {
					planw.board[px][py] = 5;
					//cout << "trafiono " << plan.board[px][py] << ".masztowiec" << endl;
					komunikat("trafiono " + to_string(plan.board[px][py]) + "masztowiec", 90, 90);
					grac.punkty++;
					rysowanie_planszy();
					rysowanieStatkow(plan, planw);
				}
				else {
					planw.board[px][py] = -1;
					cout << "pudło";
					komunikat("pudlo", 60, 60);

					hit = 0;
					rysowanie_planszy();
					rysowanieStatkow(plan, planw);
				}
			}
			else {
				//cout << "już sprawdzałeś to pole";
				komunikat("już sprawdzałeś to pole", 60, 60);
			}
		}
	}
}
void gra(plansza& p1, plansza& p2, plansza& p1w, plansza& p2w, gracz& g1, gracz& g2,int Ai) {
	if (Ai !=0) {
		while (g1.punkty != 20 || g2.punkty != 20) {
			player(p2, p2w, g1);
			ai(p1, p1w, Ai);
			g2.punkty = trafienia;
		}
		if (g1.punkty == 20) {
			komunikat("wygrales", 200, 100);
		}
		else {
			komunikat("przegrales", 200, 100);
		}
	}
	if (Ai==0) {
		while (g1.punkty != 20 || g2.punkty != 20) {
			player(p2, p2w, g1);
			player(p1, p1w, g2);
		}
		if (g1.punkty == 20) {
			komunikat("wygrał gracz 1", 200, 100);
		}
		else {
			komunikat("wygrał gracz 2", 200, 100);
		}

	}
	czysc(p1);
	czysc(p2);
	czysc(p1w);
	czysc(p2w);

}