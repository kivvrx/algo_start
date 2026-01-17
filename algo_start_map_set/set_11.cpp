#include <unordered_set>
#include <iostream>
int main() {
	std::unordered_set<int> us;
	int n, k;
	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		int n_i;
		std::cin >> n_i;
		us.insert(n_i);
	}
	std::cin >> k;
	for (int i = 0; i < k; ++i) {
		int k_i;
		std::cin >> k_i;
		if (us.count(k_i)) {
			std::cout << "YES\n";
		}
		else {
			std::cout << "NO\n";
			us.insert(k_i);
		}
	}
	return 0;
}