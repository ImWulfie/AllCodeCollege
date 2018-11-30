#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cctype>


std::string The_Word;
int wrong;
std::string SoFar;
std::string Used;


bool match(char letter, std::string word);
char askGuess(std::string usedLettersStr);
bool playAgain();

int main(){

	srand(time(0));

	const std::string words[51] = { "news", "direction", "depend", "tablet", "human", "body", "slot", "dive", "offense",
									"landscape", "serve", "pumpkin", "copyright", "contain", "breast", "technology", "fish", 
									"glue", "predator", "identity", "classify", "doggo", "motherboard", "power supply", "ram",
									"fan", "war", "mob", "black Ops", "skynet", "atmosphere", "myth", "gulag", "exploit", "eye",
									"candidate", "dribble", "lock", "declaration", "hunt", "shadow", "wolf", "view", "equilibrium",
									"turkey", "talkative", "agency", "agent 47", "marakesh", "sapienza", "colorado",};
		
		
		std::cout << "Welcome to Hangman! User :P";

	bool done = false;
	do {
		const int Max_Wrong = 8;

		int RandIndex = rand() % 51;
		The_Word = words[RandIndex];

		SoFar = std::string(The_Word.size(), '-');
		Used = "";

		while ((wrong < Max_Wrong) && (SoFar != The_Word)) {

			std::cout << "\n\nYou have " << (Max_Wrong - wrong) << " incorrect guesses left.\n";
			std::cout << "\nYou've used the following letters:\n" << Used << "\n";
			std::cout << "\nSo far, the word is:\n" << SoFar << "\n";

			Used += askGuess(Used);
		}

		if (wrong == Max_Wrong) {
			std::cout << "You've been hung\n";
			std::cout << "\n";
			std::cout << " ___________.._______ " << std::endl;
			std::cout << "| .__________))______|" << std::endl;
			std::cout << "| | / /      ||       " << std::endl;
			std::cout << "| |/ /       ||       " << std::endl;
			std::cout << "| | /        ||.-''.  " << std::endl;
			std::cout << "| |/         |/  _  \ " << std::endl;
			std::cout << "| |          ||  x/x| " << std::endl;
			std::cout << "| |          (\\`_.'  " << std::endl;
			std::cout << "| |         .-`--'.   " << std::endl;
			std::cout << "| |        |Y . . Y|  " << std::endl;
			std::cout << "| |       || |   | || " << std::endl;
			std::cout << "| |       || | . | || " << std::endl;
			std::cout << "| |       ') |   | (` " << std::endl;
			std::cout << "| |          ||'||    " << std::endl;
			std::cout << "| |          || ||    " << std::endl;
			std::cout << "| |          || ||    " << std::endl;
			std::cout << "| |          || ||    " << std::endl;
			std::cout << "| |          || ||    " << std::endl;
			std::cout << "''''''''''| `-' `-' |''' | " << std::endl;
			std::cout << "          |_________|      " << std::endl;

			
		}
		std::cout << "\nThe word was: " << The_Word << "\n";
	} 
	while (playAgain());
	return 0;
}

inline bool match(char letter, std::string word) {
	return (word.find(letter) != std::string::npos);
}

char askGuess(std::string UsedLettersStr) {
	char guess;
	std::cout << "\nEnter your guess: ";
	std::cin >> guess;
	
	while (match(guess, Used)) {
		std::cout << "\nYou've already guessed " << guess << "\n";
		std::cout << "\nEnter your guess: ";
		std::cin >> guess;
	}


	if (match(guess, The_Word)) {
		std::cout << "Yes that's right " << guess << " is in the word.\n";

		for (int i = 0; i < The_Word.length(); i++)
			if (The_Word[i] == guess)
				SoFar[i] = guess;
	}
	else {
		std::cout << "Sorry, " << guess << " is not in the word!\n";
		++wrong;	
	}
	return guess;
}

bool playAgain() {
	char again;
	std::cout << "\nInput a letter to continue...";
	std::cin >> again;

	system("cls");
	return(again == 'y');
}