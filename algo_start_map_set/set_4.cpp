#include <string>
#include <iostream>
#include <cctype>
#include <unordered_set>
#include <set>
int main() {
	std::string s;
	std::getline(std::cin, s);
	std::unordered_set<char> later;
	for (int i = 0; i < s.size(); ++i) {
		if (isalpha(s[i])) {
			later.insert(s[i]);
		}
	}
	if (later.size() == 52) {
		std::cout << "Already open";
		return 0 ;
	}
	// на этом моменте мы узнали то что знали теперь нужно посмотреть каких символов 
	// нету в множестве later это и будет ответ 
	// A - 65
	// Z - 90
	// a - 97
	// z - 122 будем прибавлять к A сначала 0 потом 1 потом 2 и так далее получится алфавит
	int i = 0;
	std::set<char> ss;
	while ('a' + i != 'z' + 1) {
		ss.insert('a' + i);
		ss.insert('A' + i);
		++i;
	}
	for (char l : later) {
		ss.erase(l);
	}

	for (const auto& s_i : ss) {
		std::cout << s_i << ' ';
	}
	return 0;
}