#include <iostream>
#include <vector>
#include <set>
struct coord {
	int a, b;
	bool operator< (const coord& other) const {
		if (a != other.a) return a < other.a;
		return b < other.b;
	}
};

int main() {
	int n, m;
	std::cin >> n >> m;
	// вектор 0 1 внутри нуля 0 внутри 1 число 
	// 0 не попал 1 попал
	std::vector<std::vector<int>> n_m(n + 1, std::vector<int>(m + 1, 0));
	int k;
	std::cin >> k;
	for (int i = 0; i < k; ++i) {
		int a, b;
		std::cin >> a >> b;
		 n_m[a][b] = 1;
	}
	std::set<coord> ans;
	for (int i = 1; i < n + 1; ++i) {
		for (int j = 1; j < m + 1; ++j) {
			if (n_m[i][j] == 0) {
				ans.insert({ i, j });
			}
		}
	}
	if (ans.empty()) {
		std::cout << "Dead field\n";
	}
	else {
		for (auto& c : ans) {
			std::cout << c.a << " " << c.b << "\n";
		}
	}


	return 0;
}