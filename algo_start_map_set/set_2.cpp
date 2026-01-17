// давайте вставим элементы в set которые нам известны знаки а затем 
// не будем вставлять уже встреченные а просто проверять есть ли они в множестве 
// для проверки испольузется хэш таблица для ответа используется красно черное дерево
#include <iostream>
#include <string>
#include <sstream>
#include <unordered_set>
#include <set>
int main() {
	int n;
	std::unordered_set<std::string> s;
	std::cin >> n;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::string line;
	std::getline(std::cin, line);
	std::istringstream iss (line);
	std::string znak;
	while (iss >> znak) {
		s.insert(znak);
	}
	int k;
	std::cin >> k;
	std::string put;
	std::set<std::string> ss;
	for (int i = 0; i < k; ++i) {
		std::cin >> put;
		if (s.count(put)) {
			ss.insert(put);
		}
	}
	if (ss.empty()) {
		std::cout << "None";
	}
	else {
		for (const auto& ss_i : ss) {
			std::cout << ss_i << ' ';
		}
	}
	return 0;
}