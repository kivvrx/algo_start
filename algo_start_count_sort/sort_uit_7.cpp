#include <iostream>
#include <vector>

int main() {
    int t;
    std::cin >> t;
    std::vector<std::string> results;
    results.reserve(t);
    for (int _ = 0; _ < t; ++_) {
        int n;
        std::cin >> n;
        std::vector<int> freq(100, 0);
        for (int i = 0; i < n; ++i) {
            int x;
            std::cin >> x; // 0 <= x < 100
            ++freq[x];
        }
        bool ok = true;
        // должно быть хотя бы одно начало ряда
        if (freq[0] == 0) ok = false;
        // частоты невозрастающие
        for (int x = 1; x < 100 && ok; ++x) {
            if (freq[x] > freq[x - 1]) {
                ok = false;
            }
        }
        results.push_back(ok ? "YES" : "NO");
    }
    for (const auto& s : results) {
        std::cout << s << "\n";
    }
    return 0;
}
