#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::cin.ignore();
    std::vector<int> cnt(256, 0);
    for (int i = 0; i < n; i++) {
        std::string line;
        std::getline(std::cin, line);
        for (char c : line) {
            if (c != ' ') { 
                cnt[(unsigned char)c]++;
            }
        }
    }
    std::vector<char> chars;
    for (int i = 0; i < 256; i++) {
        if (cnt[i] > 0) chars.push_back((char)i);
    }
    // максимальная высота
    int max_height = 0;
    for (char c : chars) {
        max_height = std::max(max_height, cnt[(unsigned char)c]);
    }
    // печатаем сверху вниз
    for (int row = max_height; row >= 1; row--) {
        for (char c : chars) {
            if (cnt[(unsigned char)c] >= row) std::cout << '#';
            else std::cout << ' ';
        }
        std::cout << '\n';
    }
    for (char c : chars) std::cout << c;
    std::cout << '\n';

    return 0;
}
