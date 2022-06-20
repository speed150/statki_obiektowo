 #include "klasy.h"

pole::pole() {
	wartosc = 0;
	x = 10;
	y = 10;
};
pole::pole(int w, int wiersz, int kolumna) {
	wartosc = w;
	x = wiersz;
	y = kolumna;
};
plansza::plansza(){
	
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			board[i][j] = 0;
		}
	}

}
statek::statek(int r, pole a) {
	rozmiar = r;
	trafienia = 0;
	p1 = a;
};
statek::statek(int r, pole a, pole b) {
	rozmiar = r;
	trafienia = 0;
	p1 = a;
	p2 = b;
};
statek::statek(int r, pole a, pole b, pole c) {
	rozmiar = r;
	trafienia = 0;
	p1 = a;
	p2 = b;
	p3 = c;
};
statek::statek(int r, pole a, pole b, pole c, pole d) {
	rozmiar = r;
	trafienia = 0;
	p1 = a;
	p2 = b;
	p3 = c;
	p4 = d;
};
