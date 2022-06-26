#include "klasy.h"
#include "SFML/Graphics.hpp"
#include <iostream>
#include <random>
#include <ctime> 
#include <Windows.h>
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
							//return;

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
	char poleLitera[3]{};
	bool hit{ 1 }, pp{ 0 };
	int px{ 0 }, py{ 0 };
	while (hit == 1) {
		
		if (grac.punkty == 20) {
			hit = 0;
		}
		else {
			wypisz(plan, planw);
			std::cin.clear();
			std::cout << "\nwybierz pole"<<endl;
			cin >> poleLitera;

			if (poleLitera[0] <= 'j' && poleLitera[0] >= 'a') {
				py = poleLitera[0] - 'a';
			}
			else if (poleLitera[0] <= 'J' && poleLitera[0] >= 'A') {
				py = poleLitera[0] - 'A';
			}
			else {
				cout << "nie ma takiego pola" << endl;;
			}
			if (atoi(poleLitera + 1) - 1 <= 9 && atoi(poleLitera + 1) - 1 >= 0) {
				px = atoi(poleLitera + 1) - 1;
			}
			else {
				cout << "nie ma takiego pola"<<endl;
			}
			if (planw.board[px][py] == 0) {
				if (plan.board[px][py] != 0) {
					planw.board[px][py] = 5;
					cout << "trafiono " << plan.board[px][py] << ".masztowiec" << endl;
					
					grac.punkty++;
				
				}
				else {
					planw.board[px][py] = -1;
					cout << "pudło" << endl;
					//return;

					hit = 0;
					
				}
			}
			else {
				cout << "już sprawdzałeś to pole"<<endl;
			
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
			wypisz(p1, p1w);
		}
		if (g1.punkty == 20) {
		}
		else {
			
		}
	}
	if (Ai==0) {
		while (g1.punkty != 20 || g2.punkty != 20) {
			player(p2, p2w, g1);
			wypisz(p1, p1w);

			player(p1, p1w, g2);
			wypisz(p1, p1w);

		}
		if (g1.punkty == 20) {
			
		}
		else {
		}


	}
	czysc(p1);
	czysc(p2);
	czysc(p1w);
	czysc(p2w);

}
void menu() {
	int poziom = 0;
	bool war1{ 0 }, war2{ 0 }, bot{ 0 };
	int m1{}, m2{}, m3{};//poziomy menu
	char a[1]{};
	plansza gr1, gr2, gracz1widoczne, gracz2widoczne;
	gracz g1, g2;
	do {
		zeruj(gr1);
		zeruj(gr2);
		
		zeruj(gracz1widoczne);
		zeruj(gracz2widoczne);

		system("cls");
		cout << "statki" << endl;
		cout << "1 gra z komputerem" << endl;
		cout << "2 gra dla 2 graczy" << endl;
		cout << "3 wyjscie" << endl;

		cin >> a;
		m1 = atoi(a);
		if (m1 > 3 || m1 < 1) {
			cout << "podales zla liczbe"<<endl;
			Sleep(500);
			
		}

		if (m1 == 1) {
			do {
				system("cls");
				ustaw_statki(gr2, 1);
				war2 = 1;
				cout << "wybierz poziom" << endl;
				cout << "1 latwy" << endl;
				cout << "2 normalny" << endl;
				cout << "3 trudny" << endl;
				cout << "4 menu" << endl;
				cin >> a;
				m2 = atoi(a);
				if (m2 >= 1 && m2 < 4) {
					poziom = m2;
					bot = 1;
				}
				else if (m2 == 4) {
					bot = 0;
					war2 = 0;
				}
				else {
					cout << "podales zla liczbe"<<endl;
					Sleep(500);
				}
				//prawidłowo wybrano poziom
				if (poziom != 0) {
					while (m3 != 3) {
						system("cls");
						cout << "gracz 1" << endl;
						cout << "1 stworz plansze sam" << endl;
						cout << "2 stworz plansze automatycznie" << endl;
						cout << "3 menu" << endl;
						cin >> a;
						m3 = atoi(a);
						if (m3 == 1) {
							ustaw_statki(gr1,2);
							war1 = 1;
							m3 = 3;
							m2 = 4;
						}
						else if (m3 == 2) {
							ustaw_statki(gr1,1);
							war1 = 1;
							m3 = 3;
							m2 = 4;
						}
						else if (m3 == 3) {
							m2 = 4;
							bot = 0;
							war1 = 0;
							war2 = 0;
						}
						else {
							cout << "podales zla liczbe" << endl;
							Sleep(500);
						}
					}
				}
			} while (m2 != 4);
		}
		else if (m1 == 2) {
			do {
				system("cls");
				cout << "gracz 1" << endl;
				cout << "1 stworz plansze sam" << endl;
				cout << "2 stworz plansze automatycznie" << endl;
				cout << "3 menu" << endl;
				cin >> a;
				m2 = atoi(a);
				if (m2 == 1) {
					ustaw_statki(gr1,2);
					war1 = 1;
				}
				else if (m2 == 2) {
					ustaw_statki(gr1,1);
					war1 = 1;
				}
				else if (m2 == 3) {
					war1 = 0;
				}
				else {
					cout << "podales zla liczbe"<<endl;
				}
				if (war1 == 1) {
					system("cls");
					cout << "gracz 2" << endl;
					cout << "1 stworz plansze sam" << endl;
					cout << "2 stworz plansze automatycznie" << endl;
					cout << "3 menu" << endl;
					cin >> a;
					m2 = atoi(a);
					if (m2 == 1) {
						ustaw_statki(gr2,2);
						war2 = 1;
						m2 = 3;
					}
					else if (m2 == 2) {
						ustaw_statki(gr2,1);
						war2 = 1;
						m2 = 3;
					}
					else if (m2 == 3) {
						war1 = 0;
						war2 = 0;
					}
					else {
						cout << "podales zla liczbe"<<endl;
					}
				}
			} while (m2 != 3);
		}

		//gra
		if (war1 == 1 && war2 == 1) {
			if (bot == 1) {
				while (g1.punkty != 20 || g2.punkty != 20) {
					player(gr2, gracz2widoczne, g1);
					ai(gr1, gracz1widoczne, poziom);
					g2.punkty = trafienia;
				}
				if (g1.punkty == 20) {
					cout << "wygrales" << endl;
					Sleep(500);
					trafienia = 0;
					g1.punkty = 0;
				}
				else {
					cout << "przegrales" << endl;
					Sleep(500);
					trafienia = 0;
					g1.punkty = 0;
				}
			}
			else {
				while (g1.punkty != 20 || g2.punkty != 20) {
					player(gr2, gracz2widoczne, g1);
					player(gr1, gracz2widoczne, g2);
				}
				if (g1.punkty == 20) {
					cout << "wygral gracz 1" << endl;
					Sleep(500);
					g1.punkty = 0;
					g2.punkty = 0;
				}
				else {
					cout << "wygral gracz 2" << endl;
					Sleep(500);
					g1.punkty = 0;
					g2.punkty = 0;
				}
			}

			cout << "1 graj dalej" << endl;
			cout << "2 zamknij" << endl;
			cin >> m3;
			if (m3 == 2) {
				exit(0);
			}
		}

	} while (m1 != 3);
}