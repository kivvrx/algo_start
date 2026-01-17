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
    int k;
    std::cin >> k;
    std::map<char, char> mapping;
    for (int i = 0; i < k; ++i) {
        char a, b;
        std::cin >> a >> b;
        mapping[a] = b;
        mapping[b] = a;
    }
    for (size_t i = 0; i < s.size(); ++i) {
        if (s[i] == t[i]) continue;
        if (mapping[s[i]] == t[i]) continue;
        if (mapping[t[i]] == s[i]) continue;
        std::cout << "NO\n";
        return 0;
    }
    std::cout << "YES\n";
    return 0;
}
