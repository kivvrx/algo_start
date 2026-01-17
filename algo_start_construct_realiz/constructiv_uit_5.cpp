#include <iostream>
#include <vector>
#include <string>

bool is_ok(const std::vector<std::vector<int>>& grid, int i, int j, int h, int w) {
    for (int dx = -1; dx <= 1; ++dx) {
        for (int dy = -1; dy <= 1; ++dy) {
            if (dx == 0 && dy == 0) continue;
            int ni = i + dx;
            int nj = j + dy;
            if (ni >= 0 && ni < h && nj >= 0 && nj < w) {
                if (grid[ni][nj] == 1) return false;
            }
        }
    }
    return true;
}

int main() {
    int t;
    std::cin >> t;
    std::vector<std::vector<std::string>> out;
    while (t--) {
        int h, w;
        std::cin >> h >> w;
        std::vector<std::vector<int>> grid(h, std::vector<int>(w, 0));
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (i == 0 || i == h - 1 || j == 0 || j == w - 1) {
                    if (is_ok(grid, i, j, h, w)) {
                        grid[i][j] = 1;
                    }
                }
            }
        }
        std::vector<std::string> result;
        for (int i = 0; i < h; ++i) {
            std::string row;
            for (int j = 0; j < w; ++j) {
                row += (grid[i][j] ? '1' : '0');
            }
            result.push_back(row);
        }

        out.push_back(result);
    }
    for (const auto& table : out) {
        for (const std::string& row : table) {
            std::cout << row << '\n';
        }
        std::cout << '\n';
    }
    return 0;
}
