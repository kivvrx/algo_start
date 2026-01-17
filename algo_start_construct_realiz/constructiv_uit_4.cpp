#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int main() {
    int t;
    std::cin >> t;
    std::vector<std::string> out;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<std::pair<int, int>> pairs(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> pairs[i].first; // a_i
        }
        for (int i = 0; i < n; ++i) {
            std::cin >> pairs[i].second; // b_i
        }
        std::sort(pairs.begin(), pairs.end()); // сортируем по a_i
        std::string a_line, b_line;
        for (int i = 0; i < n; ++i) {
            a_line += std::to_string(pairs[i].first);
            b_line += std::to_string(pairs[i].second);
            if (i + 1 < n) {
                a_line += ' ';
                b_line += ' ';
            }
        }
        out.push_back(a_line);
        out.push_back(b_line);
    }
    for (const std::string& line : out) {
        std::cout << line << '\n';
    }

    return 0;
}
