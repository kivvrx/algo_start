#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<long long> a(n);
        for (int i = 0; i < n; ++i) std::cin >> a[i];

        // 1) если есть отрицательное тогда оно точно исходное
        bool minus = false;
        long long neg = 0;
        for (long long x : a) {
            if (x < 0) { minus = true; neg = x; break; }
        }
        if (minus) {
            std::cout << neg << "\n";
            continue;
        }
        // 2) иначе все неотрицательные тогда максимум точно исходный
        long long mx = *std::max_element(a.begin(), a.end());
        std::cout << mx << "\n";
    }
    return 0;
}
