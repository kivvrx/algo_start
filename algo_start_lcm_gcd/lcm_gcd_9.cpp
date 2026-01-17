#include <iostream>
#include <numeric>
#include <cmath>

int main() {
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;
    long long n = 1LL * a * d - 1LL * c * b;
    long long den = 1LL * b * d;
    long long g = std::gcd(std::abs(n), std::abs(den));
    n /= g;
    den /= g;
    if (den < 0) {
        n = -n;
        den = -den;
    }
    std::cout << n << "/" << den;
    return 0;
}

