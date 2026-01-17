#include <iostream>
#include <map>
#include <string>
int main() {
    std::string s, t;
    std::cin >> s >> t;
    if (s.size() != t.size()) {
        std::cout << "NO\n";
        return 0;
    }
    std::map<char, int> freq_s, freq_t;
    for (char ch : s) ++freq_s[ch];
    for (char ch : t) ++freq_t[ch];

    if (freq_s == freq_t) {
        std::cout << "YES\n";
    }
    else {
        std::cout << "NO\n";
    }
    return 0;
}