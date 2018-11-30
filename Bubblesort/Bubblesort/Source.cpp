#include <iostream>
#include <vector>

void BubbleSort(std::vector<int>& a);
void PrintVector(std::vector<int> a);

int main(int argc, char const *argv[]) {

	std::vector<int> a { 3, 2, 100, 10 };

	PrintVector(a);
	BubbleSort(a);
	PrintVector(a);


}

void BubbleSort(std::vector<int>& a) {

	bool swap = true;
	while (swap) {
		swap = false;
		for (size_t i = 0; i < a.size() - 1; i++) {
			if (a[i] > a[i + 1]) {
				int temp = a[i];
				a[i] = a[i + 1];
				a[i + 1] = temp;
				swap = true;
			}
		}
	}
}


void PrintVector(std::vector<int> a) {
	for (size_t i = 0; i < a.size(); i++) {
		std::cout << a[i] << " ";
	}
	std::cout << std::endl;
	system("PAUSE");
}