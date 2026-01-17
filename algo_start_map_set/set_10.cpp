#include <iostream>
#include <unordered_set>
#include <set>
#include <vector>
int main() {
	int n, k;
	std::cin >> n;
	std::set<int> s;
	std::unordered_set<int> s_n;
	for (int i = 0; i < n; ++i) {
		int n_i;
		std::cin >> n_i;
		s_n.insert(n_i);
		s.insert(n_i);
	}
	std::cin >> k;
	std::unordered_set<int> s_k;
	for (int i = 0; i < k; ++i) {
		int k_i;
		std::cin >> k_i;
		s_k.insert(k_i);
		s.insert(k_i);
	}
	std::vector<int> v;
	for (auto ss : s) {
		if ((!s_n.count(ss) && s_k.count(ss)) || (s_n.count(ss) && !s_k.count(ss))) v.push_back(ss);
	}
	for (auto vv : v) {
		std::cout << vv << ' ';
	}
	return 0;
}