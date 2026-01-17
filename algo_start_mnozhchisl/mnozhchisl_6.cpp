#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

int main() {
    long long n;
    std::cin >> n;
    std::vector<long long> powers;
    int count = 0;
    while (n % 2 == 0) {
        count++;
        n /= 2;
    }
    if (count > 0) powers.push_back(std::pow(2, count));
    for (long long d = 3; d * d <= n; d += 2) {
        count = 0;
        while (n % d == 0) {
            count++;
            n /= d;
        }
        if (count > 0) powers.push_back(std::pow(d, count));
    }
    if (n > 1) powers.push_back(n); 
    if (powers.size() < 2) {
        std::cout << -1 << "\n";
    }
    else {
        std::sort(powers.begin(), powers.end(), std::greater<long long>());
        std::cout << powers[0] + powers[1] << "\n";
    }
    return 0;
}
