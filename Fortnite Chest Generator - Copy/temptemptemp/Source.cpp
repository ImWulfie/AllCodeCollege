#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <random>
using namespace std;

std::random_device rd;     // only used once to initialise (seed) engine
std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
std::uniform_int_distribution<int> uni(0, 29); // guaranteed unbiased


int main()
{
	//srand(time(NULL));
	string Chests[29] = { "SLURP", "Mini Shield", "Chug Jug", "Half Shield", "Medkit", "Bandages", "Gold Rocket Launcher", "Purple Rocket Launcher", "Gold Scar",
"Purple Scar", "Gold Silenced Scar", "Purple Silenced Scar", "Blue Assault Rifle", "Green Assault Rifle", "Grey Assault Rifle", "Blue Tactical Shotgun",
"Green Tactical Shotgun", "Grey Tactical Shotgun", "Blue SMG", "Green SMG", "Grey SMG", "Clingers", "Grenade", "Stink Bomb",
"Rockets", "Heavy Ammo", "Medium Ammo", "Light Ammo", "Shells" };

	/*int RandIndex = rand() % 29;
	int RandIndex2 = rand() % 29;
	int RandIndex3 = rand() % 29;
	int RandIndex4 = rand() % 29;
	int RandIndex5 = rand() % 29;*/

	

	cout << Chests[uni(rng)] << endl;
	cout << Chests[uni(rng)] << endl;
	cout << Chests[uni(rng)] << endl;
	cout << Chests[uni(rng)] << endl;
	cout << Chests[uni(rng)] << endl;

	return 0;
}