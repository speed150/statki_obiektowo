#include "klasy.h"
#include <iostream>
#include <random>
#include <ctime>
#include <Windows.h>
using namespace std;
void wypisz(plansza pl){

	for (int a = 0; a < 10; a++) {
		for (int b = 0; b < 10; b++) {
			cout << pl.board[a][b]<<" ";
			
		}
		cout << endl;
	}
}
void ustaw_statki(plansza p1, int rodzaj) {
	int ilosc = 0;
	bool dust = 0;//dobrze ustawiony statek

	if (rodzaj == 1) {// automatycznie
		mt19937 generator(time(nullptr));
		uniform_int_distribution<int> x(0, 9);//wiersz
		uniform_int_distribution<int> y(0, 9);//kolumna
		uniform_int_distribution<int> k(0, 3);//kierunek
		do {
			for (int powtorka = 4; powtorka > 0; powtorka--) {
				//jak chcesz specjalnie to zjebaæ to siê da (jescze)
				for (int dl = 5; dl > powtorka; dl--) {
					
				}


			}
			
		} while (ilosc!=10);
	}
	else {//przez gracza

	}

}