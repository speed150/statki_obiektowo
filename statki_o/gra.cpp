#include "klasy.h"
#include <iostream>
#include <random>
#include <ctime> 
using namespace std;
int trafienia,hitx,hity,tk;
int statek;
bool trafiony{ false };
bool k0{ false }, k1{ false }, k2{ false }, k3{ false }, trafionyk{ false };

void ai(plansza &gracz,plansza &g1,int poziom) {
	mt19937 generator(time(nullptr));
	uniform_int_distribution<int> x(0, 9);
	uniform_int_distribution<int> y(0, 9);
	uniform_int_distribution<int> k(0, 3);
	bool hit = true;
	int wiersz{ 0 }, kolumna{ 0 }, kierunek{};

	if (trafienia == 20) {
		cout << "przegrales";

	}
	else {
		while (hit == true) {
			wiersz = x(generator);
			kolumna = y(generator);
			//przerwanie szukania w pobli簑
			if (statek == gracz.board[hitx][hity]) {
				if (poziom == 3) {
					brzegi(hitx, hity, g1, 4-statek);
					wypisz(g1);
					rysowanie_planszy();
					przypisyDoPlanszy();
					rysowanieStatkow(gracz, g1);

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
					else if (trafionyk == true && g1.board[hitx][hity + 1] ==g1.board[hitx][hity]) {//znana warto(statek
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
							if (statek <g1.board[wiersz][kolumna]) {
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
	wypisz(g1);
	rysowanie_planszy();
	przypisyDoPlanszy();
	rysowanieStatkow(gracz, g1);
}
void player(plansza& plan, plansza& planw, gracz& grac) {//plansza niewidoczna(sprawdzana),plansza widoczna,gracz
	char pozycja[3]{};
	bool hit{ 1 }, pp{ 0 };
	int px{ 0 }, py{ 0 };
	while (hit == 1) {
		if (grac.punkty == 20) {
			hit = 0;
		}
		else {
			cin.clear();
			cout << "wybierz pole";
			cin >> pozycja;
			if (pozycja[0] <= 'j' && pozycja[0] >= 'a') {
				py = pozycja[0] - 'a';
			}
			else if (pozycja[0] <= 'J' && pozycja[0] >= 'A') {
				py = pozycja[0] - 'A';
			}
			else {
				cout << "nie ma takiego pola";
			}
			if (atoi(pozycja + 1) - 1 <= 9 && atoi(pozycja + 1) - 1 >= 0) {
				px = atoi(pozycja + 1) - 1;
			}
			else {
				cout << "nie ma takiego pola";
			}
			if (planw.board[px][py] == 0) {
				if (plan.board[px][py] != 0) {
					planw.board[px][py] = 5;
					cout << "trafiono " << plan.board[px][py] << ".masztowiec" << endl;
					grac.punkty++;
				}
				else {
					planw.board[px][py] = -1;
					cout << "pudło";
					hit = 0;
				}
			}
			else {
				cout << "już sprawdzałeś to pole";
			}
		}
	}
}
