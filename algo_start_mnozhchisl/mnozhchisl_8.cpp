#include <iostream>
#include <vector>

int main() {
    int N;
    std::cin >> N;
    std::vector<bool> is_prime(N + 1, true);
    is_prime[0] = is_prime[1] = false;
    // решето эратосфена
    for (int i = 2; i * i <= N; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= N; j += i) {
                is_prime[j] = false;
            }
        }
    }
    // каждый делитель числа 12  это КОМБИНАЦИЯ степеней простых множителей
    // для 12 = 2 * 2 * 3 
    // как получить все комбинации ?
    // для множителя 2 это 0 1 2 всего 3 
    // для множителя 3 это 0 1 всего 2 
    // тоесть всего получается 3 * 2 делителей 
    // 
    long long result = 1;
    for (int p = 2; p <= N; ++p) {
        if (!is_prime[p]) continue;
        int exponent = 0;
        int power = p;
        while (power <= N) {
            exponent += N / power;
            power *= p;
        }
        result *= (exponent + 1); // +1 потому что например степени 1 2 но еще есть 0 
        // тоесть когда нет его 
    }
    std::cout << result;
    return 0;
}
