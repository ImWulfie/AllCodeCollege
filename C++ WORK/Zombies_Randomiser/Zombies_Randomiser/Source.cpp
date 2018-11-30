#include <iostream>
#include <time.h>
#include <string>
#include <random>
#include <thread>
#include <chrono>

void Repeat();

std::random_device rd;     // only used once to initialise (seed) engine
std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
std::uniform_int_distribution<int> uni(0, 10); // guaranteed unbiased


int main() {

	std::cout << "" << std::endl;
	std::cout << " _______________________________________________ " << std::endl;
	std::cout << "| WELCOME TO THE BO4 ZOMBIES RANDOMISER SYSTEM  |" << std::endl;
	std::cout << "|   The following applications are available    |" << std::endl;
	std::cout << "|             1. Mystery Box Generator          |" << std::endl;
	std::cout << "|             2.  Wunderfizz Generator          |" << std::endl;
	std::cout << "|_______________________________________________|" << std::endl;


	int choice = 0;
	std::cout << "Please select which option you want to use" << std::endl;
	std::cin >> choice;

	switch (choice){
	case 0:
		exit(0);
		break;

	case 1:

		std::cout << "" << std::endl;

		Repeat();
		break;

	case 2:
		std::string Perks[9] = { "Juggernog", "Speed Cola", "Quick Revive", "Double-Tap", "Mule Kick", "Deadshot Daquri", "Widow's Wine", "PHD Flopper", "Stamin-Up", };
		std::cout << "You got: " << std::endl;
		std::chrono::milliseconds timespan(5000);
		std::cout << "..." << std::endl;
		std::cout << Perks[uni(rng)] << std::endl;

		Repeat();
		break;

	

	}


}




void Repeat() {
	char x;
	std::cout << "     Would you like to use the randomiser again?" << std::endl;
	std::cin >> x;
	if (x == 'y') {
		system("cls");
		main();
	}
	else if (x == 'n') {
		exit(0);
	}
	else {
		std::cout << "ERROR: Unknown response, please enter 'y' or 'n' only!" << std::endl;
		Repeat();
	}
}