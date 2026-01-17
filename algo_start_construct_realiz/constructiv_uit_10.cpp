#include <iostream>
#include <vector>
#include <tuple>
#include <numeric>

int main() {
    int t;
    std::cin >> t;
    std::vector<std::tuple<long long, long long, long long>> results;
    results.reserve(t);
    while (t--) {
        long long n;
        std::cin >> n;
        long long S = n - 1;
        long long a = -1, b = -1, c = 1;
        for (long long x = 2; x <= S - 2; ++x) {
            long long y = S - x;
            if (y >= 2 && x != y && std::gcd(x, y) == 1) {
                a = x;
                b = y;
                break;
            }
        }
        results.emplace_back(a, b, c);
    }
    for (auto [a, b, c] : results) {
        std::cout << a << ' ' << b << ' ' << c << '\n';
    }

    return 0;
}

