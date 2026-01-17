#include <iostream>
#include <cmath>

int main() {
    long long n, x;
    std::cin >> n >> x;
    long long sum = 0;
    while (n % 2 == 0) {
        sum += 2;
        if (sum >= x) { std::cout << "YES\n"; return 0; }
        n /= 2;
    }
    // здесь как бы на каждой итерации уже новое n  
    // и на каждой итерации мы ищем все деления на d 
    // нет смысла проходить по всем они симметричны
    for (long long d = 3; d * d <= n; d += 2) {
        while (n % d == 0) {
            sum += d;
            if (sum >= x) { std::cout << "YES\n"; return 0; }
            n /= d;
        }
    }
    if (n > 1) {
        sum += n;
    }
    std::cout << (sum >= x ? "YES" : "NO") << "\n";
    return 0;
}