#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <sstream>
int main() {
	int k;
	std::cin >> k;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::string s;
	std::getline(std::cin, s);
	std::set<char> ch;
	std::vector<char> sbit;
	for (int i = 0; i < s.size(); ++i) {
		if (!isspace(s[i])) {
			ch.insert(s[i]);
		}
		if (ch.size() > k) {
			sbit.push_back(s[i]);
			ch.clear();
			ch.insert(s[i]);
		}
	}
	if (sbit.empty()) std::cout << "Victory";
	for (const auto& v : sbit) {
		std::cout << v << ' ';
	}
	return 0;
}