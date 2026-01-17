#include <iostream>
#include <vector>
#include <string>

int main() {
    int t;
    std::cin >> t;
    std::vector<std::string> answers;   
    answers.reserve(t);                 
    while (t--) {
        int n, m;
        std::cin >> n >> m;
        std::vector<std::string> grid(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> grid[i];
        }
        int min_i = n, min_j = m;
        std::vector<std::pair<int, int>> robots;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 'R') {
                    robots.emplace_back(i, j);
                    if (i < min_i || (i == min_i && j < min_j)) {
                        min_i = i;
                        min_j = j;
                    }
                }
            }
        }
        bool ok = true;
        for (const auto& robot : robots) {
            if (robot.first < min_i || robot.second < min_j) {
                ok = false;
                break;
            }
        }
        answers.push_back(ok ? "YES" : "NO");
    }
    for (const auto& ans : answers) {
        std::cout << ans << '\n';
    }
    return 0;
}
