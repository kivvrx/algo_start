#include <iostream>
#include <vector>
#include <numeric> 
#include <string>
#include <cmath>

bool is_prime(long long x) {
    if (x < 2) return false;
    if (x == 2) return true;
    if (x % 2 == 0) return false;
    for (long long i = 3; i * i <= x; i += 2) {
        if (x % i == 0) return false;
    }
    return true;
}
long long lcm(long long a, long long b) {
    return a / std::gcd(a, b) * b;
}

int main() {
    int n;
    std::cin >> n;

    std::vector<int> c(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> c[i];
    }
    long long L = c[0];
    for (int i = 2; i < n; i += 2) {
        L = lcm(L, c[i]);
    }
    long long sum = 0;
    int count = 0;
    for (int i = 1; i < n; i += 2) {
        sum += c[i];
        count++;
    }
    long long G = std::gcd(sum, count);
    std::string s1 = std::to_string(L) + std::to_string(G);
    std::string s2 = std::to_string(G) + std::to_string(L);
    long long num1 = std::stoll(s1);
    long long num2 = std::stoll(s2);
    if (is_prime(num1) || is_prime(num2)) {
        std::cout << "YES";
    }
    else {
        std::cout << "NO";
    }
    return 0;
}