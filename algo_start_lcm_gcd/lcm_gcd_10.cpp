#include <iostream>
#include <cmath>

int main() {
    long long n;
    std::cin >> n;
    if (n == 1) {
        std::cout << "NO\n";
        return 0;
    }
    long long sum = 1; // 1 всегда делитель
    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            sum += i;
            if (i != n / i && n / i != n) {
                sum += n / i;
            }
        }
    }
    if (sum == n) std::cout << "YES";
    else std::cout << "NO";
    return 0;
}
