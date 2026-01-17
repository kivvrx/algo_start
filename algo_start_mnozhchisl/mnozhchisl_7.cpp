#include <iostream>
#include <cmath>

bool is_prime(int x) {
    if (x == 1) return true; 
    if (x < 2) return false;
    if (x % 2 == 0) return x == 2;
    for (int d = 3; d * d <= x; d += 2) {
        if (x % d == 0) return false;
    }
    return true;
}
int main() {
    int N;
    std::cin >> N;
    for (int p = 1; p * p <= N; ++p) {
        if (!is_prime(p)) continue;
        int p2 = p * p;
        int q2 = N - p2;
        int q = std::sqrt(q2);
        if (q * q == q2 && is_prime(q)) {
            int a = std::min(p2, q2);
            int b = std::max(p2, q2);
            std::cout << a << " " << b;
            return 0;
        }
    }
    std::cout << -1;
    return 0;
}
