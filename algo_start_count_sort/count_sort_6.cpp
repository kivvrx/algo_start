#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <cctype>

int main() {
    std::string s;
    std::getline(std::cin, s);
    std::unordered_map<std::string, int> bigram_count;
    std::string word;
    /*Did you see how great I was ? I did all kinds of really amazing moves... are you listening ?*/
    for (char ch : s) {
        if (std::isalpha(ch)) {
            word += std::tolower(ch);
        }
        else {
            if (word.size() >= 2) {
                for (size_t i = 0; i + 1 < word.size(); ++i) {
                    std::string bigram = word.substr(i, 2);
                    ++bigram_count[bigram];
                }
            }
            word.clear();
        }
    }
    if (word.size() >= 2) {
        for (size_t i = 0; i + 1 < word.size(); ++i) {
            std::string bigram = word.substr(i, 2);
            ++bigram_count[bigram];
        }
    }
    std::string result;
    int max_count = 0;
    for (const auto& [bigram, count] : bigram_count) {
        if (count > max_count || (count == max_count && bigram > result)) {
            max_count = count;
            result = bigram;
        }
    }
    if (!result.empty()) {
        std::cout << result;
    }
    return 0;
}