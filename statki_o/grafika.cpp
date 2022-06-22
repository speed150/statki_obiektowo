#define NOMINMAX
#include "klasy.h"
#include "SFML/Graphics.hpp"
#include <iostream>
#include <random>
#include <ctime>
#include <Windows.h>
#include <string>
using namespace std;
sf::RenderWindow window(sf::VideoMode(1920, 1080, 32), "statki", sf::Style::Default);
sf::CircleShape pudlo(14.f);
sf::RectangleShape planszaStatkiGracz1;
int rozmiarPlanszy{ 700 };
int Odstemp{ 100 };
sf::RectangleShape line(sf::Vector2f(rozmiarPlanszy * 2 + Odstemp, 5));
void komunikat(string tresc,int x,int y) {
	sf::Text komuikat;
	komuikat.setCharacterSize(40);
	komuikat.setFillColor(sf::Color::White);
	komuikat.setOutlineThickness(5.f);
	komuikat.setOutlineColor(sf::Color::Black);
	sf::Font font;
	font.loadFromFile("Lato-Regular.ttf");
	komuikat.setFont(font);
	komuikat.setLetterSpacing(1);
	komuikat.setPosition(sf::Vector2f(0+x,820+y));
	komuikat.setString(tresc);
	window.draw(komuikat);
	window.display();

}
sf::RectangleShape trafienie1(sf::Vector2f(50, 10));
sf::RectangleShape trafienie2(sf::Vector2f(50, 10));
sf::RectangleShape statekFragment;
int numerPola() {
	int pole{};

	sf::String playerInput{};
	sf::Text playerText{};
	sf::Event event{};
	sf::Font font;
	font.loadFromFile("Lato-Regular.ttf");
	playerText.setPosition(sf::Vector2f(70, 880));
	playerText.setFont(font);
	playerText.setCharacterSize(50);
	playerText.setFillColor(sf::Color::White);
	playerText.setOutlineThickness(5.f);
	playerText.setOutlineColor(sf::Color::Black);
	playerText.setFont(font);
	playerText.setCharacterSize(50);
	playerText.setFillColor(sf::Color::White);
	playerText.setOutlineThickness(5.f);
	playerText.setOutlineColor(sf::Color::Black);
	playerInput = "";
	sf::RectangleShape kwarat(sf::Vector2f(50, 50));
	kwarat.setPosition(sf::Vector2f(70, 880));
	kwarat.setFillColor(sf::Color::Black);
	while (pole < 10) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num0)) {
			while (sf::Keyboard::isKeyPressed(sf::Keyboard::Num0)) {}
			window.draw(kwarat);
			window.display();
			//window.clear();
			pole = 0;
			window.clear();
			window.display();
			playerInput =to_string( pole);
			playerText.setString(playerInput);
			window.clear();
			window.display();
			window.draw(playerText);
			window.display();
			//
			window.clear();
		
		}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {
				while (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {}

				window.draw(kwarat);
				window.display();
				window.clear();
				pole = 1;
				window.clear();
				window.display();
				playerInput = to_string(pole);
				playerText.setString(playerInput);
				window.clear();
				window.display();
				window.draw(playerText);
				window.display();
				

			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) {
				while (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) {}

				window.draw(kwarat);
				window.display();
			//	window.clear();
				pole = 2;
				window.clear();
				window.display();
				playerInput = to_string(pole);
				playerText.setString(playerInput);
				window.clear();
				window.display();
				window.draw(playerText);
				window.display();
			
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) {
				while (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) {}

				window.draw(kwarat);
				window.display();
				//window.clear();
				pole = 3;
				window.clear();
				window.display();
				playerInput = to_string(pole);
				playerText.setString(playerInput);
				window.clear();
				window.display();
				window.draw(playerText);
				window.display();
	

			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4)) {
				while (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4)) {}

				window.draw(kwarat);
				window.display();
				//window.clear();
				pole = 4;
				window.clear();
				window.display();
				playerInput = to_string(pole);
				playerText.setString(playerInput);
				window.clear();
				window.display();
				window.draw(playerText);
				window.display();

			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5)) {
				while (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5)) {}

				window.draw(kwarat);
				window.display();
				//window.clear();
				pole = 5;
				window.clear();
				window.display();
				playerInput = to_string(pole);
				playerText.setString(playerInput);
				window.clear();
				window.display();
				window.draw(playerText);
				window.display();
	
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num6)) {
				while (sf::Keyboard::isKeyPressed(sf::Keyboard::Num6)) {}

				window.draw(kwarat);
				window.display();
				//window.clear();
				pole = 6;
				window.clear();
				window.display();
				playerInput = to_string(pole);
				playerText.setString(playerInput);
				window.clear();
				window.display();
				window.draw(playerText);
				window.display();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num7)) {
				while (sf::Keyboard::isKeyPressed(sf::Keyboard::Num7)) {}

				window.draw(kwarat);
				window.display();
				//window.clear();
				pole = 7;
				window.clear();
				window.display();
				playerInput = to_string(pole);
				playerText.setString(playerInput);
				window.clear();
				window.display();
				window.draw(playerText);
				window.display();

			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num8)) {
				while (sf::Keyboard::isKeyPressed(sf::Keyboard::Num8)) {}
				window.draw(kwarat);
				window.display();
				//window.clear();
				pole = 8;
				window.clear();
				window.display();
				playerInput = to_string(pole);
				playerText.setString(playerInput);
				window.clear();
				window.display();
				window.draw(playerText);
				window.display();

			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num9)) {
				while (sf::Keyboard::isKeyPressed(sf::Keyboard::Num9)) {}
				window.draw(kwarat);
				window.display();
				//window.clear();
				pole = 9;
				playerInput = "9";
				window.clear();
				window.display();
				playerInput = to_string(pole);
				playerText.setString(playerInput);
				window.clear();
				window.display();
				window.draw(playerText);
				window.display();

			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
				while (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {}
				return pole;
			}
			

		}

	}

