#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <functional>

int main() {
//	std::ifstream file("input.txt");

	// ������ �� �����
	std::vector<int> vec;
	int num;
	while (file >> num) {
		vec.push_back(num);
	}

	// �������������� ������������������ ��������� �������
	std::reverse(vec.begin(), vec.end());

	// ���������� ������������ ��������
	auto min_it = *std::min_element(vec.begin(), vec.end());
	std::cout << "����������� �������: " << min_it << std::endl;

	// �������� �� ������� ���� ������ ���������
	vec.erase(std::remove_if(vec.begin(), vec.end(), [](int num) { return num % 2 == 0; }), vec.end());

	// ���������� ������� � ��������� ������������������
	std::sort(vec.begin(), vec.end(), std::greater<int>());

	// ������� � ������ ������������� ��������, �� ������� ����������
	vec.insert(std::lower_bound(vec.begin(), vec.end(), 10), 15);

	// ����������� ������� ��������� ��������
	auto it = std::find(vec.begin(), vec.end(), 10);
	std::cout << "������ �������� 10: " << it - vec.begin() << std::endl;

	// �������� ������������� ���������
	vec.erase(std::unique(vec.begin(), vec.end()), vec.end());

	// ����� ����������
	std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;

	return 0;
}