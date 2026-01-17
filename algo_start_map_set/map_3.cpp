#include <iostream>
#include <unordered_map>
#include <string>

int main() {
    std::string s;
    std::cin >> s;
    int n;
    std::cin >> n;
    std::unordered_map<char, int> price;
    for (int i = 0; i < n; ++i) {
        int k, p;
        std::cin >> k >> p;
        for (int j = 0; j < k; ++j) {
            char ch;
            std::cin >> ch;
            price[ch] = p;
        }
    }
    int total = 0;
    for (char ch : s) {
        total += price[ch];
    }
    std::cout << total;
    return 0;
}
