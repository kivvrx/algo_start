#include <iostream>
#include <vector>

int main() {
	int N;
	std::cin >> N;
	std::vector<std::vector<int>> matrix(N, std::vector<int>(N, 0));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			int N_i_j;
			std::cin >> N_i_j;
			matrix[i][j] = N_i_j;
		}
	}
	if (matrix.size() < 2) {
		std::cout << "Lucky";
		return 0;
	}
	//если например 2 на 2 то
	// 2 2        1-элемент нулевой значит идет не включая N 
	// 2 2
	std::vector<std::pair<int, int>> ans;
	for (int i = 0; i < N; ++i) {
		std::pair<int, int> p = { i,i };
		int step = 1;
		while (p.first + step != N) {
			auto l = matrix[p.first][p.second + step];
			auto r = matrix[p.first + step][p.second];
			if (l != r) {
				ans.emplace_back(std::make_pair(l, r));
			}
			++step;
		}
	}
	if (ans.empty()) {
		std::cout << "Lucky";
		return 0;
	}
	for (const auto& anss : ans) {
		std::cout << anss.first << ' ' << anss.second << '\n';
	}
	return 0;
}