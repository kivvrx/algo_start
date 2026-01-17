#include <iostream>
#include <map>

int main() {
    char inp;
    std::map<char, int> digit;
    std::map<char, int> alpha;
    while (std::cin.get(inp)) {
        if (inp == '\n') break;
        if (isalpha(static_cast<unsigned char>(inp))) alpha[inp]++;
        if (isdigit(static_cast<unsigned char>(inp))) digit[inp]++;
    }
    for (auto it = alpha.rbegin(); it != alpha.rend(); ++it) {
        for (int i = 0; i < it->second; ++i) {
            std::cout << it->first;
        }
    }
    for (const auto& [key, value] : digit) {
        for (int i = 0; i < value; ++i) {
            std::cout << key;
        }
    }
    return 0;
}
