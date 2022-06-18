#include "klasy.h"
#include <iostream>
#include <random>
#include <ctime>
using namespace std;
int trafienia,hitx,hity,tk;
int statek;
bool trafiony{ false };
bool k0{ false }, k1{ false }, k2{ false }, k3{ false }, trafionyk{ false };
plansza g1;//to widzi bot

void ai(plansza gracz,int poziom) {
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
			//przerwanie szukania w pobli¿u
			if (statek == gracz.board[hitx][hity]) {
				if (poziom == 3) {
					brzegi(hitx, hity, g1, 4-statek);
					wypisz(g1);
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
					if (hity - 1 > -1 && g1.board[hitx][hity - 1] == 0) {//zostaje w tablicy i nie by³o powtórek
						if (gracz.board[hitx][hity - 1] == 0) {//pud³o
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
							hity -= 1;//przesuniêcie
							
						}
					}
					else if (((g1.board[hitx][hity - 1] == -1 && hity - 1 > -1) || hity - 1 == -1) && trafionyk == true) {//œciana / znana wartoœæ(pud³o)
						k0 = true;
						kierunek = 2;
						tk = kierunek;
						
					}
					else if (trafionyk == true && g1.board[hitx][hity - 1] == g1.board[hitx][hity]) {//znana wartoœæ(statek
						if (hity > 0) {
							hity -= 1;
						}
						tk = kierunek;
					}
				}
				else if (kierunek == 1 && (k1 == false || statek > 1)) {//góra 
					if (hitx - 1 > -1 && g1.board[hitx - 1][hity] == 0) {
						if (gracz.board[hitx - 1][hity] == 0) {//pud³o
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
					else if (((g1.board[hitx - 1][hity] == -1 && hity - 1 > -1) || hitx - 1 == -1) && trafionyk == true) {//œciana / znana wartoœæ(pud³o)
						k0 = true;
						kierunek = 3;
						tk = kierunek;
						
					}
					else if (trafionyk == true && g1.board[hitx - 1][hity] == g1.board[hitx][hity]) {//znana wartoœæ(statek
						if (hitx > 0) {
							hitx -= 1;
						}
						tk = kierunek;
						
					}
				}
				else if (kierunek == 2 && (k2 == false || statek > 1)) {//prawo 
					if (hity + 1 < 10 && g1.board[hitx][hity + 1] == 0) {
						if (gracz.board[hitx][hity + 1] == 0) {//pud³o
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
							hity += 1;//przesuniêcie
							
						}
					}
					else if (((g1.board[hitx][hity + 1] == -1 && hity + 1 < 10) || hity + 1 == 10) && trafionyk == true) {//œciana / znana wartoœæ(pud³o)
						k2 = true;
						kierunek = 0;
						tk = kierunek;
						
					}
					else if (trafionyk == true && g1.board[hitx][hity + 1] ==g1.board[hitx][hity]) {//znana wartoœæ(statek
						if (hity < 10) {
							hity += 1;
						}
						tk = kierunek;
						
					}
				}
				else if (kierunek == 3 && (k3 == false || statek > 1)) {//dó³ 
					if (hitx + 1 < 10 && g1.board[hitx + 1][hity] == 0) {
						if (gracz.board[hitx + 1][hity] == 0) {//pud³o
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
					else if (((g1.board[hitx + 1][hity] == -1 && hity + 1 < 10) || hitx + 1 == 10) && trafionyk == true) {//œciana / znana wartoœæ(pud³o)
						k3 = true;
						kierunek = 1;
						tk = kierunek;
						
					}
					else if (trafionyk == true && g1.board[hitx + 1][hity] == g1.board[hitx][hity]) {//znana wartoœæ(statek
						if (hitx < 10) {
							hitx += 1;
						}
						tk = kierunek;
						
					}
				}
			}
			else if (g1.board[wiersz][kolumna] == 0 && hit == true) {//nie powta¿alne komórki i nie trafiono statku
				{
					if (gracz.board[wiersz][kolumna] != 0) {//trafienie w statek
						//³atwy bot
						if (poziom == 1) {
							g1.board[wiersz][kolumna] = gracz.board[wiersz][kolumna];
							trafienia++;
							
						}
						//œredni bot i trudny 
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
}