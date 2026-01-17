#include <iostream>
#include <vector>

int main() {
    int t;
    std::cin >> t;
    std::vector<long long> out;
    out.reserve(t);
    while (t--) {
        int n;
        std::cin >> n;
        long long g;
        for (int i = 0; i < n; ++i) {
            long long x;
            std::cin >> x;
            if (i == 0) g = x;
            else g &= x;
        }
        out.push_back(g);
    }
    for (long long ans : out) {
        std::cout << ans << '\n';
    }
    return 0;
}
