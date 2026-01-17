#include <iostream>
#include <unordered_map>
#include <vector>
int main() {
	int n, k;
	std::cin >> n >> k;
	std::unordered_map<int, int> check;
	std::vector<int> inp(n);
	for (auto& i : inp) std::cin >> i;
	// 10 4
	// 7 8 1 1 - 1000 20 21 1 20 2
	for (int i = 0; i < n; ++i) {
		if (check.count(inp[i])) {
			auto chk = i - check[inp[i]];
			if (chk <= k) {
				std::cout << "NO";
				return 0;
			}
			check[inp[i]] = i;
		}
		else check[inp[i]] = i;
	}
	std::cout << "YES";
	return 0;
}