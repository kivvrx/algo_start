#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
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
    std::vector<std::pair<std::string, int>> words(freq.begin(), freq.end());
    std::sort(words.begin(), words.end(), [](const auto& a, const auto& b) {
        if (a.second != b.second)
            return a.second > b.second; // по убыванию частоты
        return a.first < b.first;       // по алфавиту
        });
    for (const auto& [word, count] : words) {
        std::cout << word << ": " << count << "\n";
    }
    return 0;
}
