#include <iostream>
#include <vector>
#include <cmath>
bool is_prime(int x) {
    if (x < 2) return false;
    if (x == 2) return true;
    if (x % 2 == 0) return false;
    for (int i = 3; i * i <= x; i += 2) {
        if (x % i == 0) return false;
    }
    return true;
}
int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (int x : a) {
        if (x == 1) {
            std::cout << "1: just one\n";
        }
        else if (is_prime(x)) {
            std::cout << x << ": prime\n";
        }
        else {
            std::cout << x << ": composite\n";
        }
    }
    return 0;
}