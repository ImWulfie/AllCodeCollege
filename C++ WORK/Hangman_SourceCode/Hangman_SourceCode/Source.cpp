// Hangman
// The classic game of hangman, now with methods

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cctype>

using namespace std;

string THE_WORD;            // word to guess
int wrong;
string soFar;
string used;

bool match(char letter, string word);
char askGuess(string usedLettersStr); //tells the compiler of method askGuess
bool playAgain();

int main()
{
	srand(time(0));

	vector<string> words;  // collection of possible words to guess
	words.push_back("GUESS");
	words.push_back("HANGMAN");
	words.push_back("DIFFICULT");
	words.push_back("BOOK");
	words.push_back("DIGITAL");
	words.push_back("PROGRAM");

	cout << "Welcome to Hangman.  Good luck!\n";

	// loop starts here
	bool done = false;
	do
	{
		const int MAX_WRONG = 8;  // maximum number of incorrect guesses allowed

		random_shuffle(words.begin(), words.end());
		THE_WORD = words[0];            // word to guess

		soFar = string(THE_WORD.size(), '-');          // word guessed so far
		used = "";                            // letters already guessed

		// loop for current word
		while ((wrong < MAX_WRONG) && (soFar != THE_WORD))
		{
			cout << "\n\nYou have " << (MAX_WRONG - wrong) << " incorrect guesses left.\n";
			cout << "\nYou've used the following letters:\n" << used << endl;
			cout << "\nSo far, the word is:\n" << soFar << endl;

			used += askGuess(used);



		} // end of while ((wrong < MAX_WRONG) && (soFar != THE_WORD))

		// shut down
		if (wrong == MAX_WRONG)
		{
			cout << "\nYou've been hanged!";
		}

		cout << "\nThe word was " << THE_WORD << endl;

	} while (playAgain());

	return 0;
}

inline bool match(char letter, string word)
{
	return (word.find(letter) != string::npos);
}

char askGuess(string usedLettersStr)
{
	char guess;
	cout << "\n\nEnter your guess: ";
	cin >> guess;
	guess = toupper(guess); //make uppercase since secret word in uppercase
//        while (used.find(guess) != string::npos)
	while (match(guess, used))
	{
		cout << "\nYou've already guessed " << guess << endl;
		cout << "Enter your guess: ";
		cin >> guess;
		guess = toupper(guess);
	}


	//        if (THE_WORD.find(guess) != string::npos)
	if (match(guess, THE_WORD))
	{
		cout << "That's right! " << guess << " is in the word.\n";

		// update soFar to include newly guessed letter
		for (int i = 0; i < THE_WORD.length(); ++i)
			if (THE_WORD[i] == guess)
				soFar[i] = guess;
	}
	else
	{
		cout << "Sorry, " << guess << " isn't in the word.\n";
		++wrong;
	}
}

bool playAgain() // function to play again while clearing system
{
	char again;
	cout << "\n\nWould you like to play again? <y/n>: ";
	cin >> again;

	cin.clear(); //clear and ignore cin
	cin.ignore();

	again = toupper(again);

	system("cls");

	return (again == 'Y');
}