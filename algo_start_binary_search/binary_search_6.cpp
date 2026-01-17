#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) std::cin >> a[i];
    int q;
    std::cin >> q;
    long long total = 0;
    while (q--) {
        int p;
        std::cin >> p;
        auto L = std::lower_bound(a.begin(), a.end(), p);
        auto R = std::upper_bound(a.begin(), a.end(), p);
        int cnt = R - L;
        if (cnt > 1) total += cnt;
    }
    std::cout << total << "\n";
}
