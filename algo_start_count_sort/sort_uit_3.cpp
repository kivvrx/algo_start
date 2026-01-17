#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int main() {
    int t;
    std::cin >> t;
    std::vector<std::string> results;
    results.reserve(t);
    for (int _ = 0; _ < t; ++_) {
        int n, x;
        std::cin >> n >> x;
        std::vector<int> h(2 * n);
        for (int i = 0; i < 2 * n; ++i) {
            std::cin >> h[i];
        }
        std::sort(h.begin(), h.end());

        bool ok = true;
        for (int i = 0; i < n; ++i) {
            if (h[n + i] - h[i] < x) {
                ok = false;
                break;
            }
        }
        results.push_back(ok ? "YES" : "NO");
    }
    for (const auto& s : results) {
        std::cout << s << "\n";
    }
    return 0;
}
