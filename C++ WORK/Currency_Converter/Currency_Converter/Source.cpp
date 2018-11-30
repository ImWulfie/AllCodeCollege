#include <iostream>
using namespace std;

int main() {
	cout << "WELCOME TO THE CURRENCY EXCHANGE " << endl;
	cout << "          Current rates:         " << endl;
	cout << "      GBP to EUR - 1 : 1.11361   " << endl;
	cout << "      GBP to USD - 1 : 1.29060   " << endl;
	cout << "      GBP to AUD - 1 : 1.74055   " << endl;
	cout << "      GBP to CAD - 1 : 1.68793   " << endl;
	cout << "      GBP to JPY - 1 : 143.210   " << endl;
	cout << "      GBP to ZWD - 1 : 467.060   " << endl;
	cout << "" << endl;
	
	
	float GBP;
	cout << "Please enter the amount in GBP: ";
	cin >> GBP;

	cout << "The Amount in GBP = EUR " << GBP * 1.11361 << endl;
	cout << "" << endl;
	cout << "The Amount in GBP = USD " << GBP * 1.29060 << endl;
	cout << "" << endl;
	cout << "The Amount in GBP = AUD " << GBP * 1.74055 << endl;
	cout << "" << endl;
	cout << "The Amount in GBP = CAD " << GBP * 1.68793 << endl;
	cout << "" << endl;
	cout << "The Amount in GBP = JPY " << GBP * 143.210 << endl;
	cout << "" << endl;
	cout << "The Amount in GBP = ZWD " << GBP * 467.060 << endl;


	system("pause");
}