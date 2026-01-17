#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

bool is_prime(int x) {
    if (x < 2) return false;
    if (x == 2) return true;
    if (x % 2 == 0) return false;
    for (int i = 3; 1LL * i * i <= x; i += 2) {
        if (x % i == 0) return false;
    }
    return true;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) std::cin >> a[i];
    std::vector<int> primes;
    for (int x : a) {
        if (is_prime(x)) primes.push_back(x);
    }
    // оставляем только уникальные простые
    // потому что если два числа простые и разные, то они автоматически
    //взаимно просты потому что у разных простых чисел нет 
    //общих делителей кроме 1
    // а одинаковые простые числа дают gcd > 1 значит они не взаимно простые
    std::sort(primes.begin(), primes.end());
    primes.erase(std::unique(primes.begin(), primes.end()), primes.end());
    if (primes.size() < 2) {
        std::cout << -1 << "\n";
    }
    else {
        int m = primes.size();
        std::cout << primes[m - 1] + primes[m - 2] << "\n";
    }
    return 0;
}
