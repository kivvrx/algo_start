// пусть gcd(a,b) = g тогда a = g*m, b = g*n 
// тогда gcd(m,n) = 1 = d 
// потому что пусть d > 1 тогда a = g *m = g * d * m` 
// b = g * n = g * d * n` Тогда общий делитель a и b был бы не g, а g*d
// lcm (a,b) = a*b/(g) = g*m*n 
// по заданию нод + нок = g + g*m*n = g(1+m*n) = x
// всегда можно взять g = 1 
// 1 + m*n = x
// пусть m = 1 
// тогда n = x - 1, a = 1 , b = x - 1 
#include <iostream>
#include <vector>

int main() {
    int t;
    std::cin >> t;
    std::vector<std::pair<long long, long long>> answers;
    answers.reserve(t);
    for (int i = 0; i < t; ++i) {
        long long x;
        std::cin >> x;
        answers.push_back({ 1, x - 1 });
    }
    for (auto [a, b] : answers) {
        std::cout << a << " " << b << "\n";
    }
    return 0;
}


