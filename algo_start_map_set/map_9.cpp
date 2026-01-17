#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    std::string s;
    int k;
    std::cin >> s >> k;
    std::map<char, int> freq;
    for (char ch : s) {
        ++freq[ch];
    }
    std::vector<char> result;
    for (const auto& [ch, count] : freq) {
        if (count == k) {
            result.push_back(ch);
        }
    }
    if (result.empty()) {
        std::cout << "Sad\n";
    }
    else {
        std::sort(result.rbegin(), result.rend()); // убывание
        for (char ch : result) {
            std::cout << ch << " ";
        }
        std::cout << "\n";
    }
    return 0;
}
