#include<iostream>
#include<fstream>
#include<iterator>
#include<string>
#include<vector>

void PrintTemp(int index, int type);
void ReadTemperature();


struct temperature {
	float Temperature;
	float Relative_Humidity;
	float Air_Pressure;
	float LocationLat;
	float LocationLon;
	std::string LocationSource;
	std::string Timestamp;
};
std::vector<temperature> users;

std::vector<std::string> split(const std::string& s, char c) {
	std::vector<std::string> v;
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

void ReadTemperature() {
	std::ifstream file("data.csv");
	file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::string line;
	temperature temp;
	while (std::getline(file, line)) {
		std::vector<std::string> fields = split(line, ',');
		for (int i = 0; i < fields.size() ; i++) {
			temp.Temperature = std::stof(fields.at(0));
			temp.Relative_Humidity = std::stof(fields.at(1));
			temp.Air_Pressure = std::stof(fields.at(2));
			temp.LocationLat = std::stof(fields.at(3));
			temp.LocationLon = std::stof(fields.at(4));
			temp.LocationSource = fields.at(5);
			temp.Timestamp = fields.at(6);
		}
		users.push_back(temp);
	}
	for (int i = 0; i < users.size(); i++) {
		PrintTemp(i, 0);
	}
}

void PrintTemp(int index, int type) {
	
	switch (type) {
	case 0:
		std::cout << "This data was taken on: " << users[index].Timestamp << std::endl;
		std::cout << "Temperature: " << users[index].Temperature << std::endl;
		std::cout << "Relative Humidity: " << users[index].Relative_Humidity << std::endl;
		std::cout << "Air Pressure: " << users[index].Air_Pressure << std::endl;
		std::cout << "Location - Latitude: " << users[index].LocationLat << std::endl;
		std::cout << "Location - Longitude: " << users[index].LocationLon << std::endl;
		std::cout << "Location Source: " << users[index].LocationSource << std::endl;
		std::cout << "\n";
		break;

	default:
		std::cout << "Unknown print type" << std::endl;
		break;
	}
}

int main(int argc, char* argv[]) {
	ReadTemperature();
	system("PAUSE");
	return 0;
}