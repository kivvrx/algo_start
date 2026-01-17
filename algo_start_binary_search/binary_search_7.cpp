#include <iostream>
#include <vector>
#include <algorithm>
int main() {
	int n;
	std::cin >> n;
	std::vector<int> n_v(n);
	for (auto& a : n_v) std::cin >> a;
	int t;
	std::cin >> t;
	std::vector<int> v;
	while (t--) {
		int x;
		std::cin >> x;
		v.push_back(x);
	}
	for (const auto& vv : v) {
		auto ans = std::upper_bound(n_v.begin(), n_v.end(), vv);
		if (ans == n_v.begin() || *(ans - 1) != vv) {
			std::cout << "Dvoechka\n";
			continue;
		}
		else std::cout << (ans - n_v.begin() - 1) << "\n";
	}
	return 0;
}