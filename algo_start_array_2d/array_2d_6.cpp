#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N, M;
    std::cin >> N >> M;
    std::vector<std::vector<int>> a(N, std::vector<int>(M));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            std::cin >> a[i][j];
    int P, Q;
    std::cin >> P >> Q;
    std::vector<int> ans;
    for (int i = 0; i + P - 1 < N; ++i) {
        for (int j = 0; j + Q - 1 < M; ++j) {
            int row = i;
            int column = j;
            int anss = 0;
            // идём по всем строкам подматрицы
            while (row <= i + P - 1) {
                anss += a[row][column];
                ++column;
                if (column > j + Q - 1) {
                    ++row;
                    column = j;
                }
            }

            ans.push_back(anss);
        }
    }
    std::cout << *std::max_element(ans.begin(), ans.end()) << "\n";
    return 0;
}
