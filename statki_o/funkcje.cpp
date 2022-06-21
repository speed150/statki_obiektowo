#define NOMINMAX

#include "klasy.h"
#include "SFML/Graphics.hpp"

#include <iostream>
#include <random>
#include <ctime>
#include <Windows.h>
#include <string>
using namespace std;


void brzegi(int x, int y, plansza& p, int l) {
	if (p.board[x][y] <= 0) return;
	for (int i = -1; i < 2; i++) {
		for (int j = -1; j < 2; j++) {
			if (x + i >= 0 && y + j >= 0 && x + i < 10 && y + j < 10) {
				if (p.board[x + i][y + j] == 0) {
					p.board[x + i][y + j] = -1;
				}
			}
		}
	}
	l++;
	if (l < 4) {//failsave przed nieskoñczon¹ rekurencj¹
		if (x > 0) brzegi(x - 1, y, p, l);
		if (x < 9) brzegi(x + 1, y, p, l);
		if (y > 0) brzegi(x, y - 1, p, l);
		if (y < 9) brzegi(x, y + 1, p, l);
	}
}
void zeruj(plansza& p) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (p.board[i][j] == -1)
				p.board[i][j] = 0;
		}
	}
}
void czysc(plansza& p) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
				p.board[i][j] = 0;
		}
	}
}
void wypisz(plansza pl) {
	for (int a = 0; a < 10; a++) {
		for (int b = 0; b < 10; b++) {
			cout << pl.board[a][b] << " ";
		}
		cout << endl;
	}
	cout << endl;


}
void ustaw_statki(plansza& p1, int rodzaj) {
	//rysowanieMenu();

	int ilosc = 0;
	bool dust = 0;//dobrze ustawiony statek
	int wiersz, kolumna, kierunek;
	int dobre_pole = 1;
	if (rodzaj == 1) {// automatycznie
		mt19937 generator(time(nullptr));
		uniform_int_distribution<int> x(0, 9);//wiersz
		uniform_int_distribution<int> y(0, 9);//kolumna
		uniform_int_distribution<int> k(0, 3);//kierunek
		do {
			for (int dlugosc = 4; dlugosc > 0; dlugosc--) {
				for (int pow = 5; pow > dlugosc; pow--) {//powtórzenie statku
					dust = 0;
					while (dust == 0) {
						wiersz = x(generator);
						kolumna = y(generator);
						kierunek = k(generator);
						if (dlugosc == 1) {
							if (p1.board[wiersz][kolumna] == 0) {
								p1.board[wiersz][kolumna] = dlugosc;
								brzegi(wiersz, kolumna, p1, 3);
								dust = 1;
							}
						}
						if (p1.board[wiersz][kolumna] == 0) {
							switch (kierunek)
							{
							default:
								break;
							case 0:
								if (kolumna - dlugosc + 1 >= 0) {
									for (int st = 0; st < dlugosc; st++) {
										if (p1.board[wiersz][kolumna - st] == 0) {
											dobre_pole += 1;
										}
									}
									if (dobre_pole == dlugosc + 1) {
										for (int s = 0; s < dlugosc; s++) {
											p1.board[wiersz][kolumna - s] = dlugosc;
										}
										dobre_pole = 1;
										dust = 1;
										brzegi(wiersz, kolumna, p1, 0);
									}
									else {
										p1.board[wiersz][kolumna] = 0;
										dobre_pole = 1;
									}
								}
								else
								{
									dobre_pole = 1;
								}
								break;
							case 1:
								if (wiersz - dlugosc + 1 >= 0) {
									for (int st = 0; st < dlugosc; st++) {
										if (p1.board[wiersz - st][kolumna] == 0) {
											dobre_pole += 1;
										}
									}
									if (dobre_pole == dlugosc + 1) {
										for (int s = 0; s < dlugosc; s++) {
											p1.board[wiersz - s][kolumna] = dlugosc;
										}
										dobre_pole = 1;
										dust = 1;
										brzegi(wiersz, kolumna, p1, 0);
									}
									else {
										p1.board[wiersz][kolumna] = 0;
										dobre_pole = 1;
									}
								}
								else
								{
									dobre_pole = 1;
								}
								break;
							case 2:
								if (kolumna + dlugosc - 1 <= 9) {
									for (int st = 0; st < dlugosc; st++) {
										if (p1.board[wiersz][kolumna + st] == 0) {
											dobre_pole += 1;
										}
									}
									if (dobre_pole == dlugosc + 1) {
										for (int s = 0; s < dlugosc; s++) {
											p1.board[wiersz][kolumna + s] = dlugosc;
										}
										dobre_pole = 1;
										dust = 1;
										brzegi(wiersz, kolumna, p1, 0);
									}
									else {
										p1.board[wiersz][kolumna] = 0;
										dobre_pole = 1;
									}
								}
								else
								{
									dobre_pole = 1;
								}
								break;
							case 3:
								if (kolumna + dlugosc - 1 >= 9) {
									for (int st = 0; st < dlugosc; st++) {
										if (p1.board[wiersz + st][kolumna] == 0) {
											dobre_pole += 1;
										}
									}
									if (dobre_pole == dlugosc + 1) {
										for (int s = 0; s < dlugosc; s++) {
											p1.board[wiersz + s][kolumna] = dlugosc;
										}
										dobre_pole = 1;
										dust = 1;
										brzegi(wiersz, kolumna, p1, 0);
									}
									else {
										p1.board[wiersz][kolumna] = 0;
										dobre_pole = 1;
									}
								}
								else
								{
									dobre_pole = 1;
								}
								break;
							}
						}
					}
					ilosc += 1;
				}
			}
		} while (ilosc != 10);
	;
	przypisyDoPlanszy();
	rysowanie_planszy();
	rysowanieStatkow(p1, p1);
		zeruj(p1);
	}
	else {//przez gracza

	string pozycja{};
	int kierunek{};
	ilosc = 0;
					
	bool dkier = 0;
	int wiersz{}, kolumna{}, dobre_pole{ 1 };
	do {
		for (int dlugosc = 4; dlugosc > 0; dlugosc--) {
			for (int pow = 5; pow > dlugosc; pow--) {//powtórzenie statku
				dust = 0;
				while (dust == 0) {
					//cin.clear();
					cout << "ustaw " << dlugosc << ".masztowiec" << endl;
					wypisz(p1);
					rysowanie_planszy();
					przypisyDoPlanszy();
					rysowanieStatkow(p1, p1);
					pozycja = wyborPola("gracz", true);
					//cin >> pozycja;
					if (pozycja[0] <= 'J' && pozycja[0] >= 'A') {
						kolumna = pozycja[0] - 'A';
					}
					else {
						kolumna = pozycja[0] - 'a';
					}
					string a = pozycja.substr(1, 1);
					
					if (isdigit(pozycja[1])) {
						wiersz = stoi(pozycja.substr(1, 1)) - 1;
					}
					else {
						cout << "cos sie nie konwertuje";
					}
					dkier = 0;
					cin.clear();
					if ((wiersz <= 9 && wiersz >= 0) && (kolumna <= 9 && kolumna >= 0)) {
						if (p1.board[wiersz][kolumna] == 0) {
							if (dlugosc == 1) {
								p1.board[wiersz][kolumna] = dlugosc;
								brzegi(wiersz, kolumna, p1, 3);
								dust = 1;
							}
							else {
								cin.clear();
								cout << "wybierz kierunek 1lewo 2 góra 3 prawo 4 dol";
								pozycja = wyborPola("gracz", true);
								kierunek -= 1;
								string a = pozycja.substr(0, 1);

								if (isdigit(pozycja[1])) {
									kierunek = stoi(pozycja.substr(1, 1)) - 1;
								}
								else {
									cout << "nie ma takiego kierunku";
								}
								switch (kierunek)
								{
								default:
									cout << "nie ma takiego kierunku";
									break;
								case 0:
									if (kolumna - dlugosc + 1 >= 0) {
										for (int st = 0; st < dlugosc; st++) {
											if (p1.board[wiersz][kolumna - st] == 0) {
												dobre_pole += 1;

											}
										}
										if (dobre_pole == dlugosc + 1) {
											for (int s = 0; s < dlugosc; s++) {
												p1.board[wiersz][kolumna - s] = dlugosc;
											}
											dobre_pole = 1;
											dust = 1;
											brzegi(wiersz, kolumna, p1, 4 - dlugosc);
										}

										else
										{
											

											dobre_pole = 1;
											cout << "zly kierunek" << endl;
										}
									}
									else
									{
										cout << "z³e pole" << endl;
										dobre_pole = 1;
									}
									break;
								case 1:
									if (wiersz - dlugosc + 1 >= 0) {
										for (int st = 0; st < dlugosc; st++) {
											if (p1.board[wiersz - st][kolumna] == 0) {
												dobre_pole += 1;
											}
										}
										if (dobre_pole == dlugosc + 1) {
											for (int s = 0; s < dlugosc; s++) {
												p1.board[wiersz - s][kolumna] = dlugosc;
											}
											dobre_pole = 1;
											dust = 1;
											brzegi(wiersz, kolumna, p1, 4 - dlugosc);
										}

											dobre_pole = 1;
											cout << "zly kierunek" << endl;
										}
									
									else
									{
										cout << "z³e pole" << endl;
										dobre_pole = 1;
									}
									break;
								case 2:
									if (kolumna + dlugosc - 1 <= 9) {
										for (int st = 0; st < dlugosc; st++) {
											if (p1.board[wiersz][kolumna + st] == 0) {
												dobre_pole += 1;
											}
										}
										if (dobre_pole == dlugosc + 1) {
											for (int s = 0; s < dlugosc; s++) {
												p1.board[wiersz][kolumna + s] = dlugosc;
											}
											dobre_pole = 1;
											dust = 1;
											brzegi(wiersz, kolumna, p1, 4 - dlugosc);
										}
					                    else{
											dobre_pole = 1;
											cout << "zly kierunek" << endl;
										}
									}
									else
									{
										cout << "z³e pole" << endl;
										dobre_pole = 1;
									}
									break;
								case 3:
									if (kolumna + dlugosc - 1 >= 9) {
										for (int st = 0; st < dlugosc; st++) {
											if (p1.board[wiersz + st][kolumna] == 0) {
												dobre_pole += 1;
											}
										}
										if (dobre_pole == dlugosc + 1) {
											for (int s = 0; s < dlugosc; s++) {
												p1.board[wiersz + s][kolumna] = dlugosc;
											}
											dobre_pole = 1;
											dust = 1;
											brzegi(wiersz, kolumna, p1, 4 - dlugosc);
										}
							            else{
											dobre_pole = 1;
											cout << "zly kierunek" << endl;
										}
									}
									else
									{
										cout << "z³e pole" << endl;
										dobre_pole = 1;
									}
									break;
								}
							}
						}
					}
					else {
						cout << "zle pole" << endl;
					}

				}
				ilosc++;

			}
			}
		} while (ilosc!=10);
	}
}
//void player(plansza& plan, plansza& planw, gracz& gra) {//plansza niewidoczna(sprawdzana),plansza widoczna,gracz
//	char pozycja[3]{};
//	bool hit{ 1 }, pp{ 0 };
//	int px{ 0 }, py{ 0 };
//	while (hit == 1) {
//		if (gra.punkty == 20) {
//			hit = 0;
//		}
//		else {
//			cin.clear();
//			cout << "wybierz pole";
//			cin >> pozycja;
//			if (pozycja[0] <= 'j' && pozycja[0] >= 'a') {
//				py = pozycja[0] - 'a';
//			}
//			else if (pozycja[0] <= 'J' && pozycja[0] >= 'A') {
//				py = pozycja[0] - 'A';
//			}
//			else {
//				cout << "nie ma takiego pola";
//			}
//			if (atoi(pozycja + 1) - 1 <= 9 && atoi(pozycja + 1) - 1 >= 0) {
//				px = atoi(pozycja + 1) - 1;
//			}
//			else {
//				cout << "nie ma takiego pola";
//			}
//			if (planw.board[px][py] == 0) {
//				if (plan.board[px][py] != 0) {
//					planw.board[px][py] = 5;
//					cout << "trafiono " << plan.board[px][py] << ".masztowiec" << endl;
//					gra.punkty++;
//				}
//				else {
//					planw.board[px][py] = -1;
//					cout << "pudło";
//					hit = 0;
//				}
//			}
//			else {
//				cout << "już sprawdzałeś to pole";
//			}
//		}
//	}
//}
