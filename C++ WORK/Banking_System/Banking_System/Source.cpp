#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <random>
#include "windows.h."


float balance = 500.0f; 
unsigned int accountNumber;
void account_num();
unsigned int SortCode;
void sort_code();


void Repeat();

void account_num() {
	int Random[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	std::cout << "Generating Account Number..." << std::endl;
	Sleep(5);
	std::cout << "Processing" << std::endl;
	
	std::cout << "" << std::endl;
	std::cout << "Below is your account number" << std::endl;

	int i; /* counter */
	/* loop 20 times */
	for (i = 1; i <= 6; i++) {
		/* pick random number from 1 to 6 and output it */
		printf("%d ", 1 + (rand() % 6));
	}
	std::cout << "" << std::endl;
	
	sort_code();
}


void sort_code() {
	int Random[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	std::cout << "Generating Sort Code..." << std::endl;
	Sleep(5);
	std::cout << "Processing" << std::endl;

	std::cout << "" << std::endl;
	std::cout << "Below is your sort code" << std::endl;

	int i; /* counter */
	/* loop 20 times */
	for (i = 1; i <= 8; i++) {
		/* pick random number from 1 to 8 and output it */
		printf("%d ", 1 + (rand() % 6));
	}

	Repeat();
}


void Bank() {

	std::cout << "" << std::endl;
	std::cout << "___________________________________________" << std::endl;
	std::cout << "|       WELCOME TO THE BANKING SYSTEM     |" << std::endl;
	std::cout << "|      Do you already have an account?    |" << std::endl;
	std::cout << "|                 1. Yes                  |" << std::endl;
	std::cout << "|                 2. No                   |" << std::endl;
	std::cout << "|_________________________________________|" << std::endl;

	int choice = 0;
	std::cin >> choice;

		switch (choice) {
		case 0:
			exit (0);
			break;

		case 1:
		{
			std::cout << "What would you like to do?" << std::endl;
			std::cout << "1. Deposit" << std::endl;
			std::cout << "2. Withdraw" << std::endl;
			std::cout << "3. Check Balance" << std::endl;
			std::cout << "4. Exit" << std::endl;

			int Operation = 0;
			std::cin >> Operation;

			switch (Operation) {
			case 0:
				return Bank();
				break;

			case 1:
				float Deposit;
				std::cout << "Please enter the amount you would like to deposit" << std::endl;
				std::cin >> Deposit;
				balance += Deposit;
				std::cout << "Your new balance is: " << balance << std::endl;
				std::cout << "" << std::endl;
				Repeat();
				break;

			case 2:
				float Withdraw;
				std::cout << "Please enter the amount you would like to withdraw" << std::endl;
				std::cin >> Withdraw;
				balance -= Withdraw;
				std::cout << "Your new balance is: " << balance << std::endl;
				std::cout << "" << std::endl;
				Repeat();
				break;

			case 3:
				std::cout << "Your balance is: " << balance << std::endl;
				Repeat();
				break;


			case 4:
				system("pause");
				break;

			default:
				std::cout << "ERROR - UNKNOWN CHOICE" << std::endl;
				break;

			}
		}
			break; //case 1 break
		case 2:
			account_num();

			
		break;
      	default:
			break;
		}


}

void Repeat() {
	char x;
	std::cout << "     Would you like to do something else?" << std::endl;
	std::cin >> x;
	if (x == 'y') {
		Bank();
	}
	else if (x == 'n') {
		exit(0);
	}
	else {
		std::cout << "ERROR: Unknown response, please enter 'y' or 'n' only!" << std::endl;
		Repeat();
	}
}

int main() {
	Bank();
	return 0;
}