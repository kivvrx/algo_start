#include <iostream>
#include <string>
#include <map>
#include <vector>

int main() {
    std::string s;
    int k;
    std::cin >> s >> k;
    std::map<char, std::vector<int>> positions;
    std::vector<bool> removed(s.size(), false);
    for (int i = 0; i < s.size(); ++i) {
        positions[s[i]].push_back(i);
    }
    for (auto& [ch, vec] : positions) {
        for (int idx : vec) {
            if (k == 0) break;
            removed[idx] = true;
            --k;
        }
        if (k == 0) break;
    }
    bool empty = true;
    for (int i = 0; i < s.size(); ++i) {
        if (!removed[i]) {
            std::cout << s[i];
            empty = false;
        }
    }
    if (empty) {
        std::cout << "Empty string";
    }
    return 0;
}
