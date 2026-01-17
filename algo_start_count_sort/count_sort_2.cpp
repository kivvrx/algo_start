#include <iostream>
#include <vector>
#include <string>

int main() {
    std::string s, t;
    std::cin >> s >> t;
    if (s.size() != t.size()) {
        std::cout << "NO\n";
        return 0;
    }
    std::vector<int> cnt(256, 0);
    for (char c : s) cnt[(unsigned char)c]++;
    for (char c : t) cnt[(unsigned char)c]--;
    for (int x : cnt) {
        if (x != 0) {
            std::cout << "NO\n";
            return 0;
        }
    }
    std::cout << "YES\n";
    return 0;
}
