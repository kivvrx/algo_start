#include <iostream>
#include <cmath>

int main() {
    long long n;
    std::cin >> n;
    int count = 0;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            count++;
            if (i != n / i) count++;
        }
    }
    std::cout << count << "\n";
    return 0;
}