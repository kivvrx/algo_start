#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

bool is_valid(char c) {
    return std::isalnum(static_cast<unsigned char>(c)) ||
        std::string(".!?:-,;()").find(c) != std::string::npos;
}
int main() {
    int n;
    std::cin >> n;
    std::cin.ignore();
    std::vector<int> cnt(256, 0);
    for (int i = 0; i < n; ++i) {
        std::string line;
        std::getline(std::cin, line);
        for (char c : line) {
            if (is_valid(c)) {
                cnt[static_cast<unsigned char>(c)]++;
            }
        }
    }
    std::vector<char> chars;
    chars.reserve(256);
    for (int i = 0; i < 256; ++i) {
        if (cnt[i] > 0) chars.push_back(static_cast<char>(i));
    }
    std::sort(chars.begin(), chars.end());
    for (char c : chars) std::cout << c;
    std::cout << '\n';
    int max_height = 0;
    for (char c : chars) {
        max_height = std::max(max_height, cnt[static_cast<unsigned char>(c)]);
    }
    for (int row = 1; row <= max_height; ++row) {
        for (char c : chars) {
            std::cout << (cnt[static_cast<unsigned char>(c)] >= row ? '#' : ' ');
        }
        std::cout << '\n';
    }
    return 0;
}
