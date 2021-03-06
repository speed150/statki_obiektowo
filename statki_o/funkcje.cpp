#define NOMINMAX

#include "klasy.h"
//#include "SFML/Graphics.hpp"

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
void wypisz(plansza pl,plansza p2) {
	int a = 0;
	char litery[12]{ " ABCDEFGHIJ" };
	int liczby[10]{ 1,2,3,4,5,6,7,8,9,10 };
	for (int a = 0; a < 10; a++) {
		if (a == 0) {
			for (int k = 0; k < 12; k++) {
				cout.width(3);
				cout << litery[k];
			}
			cout << "\t|\t";
		}

		if (a == 0) {
			for (int k = 0; k < 12; k++) {
				cout.width(3);
				cout << litery[k];
			}
			cout << endl;
		}
		for (int j = 0; j < 10; j++) {
			if (j == 0) {
				cout.width(3);
				cout << a + 1;
			}
			cout.width(3);
			if (pl.board[a][j] == 0)
				cout << " ";
			else if (pl.board[a][j] == -1)
				cout << "O";
			else if (pl.board[a][j] == 5)
				cout << "X";
			else
				cout << pl.board[a][j];
		}
		cout << "\t|\t";

		for (int j = 0; j < 10; j++) {
			if (j == 0) {
				cout.width(3);
				cout << a + 1;
			}
			cout.width(3);
			if (p2.board[a][j] == 0)
				cout << " ";
			else if (p2.board[a][j] == -1)
				cout << "O";
			else if (p2.board[a][j] == 5)
				cout << "X";
			else
				cout << p2.board[a][j];
		}
		cout << endl;
	}
	cout << endl;


}

void ustaw_statki(plansza& p1, int rodzaj) {
	//rysowanieMenu();
	plansza zero;
	int ilosc = 0;
	bool dust = 0;//dobrze ustawiony statek
	int wiersz, kolumna, kierunek;
	int dobre_pole = 1;
	czysc(p1);
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
				/*przypisyDoPlanszy();
				rysowanie_planszy();
				rysowanieStatkow(p1, p1);*/
			}
		} while (ilosc != 10);
		
		
		zeruj(p1);
	}
	else {//przez gracza

		char poz[3]{};
		int kierunek{};
		char wier[1]{};
		ilosc = 0;
		bool dane{ 1 };
		bool dkier = 0;
		int wiersz{}, kolumna{}, dobre_pole{ 1 };
		do {
			for (int dlugosc = 4; dlugosc > 0; dlugosc--) {
				for (int pow = 5; pow > dlugosc; pow--) {//powtórzenie statku
					dust = 0;
					while (dust == 0) {
						cout << "podaj pozycje" << endl;
						wypisz(p1,p1);
						cin >> poz;
						
						if (poz[0] <= 'J' && poz[0] >= 'A') {
							kolumna = poz[0] - 'A';
						}
						else {
							kolumna = poz[0] - 'a';
						}
						//stirng a = pozycja.substr(1, 1);
						//cout << poz[1];
						wier[0] = poz[1];
						if (atoi(poz+1)-1 <= 9 && atoi(poz+1)-1 >= 0) {
							wiersz = atoi(poz+1)-1;
						}
						else
						{
							continue;
						} 

						
						//cout << wiersz;

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
									cin >> kierunek;
									//kierunek = stoi(wyborPola("gracz", false));
									//int a= numerPola();
									
									kierunek -= 1;
									//string a = pozycja.substr(0, 1);


									switch (kierunek)
									{
									default:
										cout << "zły kieruenek" << endl;
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
												cout << "zly kierunek" << endl;



												dobre_pole = 1;
											
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
											else {
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
										if (wiersz + dlugosc - 1 <= 9) {
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
											else {
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
									wypisz(p1, p1);
								}
							}
						else {
						cout << "zajente pole" << endl;
						}
						}
						else {
							cout << "zle pole" << endl;

						}

					}
					ilosc++;

				}
			}
		} while (ilosc != 10);
	}
}