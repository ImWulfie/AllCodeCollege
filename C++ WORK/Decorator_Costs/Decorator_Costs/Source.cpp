#include <iostream>
void Repeat();
float Validation(int type);
void CalculateCost(float);

//This is a function for validating input from the user so that is inbetween two designated boundaries.//
float Validation(int type) {
	float val = 0.0f;
	std::cin >> val;

	/*
	Here the program is going through the possibilites of what can be entered in order of apperance length then height for 
	the wall and the window
	*/
	switch (type) {
	case 0: 
		if (val >= 1 && val <= 25) {
			return val;
		}
		else {
			std::cerr << "ERROR: value must be between 1 and 25!" << std::endl;
			Validation(0);
		}
		break;
	case 1:
		if (val >= 2.4 && val <= 6) {
			return val;
		}
		else {
			std::cerr << "ERROR: value must be between 2.4 and 6!" << std::endl;
			Validation(1);
		}
		break;
	case 2:
		if (val > 0.8 && val <= 2) {
			return val;
		}
		else {
			std::cerr << "ERROR: value must be between 0.9 and 2!" << std::endl;
			Validation(2);
		}
		break;
	case 3:
		if (val > 0.8 && val <= 1.5) {
			return val;
		}
		else {
			std::cerr << "ERROR: value must be between 0.9 and 1.5!" << std::endl;
			Validation(3);
		}
		break;
	default: std::cout << "default case" << std::endl;
		break;
	}

}




/*
Here is the validation for the main menu where it only accepts values that will set the bool to true
those being 1, 2 & 3. If an entered integer that is not those 3 then the program will not accept said int
and it will error and ask for another input
*/
int ChoiceValidate() {
	int temp = 0;
	bool valid = false;
	while (!valid) {
		if (std::cin >> temp) {
			valid = true;
			break;
		}
		else {
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
			std::cout << "Invalid choice, please re-enter!" << std::endl;
		}
	}
	return temp;
}


int main() {

	std::cout << "Welcome to the decorator calculator" << std::endl;
	std::cout << "" << std::endl;
	std::cout << "    Please choose from the list    " << std::endl;
	std::cout << "   which type of paint you require " << std::endl;
	std::cout << "" << std::endl;
	std::cout << "   1. Luxury = \x9C 1.75 per sq/m   " << std::endl;
	std::cout << "   2. Standard = \x9C 1.00 per sq/m   " << std::endl;
	std::cout << "   3. Economy = \x9C 0.80 per sq/m   " << std::endl;

	int choice = ChoiceValidate();
	
	/*
	Below we have the switch case which takes the input from "choice" and it goes through each case to see if the correct number
	has been entered, if not it errors and asks for another input from the user. If 1 is entered then "Case 1" will be selected,
	2 = Case 2 etc.
	
	Here it also assigns how much to multiply the total cost by based upon the users requirements. 
	Case 1 being 1.75
	Case 2 being 1.00
	Case 3 being 0.80
	*/

	switch (choice) {

	case 0:
		exit(0);
		break;

	case 1: {
		std::cout << "You have selected Luxury" << std::endl;
		CalculateCost(1.75);
	}

	case 2: {
		std::cout << "You have selected Standard" << std::endl;
		CalculateCost(1.0);
	}
	case 3: {
		std::cout << "You have selected Economy" << std::endl;
		CalculateCost(0.8);
	}

	default: {
		std::cout << "Invalid Input!" << std::endl;
		system("cls");
		main();
	}
	}

}


/*
Here we have the function that calcuates the cost of the room based upon a series of user inputs that are validated
by the Validation() function
*/
void CalculateCost(float paintChoice) {
	float length, height, area;

	std::cout << "Enter the total length of the room in m (minimum 1m and maximum 25m) : ";
	length = Validation(0);

	std::cout << "Enter the total height of the room in m (between 2.4m and 6m): ";
	height = Validation(1);

	// Formula to calculate area of the room
	area = length * height;
	std::cout << "Area of the room in meters: " << area << std::endl;

	char y;
	std::cout << "Do you have a window? y/n" << std::endl;
	std::cin >> y;
	if (y == 'y') {

		float WindowLength;
		std::cout << "Please enter the length of the window (minimum 0.9m, maximum 2.0m)" << std::endl;
		WindowLength = Validation(2);

		float WindowHeight;
		std::cout << "Please enter the height of the window (minimum 0.9, maximum 1.5m)" << std::endl;
		WindowHeight = Validation(3);

		//Formula to calculate area of the window
		float TotalWindow;
		TotalWindow = WindowHeight * WindowLength;

		//formula to calcualte the new total area, with the window area subtracted
		area = area - TotalWindow;
	}


	
	printf("The current price for this room is: \x9C %.2f\n", area * paintChoice);
	float area2;
	area2 = area * paintChoice;


	/*Here is the function for whether the user would like an undercoat.
	The function itself is simple and validates the users input*/
	char x;
	std::cout << "Would you like to add an undercoat? y/n" << std::endl;
	std::cin >> x;
	if (x == 'y') {
		float area3;
		area3 = area * 0.45;
		
		printf("Your new total is : \x9C %.2f", area2+area3);
		Repeat();
	}
	else if (x == 'n') {
		std::cout << "Your total for this room is: \x9C" << area2 << std::endl;
		Repeat();
	}

	else (x == not 'y' or 'n'); {
		std::cout << "### FATAL ERROR! Restarting... ###" << std::endl;
		system("cls");
		main();
	}

}


/*This is the repeat function, that allows the user to exit or restart the program*/
void Repeat() {
	char x;
	std::cout << "     Would you like to use the calculator again?" << std::endl;
	std::cin >> x;
	if (x == 'y') {
		system("CLS");
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
