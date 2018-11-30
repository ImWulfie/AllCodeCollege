#include <iostream>
//function prototype 
void Repeat();
float Validation(int type);

//This is a function that is validation for the users input on the currency amount.
//Here it stops the user from entering a value of above £5500 or less than £1.
float Validation(int type) {
	float val = 0.0f;
	std::cin >> val;

	switch (type) {
	case 0:
		if (val >= 1 && val < 5500) {
			return val;
		}
		else {
			std::cerr << "ERROR: This is too much to do within one conversion (\x9C 1 to \x9C 5500)" << std::endl;
			std::cout << "Please try again" << std::endl;
			Validation(type);
			
			return val;

		}
	}
}


//Here is the menu for the program from here it asks the user for what amount of currency they want to convert
//and then which currency they want the amount to be converted to.
void Currency() {
	std::cout << ""  << std::endl;
	std::cout << "###########################################" << std::endl;
	std::cout << "# WELCOME TO THE CURRENCY EXCHANGE SYSTEM #" << std::endl;
	std::cout << "# The current exchange rates for GBP are; #" << std::endl;
	std::cout << "#          1. GBP - EUR = 1.11361         #" << std::endl;
	std::cout << "#          2. GBP - USD = 1.29060         #" << std::endl;
	std::cout << "#          3. GBP - AUD = 1.74055         #" << std::endl;
	std::cout << "#          4. GBP - CAD = 1.68793         #" << std::endl;
	std::cout << "#          5. GBP - JPY = 143.210         #" << std::endl;
	std::cout << "#          6. GBP - ZWD = 467.060         #" << std::endl;
	std::cout << "###########################################" << std::endl;

	float val;
	std::cout << std::endl;
	std::cout << "   Please Enter the ammount of \x9C you" << std::endl;
	std::cout << "          would like to convert: " << std::endl;
	val = Validation(0);


	int choice = 0;
	std::cout << "Please enter the number of the currency you would like to convert to." << std::endl;
	std::cin >> choice;

	
	//Here the program is taking the users input and then using the correct currency based upon 1-6 input
	//If the input is not 1-6 then the program returns to the beginning and displays an error.
	switch (choice) {
	case 0:
		exit(0);
		break;

	case 1:

		std::cout << "" << std::endl;
		std::cout << "     The Amount in EUR is: " << val * 1.11361 << " EUR" << std::endl;
		Repeat();
		break;

	case 2:

		std::cout << "" << std::endl;
		std::cout << "     The Amount in USD is: " << val * 1.29060 << " USD" << std::endl;
		Repeat();
		break;

	case 3:

		std::cout << "" << std::endl;
		std::cout << "     The Amount in AUD is: " << val * 1.74055 << " AUD" << std::endl;
		Repeat();
		break;

	case 4:

		std::cout << "" << std::endl;
		std::cout << "     The Amount in CAD is: " << val * 1.68793 << " CAD" << std::endl;
		Repeat();
		break;

	case 5:

		std::cout << "" << std::endl;
		std::cout << "     The Amount in JPY is: " << val * 143.210 << " JPY" << std::endl;
		Repeat();
		break;

	case 6:
		std::cout << "" << std::endl;
		std::cout << "     The Amount in ZWD is: " << val * 467.060 << " ZWD" << std::endl;
		Repeat();
		break;
	
	default:
		std::cout <<  "ERROR - UNKNOWN CHOICE" << std::endl;
		return Currency();
		break;

	}
	
	
	std::cout << "" << std::endl;

	Repeat();
}


//This function allows the program to repeat when prompted
void Repeat() {
	char x;
	std::cout << "     Would you like to convert again?" << std::endl;
	std::cin >> x;
	if (x == 'y') {
		system("cls");
		Currency();
	}
	else if (x == 'n') {
		exit(0);
	}
	else {
		std::cout << "ERROR: Unknown response, please enter 'y' or 'n' only!" << std::endl;
		Repeat();
	}
}


//This is where the main program is run - here it calls for another function that is defined above.
int main() {
	Currency();
	return 0;
}

