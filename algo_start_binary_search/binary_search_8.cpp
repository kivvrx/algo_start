#include <iostream>
#include <vector>
#include <algorithm>
int main() {
	int n, t;
	std::cin >> n;
	std::vector<int> a(n);
	for (auto& vv : a) std::cin >> vv;
	std::cin >> t;
	std::vector<int> ans(t);
	for (auto& anss : ans) {
		int l,r;
		std::cin >> l >> r;
		auto it_l = std::lower_bound(a.begin(), a.end(), l);
		auto it_r = std::upper_bound(a.begin(), a.end(), r);
		anss = it_r - it_l;
	}
	for (const auto& j : ans) std::cout << j << '\n';
	return 0;
}