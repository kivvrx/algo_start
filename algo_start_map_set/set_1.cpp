#include <iostream>
#include <set>

int main() {
	int n;
	std::cin >> n;
	std::set<int> s;
	for (int i = 0; i < n; ++i) {
		int a;
		std::cin >> a;   
		s.insert(a);     
	}
	for (const auto& a_i : s) {
		std::cout << a_i << ' ';
	}
	return 0;
}