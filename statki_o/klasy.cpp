 #include "klasy.h"


plansza::plansza(){
	
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			board[i][j] = 0;
		}
	}

}
gracz::gracz() {
	punkty = 0;
}