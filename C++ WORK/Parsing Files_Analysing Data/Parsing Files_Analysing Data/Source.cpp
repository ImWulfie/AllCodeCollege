#include<iostream>
#include<fstream>
#include<iterator>
#include<string>
#include<vector>

/*This is defining where the data from the text file will be stored
and in which data type*/
struct user {
	std::string name;
	int age;
	std::string email;
	std::string password;
	std::string address;
	std::string phone;
};
std::vector<user> users;

void PrintUser(int index, int type);
void ReadDatabase();
void Menu();
void BubbleSort(std::vector<user>& users);


void Menu() {
	std::cout << "#################################################" << std::endl;
	std::cout << "----------Welcome to the user database-----------" << std::endl;
	std::cout << "---Please select an option from the list below---" << std::endl;
	std::cout << "--------- 1. Display user's in order of age -------" << std::endl;
	std::cout << "---------- 2. Display name, age & email ---------" << std::endl;
	std::cout << "-- 3. Display name, email, address & phone num --" << std::endl;
	std::cout << "#################################################" << std::endl;
	
	BubbleSort(users);
	int x;
	std::cin >> x;
	for (int i = 0; i < users.size(); i++) {
		PrintUser(i, x);
	}

	
}

std::vector< std::string> split(const std::string& s, char c) {
	std::vector< std::string> v;
	std::string::size_type i = 0;
	std::string::size_type j = s.find(c);

	while (j != std::string::npos) {
		v.push_back(s.substr(i, j - i));
		i = ++j;
		j = s.find(c, j);

		if (j == std::string::npos)
			v.push_back(s.substr(i, s.length()));
	}
	return v;
}

void ReadDatabase() {
	std::ifstream file("dataBase.txt");
	std::string line;
	user temp;
	while (std::getline(file, line)) {
		std::vector<std::string> fields = split(line, ';');
		for (int i = 0; i < fields.size() - 1; i++) {
			temp.name = fields.at(0);
			temp.age = std::stoi(fields.at(1)); //this needs converting to an integer
			temp.email = fields.at(2);
			temp.password = fields.at(3);
			temp.address = fields.at(4);
			temp.phone = fields.at(5); // td::stoi(fields.at(5));
		}
		users.push_back(temp); //finally add the temp user to the users vector
	}
	//this will print out all the users
	/*for (int i = 0; i < users.size(); i++) {
		PrintUser(i, 0);
	}*/
}


void BubbleSort(std::vector<user>& vec){

	bool swap = true;
		while (swap) {
			swap = false;
			for (size_t i = 0; i < vec.size() - 1; i++) {
				if (vec[i].age > vec[i + 1].age) {
					user temp;
					temp = vec[i];
					vec[i] = vec[i + 1];
					vec[i + 1] = temp;
					swap = true;
				}
			}
		}
}

void PrintVector(std::vector<user> vec) {
	for (size_t i = 0; i < vec.size(); i++) {
		std::cout << vec[i].age << ", ";
	}
	std::cout << std::endl;
	

}


void PrintUser(int index, int type) {
	
	
	//type is the printing style required
	switch (type) {
	case 0:
		break;
	
	case 1:

			std::cout << "Name:" << users[index].name << std::endl;
			std::cout << "Age:" << users[index].age << std::endl;
			std::cout << "Email:" << users[index].email << std::endl;
			std::cout << "Address:" << users[index].address << std::endl;
			std::cout << "Phone Num:" << users[index].phone << std::endl;
			std::cout << "" << std::endl;
		break;

	case 2:
		std::cout << "Name:" << users[index].name << std::endl;
		std::cout << "Age:" << users[index].age << std::endl;
		std::cout << "Email:" << users[index].email << std::endl;
		std::cout << "" << std::endl;
		break;
	case 3:
		std::cout << "Name:" << users[index].name << std::endl;
		std::cout << "Email:" << users[index].email << std::endl;
		std::cout << "Address:" << users[index].address << std::endl;
		std::cout << "Phone Num:" << users[index].phone << std::endl;
		std::cout << "" << std::endl;
		break;
	default: 
		std::cout << "Unknown print type" << std::endl;
		break;
	}
	



}

int main(int argc, char* argv[]) {
	ReadDatabase();
	Menu();
	BubbleSort(users);
	//PrintVector(users);
	//for (int i = 0; i < users.size(); i++) {
	//	PrintUser(i, 0);
	//}

	system("PAUSE");
	return 0;

}