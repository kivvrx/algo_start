#include <iostream>
#include <vector>
#include <cmath>

int main() {
    long long n;
    std::cin >> n;
    std::vector<long long> factors;
    while (n % 2 == 0) {
        factors.push_back(2);
        n /= 2;
    }
    for (long long d = 3; d * d <= n; d += 2) {
        while (n % d == 0) {
            factors.push_back(d);
            n /= d;
        }
    }
    if (n > 1) factors.push_back(n);
    // сумма произведений
    long long sum = 0;
    for (size_t i = 0; i < factors.size(); ++i) {
        for (size_t j = i + 1; j < factors.size(); ++j) {
            sum += factors[i] * factors[j];
        }
    }
    std::cout << sum;
    return 0;
}
