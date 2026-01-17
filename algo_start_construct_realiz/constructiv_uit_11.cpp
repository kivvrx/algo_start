#include <iostream>
#include <string>
#include <vector>

int main() {
    int t;
    std::cin >> t;
    std::vector<std::string> results;
    results.reserve(t);
    while (t--) {
        int n, k;
        std::cin >> n >> k;
        std::string s;
        std::cin >> s;
        bool ok = true;
        // 1) середина должна быть непустой
        if (2 * k >= n) {
            ok = false;
        }
        else {
            // 2) первые k символов должны совпадать с последними k в зеркальном порядке
            for (int i = 0; i < k; ++i) {
                if (s[i] != s[n - 1 - i]) {
                    ok = false;
                    break;
                }
            }
        }
        results.push_back(ok ? "YES" : "NO");
    }
    for (const auto& res : results) {
        std::cout << res << '\n';
    }
    return 0;
}

