#include <iostream>
#include <cmath>

bool is_prime(int x) {
    if (x < 2) return false;
    if (x == 2) return true;
    if (x % 2 == 0) return false;
    for (int d = 3; d * d <= x; d += 2) {
        if (x % d == 0) return false;
    }
    return true;
}
int main() {
    int x;
    std::cin >> x;
    if (is_prime(x) || is_prime(x - 1) || is_prime(x + 1)) {
        std::cout << "YES";
    }
    else {
        std::cout << "NO";
    }
    return 0;
}

