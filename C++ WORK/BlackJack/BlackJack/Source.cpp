#include <iostream>
#include "Blackjack.h"

int main() {
	int exitGame = 1;

	do 
	{
		Blackjack casino_royale;
		casino_royale.playGame();
		std::cout << "Would you like to play again?" << std::endl;
		std::cin >> exitGame;

	} while (exitGame ==  1);

	std::cout << "\nThanks for playing\n" << std::endl;
	system("pause");
	return 0;
}