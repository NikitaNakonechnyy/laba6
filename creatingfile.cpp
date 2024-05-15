#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
	vector<int> numbers;

	// Добавление элементов в вектор
	numbers.push_back(1);
	numbers.push_back(2);
	numbers.push_back(3);
	numbers.push_back(4);
	numbers.push_back(5);

	// Запись вектора в файл
	ofstream file("input.txt");
	for (int number : numbers) {
		file << number << " ";
	}
	file.close();

	return 0;
}