#include <iostream>

long long gcd(long long a, long long b) {
    while (b != 0) {
        long long t = a % b;
        a = b;
        b = t;
    }
    return a;
}

int main() {
    long long A, B;
    std::cin >> A >> B;
    long long g = gcd(A, B);
    std::cout << A / g << " " << B / g << "\n";
    return 0;
}
