#include <iostream>
#include <string>
#include "funkcje.h"
#include "klasy.h"
using namespace std;
int main() {
	//plansza g1,g1w,g2,g2w;
	plansza a;
	ustaw_statki(a, 1);
	for(int i =0;i<15;i++)
	ai(a, 3);

	wypisz(a);
	
}