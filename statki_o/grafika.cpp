#include "klasy.h"
#include "SFML/Graphics.hpp"
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