std::string wyborPola(string nazwaGracza, bool czyUstawiane,plansza pl) {
	komunikat("wybierz kolumne od A do I",0,0);
	window.clear();
	window.display();
	string pole{};
	sf::String playerInput{};
	sf::Text playerText{};
	sf::Event event{};
	sf::Font font;
	font.loadFromFile("Lato-Regular.ttf");
	playerText.setPosition(sf::Vector2f(20, 880));
	playerText.setFont(font);
	playerText.setCharacterSize(50);
	playerText.setFillColor(sf::Color::White);
	playerText.setOutlineThickness(5.f);
	playerText.setOutlineColor(sf::Color::Black);
	playerText.setFont(font);
	playerText.setCharacterSize(50);
	playerText.setFillColor(sf::Color::White);
	playerText.setOutlineThickness(5.f);
	playerText.setOutlineColor(sf::Color::Black);
	playerInput = "";
	sf::RectangleShape kwarat(sf::Vector2f(50, 50));
	kwarat.setPosition(sf::Vector2f(20, 880));
	kwarat.setFillColor(sf::Color::Black);

	//while (!sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
	//	
	//	rysowanie_planszy();
	//	//rysowanieStatkow(p1);
	//	przypisyDoPlanszy();
	//	while (window.pollEvent(event))
	//	{
	//		if (event.type == sf::Event::TextEntered)
	//		{
	//			if (event.text.unicode < 128)
	//			{
	//				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Backspace)) {
	//					if (playerInput.getSize() > 0) {
	//						playerInput.erase(playerInput.getSize() - 1, 2);
	//						playerText.setString(playerInput);
	//						window.clear();
	//						window.display();
	//						//cout << playerInput;
	//						
	//					}
	//					window.display();

	//					window.draw(playerText);
	//					window.display();
	//				}
	//				else
	//					if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Backspace)) 
	//					 {
	//					playerInput += event.text.unicode;
	//					playerText.setString(playerInput);
	//					window.clear();

	//					window.draw(playerText);
	//					window.display();
	//				}
	//				window.clear();

	//				window.draw(playerText);
	//				window.display();
	//			}
	//		}
	//	}
	//}

		while (pole.length() < 2) {
			komunikat("wybierz kolumne od A do I enter aby przejść dalej backspace aby usunąć znak",0,0);

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
				while (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {}

				window.draw(kwarat);
				window.display();
				window.clear();
				
				komunikat("wybierz kolumne od A do I enter aby przejść dalej backspace aby usunąć znak",0,0);
				pole = "A";
				playerInput = pole;
				playerText.setString(playerInput);
				rysowanie_planszy();
				rysowanieStatkow(pl, pl);
				window.draw(playerText);
				window.display();
				window.clear();


			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::B)) {
				while (sf::Keyboard::isKeyPressed(sf::Keyboard::B)) {}

				window.draw(kwarat);
				window.display();
				window.clear();
				komunikat("wybierz kolumne od A do I enter aby przejść dalej backspace aby usunąć znak",0,0);
				pole = "B";
				playerInput = pole;
				playerText.setString(playerInput);
				window.draw(playerText);
				window.display();
				window.clear();

			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::C)) {
				while (sf::Keyboard::isKeyPressed(sf::Keyboard::C)) {}

				window.draw(kwarat);
				window.display();
				window.clear();
				komunikat("wybierz kolumne od A do I enter aby przejść dalej backspace aby usunąć znak",0,0);
				pole = "C";
				playerInput = pole;
				playerText.setString(playerInput);
				window.draw(playerText);
				window.display();
				window.clear();

			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
				while (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {}
				

				window.draw(kwarat);
				window.display();
				window.clear();
				komunikat("wybierz kolumne od A do I enter aby przejść dalej backspace aby usunąć znak",0,0);
				pole = "D";
				playerInput = pole;
				playerText.setString(playerInput);
				window.draw(playerText);
				window.display();
				window.clear();

			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
				while (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {}
			

				window.draw(kwarat);
				window.display();
				window.clear();
				komunikat("wybierz kolumne od A do I enter aby przejść dalej backspace aby usunąć znak",0,0);
				pole = "E";
				playerInput = pole;
				playerText.setString(playerInput);
				window.draw(playerText);
				window.display();
				window.clear();

			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {
				while (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {}

				window.draw(kwarat);
				window.display();
				komunikat("wybierz kolumne od A do I enter aby przejść dalej backspace aby usunąć znak",0,0);
				window.clear();
				pole = "F";
				playerInput = pole;
				playerText.setString(playerInput);
				window.draw(playerText);
				window.display();
				window.clear();

			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::G)) {
				while (sf::Keyboard::isKeyPressed(sf::Keyboard::G)) {}

				window.draw(kwarat);
				window.display();
				window.clear();
				komunikat("wybierz kolumne od A do I enter aby przejść dalej backspace aby usunąć znak",0,0);
				pole = "G";
				playerInput = pole;
				playerText.setString(playerInput);
				window.draw(playerText);
				window.display();
				window.clear();

			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::H)) {
				while (sf::Keyboard::isKeyPressed(sf::Keyboard::H)) {}

				window.draw(kwarat);
				window.display();
				window.clear();
				komunikat("wybierz kolumne od A do I enter aby przejść dalej backspace aby usunąć znak",0,0);
				pole = "H";
				playerInput = pole;
				playerText.setString(playerInput);
				window.draw(playerText);
				window.display();
				window.clear();

			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::I)) {
				while (sf::Keyboard::isKeyPressed(sf::Keyboard::I)) {}
				window.draw(kwarat);

				window.display();
				window.clear();
				komunikat("wybierz kolumne od A do I enter aby przejść dalej backspace aby usunąć znak",0,0);
				pole = "I";
				playerInput = pole;
				playerText.setString(playerInput);
				window.draw(playerText);
				window.display();
				window.clear();

			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::J)) {
				while (sf::Keyboard::isKeyPressed(sf::Keyboard::J)) {}

				window.draw(kwarat);
				window.display();
				window.clear();
				pole = "J";
				playerInput = pole;
				playerText.setString(playerInput);
				window.draw(playerText);
				window.display();
				window.clear();
				komunikat("wybierz kolumne od A do I enter aby przejść dalej backspace aby usunąć znak",0,0);

			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
				komunikat("wybierz kolumne od A do I enter aby przejść dalej backspace aby usunąć znak",0,0);

				while (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {}
				return pole;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) {

				while (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) {}
				window.draw(kwarat);
				window.clear();
				window.display();
				pole = " ";
				playerInput = pole;
				playerText.setString(playerInput);
				window.draw(kwarat);
				window.display();
				window.clear();
				komunikat("wybierz kolumne od A do I enter aby przejść dalej backspace aby usunąć znak",0,0);

			
		}
	}

		window.clear();
		return playerInput;
		///playerInput = "";
	
}
void ustawStakiMenu(string nazwaGracza, plansza& p1,int iloscGraczy) {
	window.clear();

	sf::Text jakUstawicStatko;
	jakUstawicStatko.setCharacterSize(40);
	jakUstawicStatko.setFillColor(sf::Color::White);
	jakUstawicStatko.setOutlineThickness(5.f);
	jakUstawicStatko.setOutlineColor(sf::Color::Black);
	sf::Font font;
	font.loadFromFile("Lato-Regular.ttf");
	jakUstawicStatko.setFont(font);
	jakUstawicStatko.setLetterSpacing(1);
	jakUstawicStatko.setPosition(sf::Vector2f(20, 0));
	jakUstawicStatko.setString(nazwaGracza);
	window.draw(jakUstawicStatko);
	jakUstawicStatko.setPosition(sf::Vector2f(40, 50));
	jakUstawicStatko.setString("1. automatycznie");
	window.draw(jakUstawicStatko);
	jakUstawicStatko.setPosition(sf::Vector2f(40, 90));
	jakUstawicStatko.setString("2. ręcznie");
	window.draw(jakUstawicStatko);
	jakUstawicStatko.setPosition(sf::Vector2f(40, 140));
	jakUstawicStatko.setString("3. wyjdź");
	window.draw(jakUstawicStatko);
	window.display();
	int sposubUstawienia{ 0 };
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {
		while (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {}
		sposubUstawienia = 1;
		window.clear();
		
			window.clear();
			ustaw_statki(p1, sposubUstawienia);
		

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) {
		while (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) {}
		rysowanieMenu();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) {
		while (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) {}
		sposubUstawienia = 2;
		window.clear();
	
			window.clear();
			ustaw_statki(p1, sposubUstawienia);


		
	}
	if (iloscGraczy == 2) {
		plansza p2;
		ustawStakiMenu("gracz 2", p2, 1);
	}
}

void przypisyDoPlanszy() {
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
	window.display();

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
		przypisyDoPlanszy();
		window.display();

}
void rysowanieStatkow(plansza p1, plansza p2) {
	
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++)
		{
			if (p1.board[i][j] == 0)
			{
			}
			else if (p1.board[i][j] == -1)
			{
				pudlo.setPosition(sf::Vector2f((rozmiarPlanszy / 10) * j + 60, (rozmiarPlanszy / 10) * (i)+75));
				pudlo.setFillColor(sf::Color::Black);
				pudlo.setOutlineThickness(5.f);
				pudlo.setOutlineColor(sf::Color(250, 0, 0));
				window.draw(pudlo);
			}
			else if (p1.board[i][j] == 5)
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
			if (p2.board[i][j] == 0)
			{
			}
			else if (p2.board[i][j] == -1)
			{
				pudlo.setPosition(sf::Vector2f((rozmiarPlanszy / 10) * (j)+60 + 12 + rozmiarPlanszy + Odstemp, 5 + (rozmiarPlanszy / 10) * (i)+70));
				pudlo.setFillColor(sf::Color::Black);
				pudlo.setOutlineThickness(5.f);
				pudlo.setOutlineColor(sf::Color(250, 0, 0));
				window.draw(pudlo);
			}
			else if (p2.board[i][j] == 5)
			{
				trafienie1.setPosition(sf::Vector2f((rozmiarPlanszy / 10) * (j)+60 + 12 + rozmiarPlanszy + Odstemp, (rozmiarPlanszy / 10) * (i)+70 + 5));
				trafienie1.setFillColor(sf::Color::Red);
				trafienie2.setPosition(sf::Vector2f(1, 1));
				trafienie2.setFillColor(sf::Color::Red);
				trafienie1.setPosition(sf::Vector2f((rozmiarPlanszy / 10) * j + 105 + rozmiarPlanszy + Odstemp, (rozmiarPlanszy / 10) * (i)+75));
				trafienie1.setFillColor(sf::Color::Red);
				trafienie1.setRotation(135);
				trafienie2.setPosition(sf::Vector2f((rozmiarPlanszy / 10) * j + 70 + rozmiarPlanszy + Odstemp, (rozmiarPlanszy / 10) * (i)+70));
				trafienie2.setFillColor(sf::Color::Red);
				trafienie2.setRotation(45);
				window.draw(trafienie1);
				window.draw(trafienie2);
			}
			else {
				statekFragment.setPosition(sf::Vector2f((rozmiarPlanszy / 10) * j + rozmiarPlanszy + Odstemp + 60, (rozmiarPlanszy / 10) * i + 65));
				statekFragment.setFillColor(sf::Color::White);
				statekFragment.setSize(sf::Vector2f(50, 50));
				window.draw(statekFragment);

			}
		}
	}
	window.display();
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
			menu1.setString("1 gra z komputerem");
			menu1.setPosition(sf::Vector2f(40, 60));
			window.draw(menu1);
			menu1.setString("2 gra z przeciwnikiem");
			menu1.setPosition(sf::Vector2f(40, 120));
			window.draw(menu1);
			menu1.setString("3 opusc");
			menu1.setPosition(sf::Vector2f(40, 180));
			window.draw(menu1);
			window.display();
			int poziomTrudnosic{ 0 };
			int PierwszeMenu{ 0 };
			int MenuTrudnosci{ 0 };
			int MenuUstawiania{ 0 };
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {
			
				while (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
				{
				}
					PierwszeMenu = 1;
					MenuTrudnosci = 0;
					int MenuStatkow{ 0 };
					while (PierwszeMenu == 1)
					{
						window.clear();
						menu1.setPosition(sf::Vector2f(20, 0));
						menu1.setString("wybierz poziom trudnosci");
						window.draw(menu1);
						menu1.setString("1. latwy");
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
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {
							while(sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)){}
							MenuStatkow = 1;
							poziomTrudnosic = 1;
							while (MenuStatkow == 1)
							{
								plansza p1;
								ustawStakiMenu("gracz ",p1,1);
								if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) {
									while(sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) {}
									MenuStatkow = 0;
									
								}
							}
						}
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) {
							while(sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) {}
							MenuStatkow = 1;
							poziomTrudnosic = 2;
								plansza pl;
							while (MenuStatkow == 1)
						
							
								ustawStakiMenu("gracz ",pl,1);
								if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) {
									while (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) {}
									MenuStatkow = 0;
									
								}
							}
						}
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) {
							while (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) {}
							poziomTrudnosic = 3;
							MenuStatkow = 1;
							while (MenuStatkow == 1)
							{
								plansza p1;
								
								ustawStakiMenu("gracz ",p1,1);
								if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) {
									while (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) {}
									MenuStatkow = 0;
									
								}
							}
						}
					
				}
			
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) {
				while (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) {}
				if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) {
					PierwszeMenu = 2;
					while (PierwszeMenu == 2)
					{
						plansza p1;
						
				/*	gracz PierwszyGracz;
					gracz DrugiGracz;*/

						ustawStakiMenu("gracz 1",p1,2);

						//ustawStakiMenu("gracz 2",p2);
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) {
							PierwszeMenu = 0;
							Sleep(250);
						}
					}
				}
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) {
				window.clear();
				window.close();
				menuGlowne = 0;
				
				break;
			}
		}
	}
}