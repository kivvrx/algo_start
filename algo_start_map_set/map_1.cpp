#include <iostream>
#include <map>
#include <string>

int main() {
    int n;
    std::cin >> n;
    std::map<std::string, int> freq;
    for (int i = 0; i < n; ++i) {
        std::string word;
        std::cin >> word;
        ++freq[word];
    }
    for (const auto& [word, count] : freq) {
        std::cout << word << ": " << count << "\n";
    }
    return 0;
}
