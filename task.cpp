#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <functional>

int main() {
//	std::ifstream file("input.txt");

	// Чтение из файла
	std::vector<int> vec;
	int num;
	while (file >> num) {
		vec.push_back(num);
	}

	// Реверсирование последовательности элементов вектора
	std::reverse(vec.begin(), vec.end());

	// Нахождение минимального элемента
	auto min_it = *std::min_element(vec.begin(), vec.end());
	std::cout << "Минимальный элемент: " << min_it << std::endl;

	// Удаление из вектора всех четных элементов
	vec.erase(std::remove_if(vec.begin(), vec.end(), [](int num) { return num % 2 == 0; }), vec.end());

	// Сортировка вектора в убывающей последовательности
	std::sort(vec.begin(), vec.end(), std::greater<int>());

	// Вставка в вектор произвольного элемента, не нарушая сортировку
	vec.insert(std::lower_bound(vec.begin(), vec.end(), 10), 15);

	// Определение индекса заданного элемента
	auto it = std::find(vec.begin(), vec.end(), 10);
	std::cout << "Индекс элемента 10: " << it - vec.begin() << std::endl;

	// Удаление дублированных элементов
	vec.erase(std::unique(vec.begin(), vec.end()), vec.end());

	// Вывод результата
	std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;

	return 0;
}