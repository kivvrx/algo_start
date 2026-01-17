#include <iostream>
#include <cstdint>
const uint64_t MOD = 1000000007;
// работает на gcc 64
uint64_t gcd128(uint64_t a, uint64_t b) {
    while (b != 0) {
        uint64_t t = a % b;
        a = b;
        b = t;
    }
    return a;
}

uint64_t lcm128(uint64_t a, uint64_t b) {
    uint64_t g = gcd128(a, b);
    return (a / g) * b;
}

int main() {
    uint64_t z, x, c;
    if (!(std::cin >> z >> x >> c)) return 0;
    uint64_t L = lcm128(lcm128(z, x), c);
    uint64_t ans = (L % MOD);
    std::cout << ans << "\n";
    return 0;
}
