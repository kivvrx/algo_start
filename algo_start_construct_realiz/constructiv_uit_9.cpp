#include <iostream>

int main() {
    long long n;
    std::cin >> n;
    long long weeks = n / 7;
    long long rem = n % 7;

    long long weeks_min = weeks * 2 + std::max(0LL, rem - 5);
    long long weeks_max = weeks * 2 + std::min(2LL, rem);
    std::cout << weeks_min << " " << weeks_max << "\n";
    return 0;
}

