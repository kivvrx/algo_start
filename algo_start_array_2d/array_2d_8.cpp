#include <iostream>
#include <vector>
#include <map>
#include <cmath>

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> field(n, std::vector<int>(m));
    std::map<int, std::vector<std::pair<int, int>>> positions;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            std::cin >> field[i][j];
            positions[field[i][j]].emplace_back(i, j);
        }
    int a, b;
    std::cin >> a >> b;
    --a; --b;
    int x = field[a][b];
    auto& cells = positions[x];
    int max_dist = -1;
    for (auto& p : cells) {
        if (p.first == a && p.second == b) continue;
        int dist = std::abs(p.first - a) + std::abs(p.second - b);
        if (dist > max_dist) max_dist = dist;
    }
    std::cout << (max_dist == -1 ? -1 : max_dist) << "\n";
    return 0;
}