#include <iostream>
#include <set>
int main() {
	int n, x;
	std::cin >> n >> x;
	std::set<int> s;
	for (int i = 0; i < n; ++i) {
		int n_i;
		std::cin >> n_i;
		s.insert(n_i);
	}
	auto l = s.begin();
	auto r = --(s.end());
	bool b = false;
	while (r != l) {
		auto sum = *l + *r;
		if ((sum == x)) {
			std::cout << "YES";
			b = true;
			break;
		}
		else if (sum < x) ++l;
		else --r;
	}
	if (!b) std::cout << "NO";
	return 0;
}