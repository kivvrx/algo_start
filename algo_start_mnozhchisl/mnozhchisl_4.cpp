#include <iostream>
#include <vector>
#include <set>
#include <cmath>

int main() {
    long long n;
    int k;
    std::cin >> n >> k;
    std::vector<long long> a(k);
    for (int i = 0; i < k; i++) {
        std::cin >> a[i];
    }
    std::set<long long> primes;
    long long tmp = n;
    while (tmp % 2 == 0) {
        primes.insert(2);
        tmp /= 2;
    }
    for (long long d = 3; d * d <= tmp; d += 2) {
        while (tmp % d == 0) {
            primes.insert(d);
            tmp /= d;
        }
    }
    if (tmp > 1) primes.insert(tmp);
    for (long long x : a) {
        if (primes.count(x)) {
            std::cout << "YES\n";
            return 0;
        }
    }
    std::cout << "NO\n";
    return 0;
}