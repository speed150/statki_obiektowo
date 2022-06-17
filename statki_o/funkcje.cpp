#include "klasy.h"
#include <iostream>
#include <random>
#include <ctime>
#include <Windows.h>
using namespace std;
sf::RenderWindow window(sf::VideoMode(1920, 1080, 32), "statki", sf::Style::Default);
sf::CircleShape pudlo(14.f);
sf::RectangleShape planszaStatkiGracz1;
int rozmiarPlanszy{ 700 };
int Odstemp{ 100 };


sf::RectangleShape line(sf::Vector2f(rozmiarPlanszy * 2 + Odstemp, 5));
sf::RectangleShape trafienie1(sf::Vector2f(50, 10));
sf::RectangleShape trafienie2(sf::Vector2f(50, 10));

sf::RectangleShape statekFragment;
void przypisyDoPlanysz() {
	int skok{ 0 };
	for (int i = 1; i <= 10; i++) {
		sf::Text liczby;
		liczby.setCharacterSize(50);
		liczby.setFillColor(sf::Color::White);
		liczby.setOutlineThickness(5.f);
		liczby.setOutlineColor(sf::Color::Black);
		sf::Font font;
		font.loadFromFile("Lato-Regular.ttf");
		liczby.setFont(font);
		liczby.setString(to_string(i));
		liczby.setLetterSpacing(0);
		liczby.setPosition(sf::Vector2f(90 + rozmiarPlanszy, i * 70));
		window.draw(liczby);
	}
	for (int i = 0; i < 20; i++) {
		sf::Text litery;
		litery.setCharacterSize(50);
		litery.setFillColor(sf::Color::White);
		litery.setOutlineThickness(5.f);
		litery.setOutlineColor(sf::Color::Black);

		sf::Font font;
		font.loadFromFile("Lato-Regular.ttf");
		litery.setFont(font);
		litery.setString("A B C D E F G H I J");
		litery.setLetterSpacing(5.5);
		litery.setPosition(sf::Vector2f(skok + 50, 0));
		window.draw(litery);

		if (i == 9) {
			skok = 104 + rozmiarPlanszy;
		}
	}
}
void rysowanie_planszy() {

	planszaStatkiGracz1.setSize(sf::Vector2f(rozmiarPlanszy, rozmiarPlanszy));

	planszaStatkiGracz1.setFillColor(sf::Color::Green);
	trafienie1.setFillColor(sf::Color::Red);
	trafienie2.setFillColor(sf::Color::Red);
	window.draw(trafienie1);
	window.draw(trafienie2);
	bool pierwszyPrzebieg = TRUE;
	line.setFillColor(sf::Color::Black);
	for (int i = 0; i < 2; i++) {
		planszaStatkiGracz1.setPosition(sf::Vector2f(50 + Odstemp * i + rozmiarPlanszy * i, 60));
		window.draw(planszaStatkiGracz1);
	}
	for (int i = 0; i < 9; i++)
	{
		line.setPosition(sf::Vector2f(50, 5 + 87.5 + 30 + (rozmiarPlanszy / 10) * i));
		window.draw(line);
	}
	sf::RectangleShape line(sf::Vector2f(rozmiarPlanszy, 5));
	line.rotate(90);
	line.setFillColor(sf::Color::Black);
	float skok{ 0 };
	for (int i = 0; i < 18; i++) {
		line.setPosition(sf::Vector2f(90 + 30 + (rozmiarPlanszy / 10) * i + skok, 55));
		window.draw(line);
		if (i == 8) {
			skok = 104 + rozmiarPlanszy * 0.1;
		}
	}

}
void rysowanieStatkow(int tab[10][10], int tab1[10][10]) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++)
		{
			if (tab[i][j] == 0)
			{
			}
			else if (tab[i][j] == -1)
			{

				pudlo.setPosition(sf::Vector2f((rozmiarPlanszy / 10) * j + 40, (rozmiarPlanszy / 10) * (i)+5));
				pudlo.setFillColor(sf::Color::Black);

				pudlo.setOutlineThickness(5.f);
				pudlo.setOutlineColor(sf::Color(250, 0, 0));
				window.draw(pudlo);
			}
			else if (tab[i][j] == 5)
			{


			}
			else {
				statekFragment.setPosition(sf::Vector2f((rozmiarPlanszy / 10) * j + 60, (rozmiarPlanszy / 10) * i + 65));
				statekFragment.setFillColor(sf::Color::White);
				statekFragment.setSize(sf::Vector2f(50, 50));
				window.draw(statekFragment);


			}
		}
	}
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++)
		{
			if (tab1[i][j] == 0)
			{
			}
			else if (tab1[i][j] == -1)
			{

				pudlo.setPosition(sf::Vector2f((rozmiarPlanszy / 10) * (j)+60 + 12 + rozmiarPlanszy + Odstemp, 5 + (rozmiarPlanszy / 10) * (i)+70));
				pudlo.setFillColor(sf::Color::Black);

				pudlo.setOutlineThickness(5.f);
				pudlo.setOutlineColor(sf::Color(250, 0, 0));
				window.draw(pudlo);
			}
			else if (tab[i][j] == 5)
			{
				trafienie1.setPosition(sf::Vector2f((rozmiarPlanszy / 10) * (j)+60 + 12 + rozmiarPlanszy + Odstemp, (rozmiarPlanszy / 10) * (i)+70 + 5));
				trafienie1.setFillColor(sf::Color::Red);
				trafienie2.setPosition(sf::Vector2f(1, 1));
				trafienie2.setFillColor(sf::Color::Red);
				window.draw(trafienie1);
				window.draw(trafienie2);
			}
			else {
				statekFragment.setPosition(sf::Vector2f((rozmiarPlanszy / 10) * j + rozmiarPlanszy + Odstemp + 60, (rozmiarPlanszy / 10) * i + 65));

				statekFragment.setFillColor(sf::Color::White);
				statekFragment.setSize(sf::Vector2f(50, 50));
				window.draw(statekFragment);

				trafienie1.setPosition(sf::Vector2f((rozmiarPlanszy / 10) * j + 105 + rozmiarPlanszy + Odstemp, (rozmiarPlanszy / 10) * (i)+75));
				trafienie1.setFillColor(sf::Color::Red);
				trafienie1.setRotation(135);
				trafienie2.setPosition(sf::Vector2f((rozmiarPlanszy / 10) * j + 70 + rozmiarPlanszy + Odstemp, (rozmiarPlanszy / 10) * (i)+70));
				trafienie2.setFillColor(sf::Color::Red);
				trafienie2.setRotation(45);
				window.draw(trafienie1);
				window.draw(trafienie2);

			}
		}
	}

}
void rysowanieMenu() {
	while (window.isOpen())
	{


		sf::Event event;


		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		bool menuGlowne{ true };
		while (menuGlowne)
		{
			window.clear();

			sf::Text menu1;
			menu1.setCharacterSize(50);
			menu1.setFillColor(sf::Color::White);
			menu1.setOutlineThickness(5.f);
			menu1.setOutlineColor(sf::Color::Black);
			sf::Font font;
			font.loadFromFile("Lato-Regular.ttf");
			menu1.setFont(font);

			menu1.setLetterSpacing(1);
			menu1.setPosition(sf::Vector2f(20, 0));
			menu1.setString("statki:");
			window.draw(menu1);
			menu1.setString("1 gra z konputerem");
			menu1.setPosition(sf::Vector2f(40, 60));
			window.draw(menu1);
			menu1.setString("2 gra z pszeciwnikiem");
			menu1.setPosition(sf::Vector2f(40, 120));
			window.draw(menu1);
			menu1.setString("3 opusc");
			menu1.setPosition(sf::Vector2f(40, 180));
			window.draw(menu1);
			window.display();
			int PierwszeMenu{ 0 };
			int MenuTrudnosci{ 0 };
			int MenuUstawiania{ 0 };
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {
				PierwszeMenu = 1;
				MenuTrudnosci = 0;
				while (PierwszeMenu == 1)
				{
					window.clear();
					menu1.setPosition(sf::Vector2f(20, 0));
					menu1.setString("wybierz poziom trudnosci");
					window.draw(menu1);
					menu1.setString("1. łatwy");
					menu1.setPosition(sf::Vector2f(40, 60));
					window.draw(menu1);

					menu1.setString("2. sredni");
					menu1.setPosition(sf::Vector2f(40, 120));

					window.draw(menu1);
					menu1.setString("3. trudny");
					menu1.setPosition(sf::Vector2f(40, 180));

					window.draw(menu1);
					menu1.setString("4. menu");
					menu1.setPosition(sf::Vector2f(40, 240));

					window.draw(menu1);
					window.display();
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4)) {
						PierwszeMenu = 0;
					}

				}
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) {
			window.clear();
			window.close();
			menuGlowne = FALSE;
		}
	
		
	}
	
}
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
	int ilosc = 0;
	bool dust = 0;//dobrze ustawiony statek
	int wiersz, kolumna, kierunek;
	int dobre_pole = 1;
	rysowanieMenu();
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
		zeruj(p1);
	}
	else {//przez gracza

	}
}
