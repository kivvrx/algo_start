#include <iostream>
#include <string>
#include <map>
#include <algorithm>
//aaaabkkabbbbc
// должна быть максимальная встречаемость в массиве и минимальна по лексикографически 
// тоесть если выбирать между a и b то a меньше 
int main() {
    std::string s;
    std::cin >> s;
    std::map<char, int> alphabet;
    for (char c = 'a'; c <= 'z'; ++c) {
        alphabet[c] = 0;
    }
    int l=0, r = 0;
    while (l != s.size() && r != s.size()) {
        while (r != s.size() && s[l] == s[r]) {
            ++r;
      }
        ++alphabet[s[l]];
        l = r;
    }
    auto it = std::max_element(
        alphabet.begin(), alphabet.end(),
        [](const auto& a, const auto& b) {
            return a.second < b.second;
        }
    );

    char ans = it->first;     // буква
    int max_count = it->second; // количество
    std::cout << ans << "\n";
}

