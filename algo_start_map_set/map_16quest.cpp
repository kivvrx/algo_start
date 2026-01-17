#include <iostream>
#include <string>
#include <unordered_map>

int main() {
    std::string q, s;
    std::cin >> q >> s;
    std::unordered_map<char, char> mirror;
    for (int i = 0; i < 26; ++i) {
        mirror[q[i]] = q[25 - i];
    }
    for (char c : s) {
        std::cout << mirror[c];
    }
    return 0;
}