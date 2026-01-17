#include <iostream>
#include <string>
#include <sstream>
#include <unordered_set>
#include <set>
int main() {
	int n;
	std::unordered_set<std::string> s;
	std::unordered_set<std::string> ss;
	std::cin >> n;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::string line;
	std::getline(std::cin, line);
	std::istringstream iss(line);
	std::string znak;
	while (iss >> znak) {
		s.insert(znak);
	}
	int k,m;
	std::cin >> k >> m;
	std::string put;
	int ans = 0;
	for (int i = 0; i < k; ++i) {
		std::cin >> put;
		if (s.count(put) && !ss.count(put)) {
			ss.insert(put);
			ans += m;
		}
	}
	std::cout << ans;
	return 0;
}