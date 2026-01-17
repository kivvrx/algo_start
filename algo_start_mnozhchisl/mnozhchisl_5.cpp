#include <iostream>
#include <cmath>

int main() {
    long long n;
    std::cin >> n;
    if (n <= 3) {
        std::cout << -1 << "\n";
        return 0;
    }
    long long best = -1;
    for (long long d = 2; d * d <= n; d++) {
        if (n % d == 0) {
            long long other = n / d;
            if (d != n && d != 1) best = std::max(best, d);
            if (other != n && other != 1) best = std::max(best, other);
        }
    }
    std::cout << best << "\n";
    return 0;
}
