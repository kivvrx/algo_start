#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, a, b;
    std::cin >> n >> a >> b;
    std::vector<long long> h(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> h[i];
    }
    std::sort(h.begin(), h.end());
    long long hb = h[b - 1];
    long long hbp1 = h[b];

    long long ans = hbp1 > hb ? (hbp1 - hb) : 0;
    std::cout << ans;
    return 0;
}
