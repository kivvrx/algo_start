// 1 в dp храним колво способов добраться до клетки i
// 2 база dp[0] = 1 иначе алгоритм не запустится
// 3 dp[i] = dp[i-1] + dp[i-2]
// 4 идем слева направо 
// 5 ответ это последний элемент массива 
#include <iostream>
#include <vector>
#include <unordered_set>

int main() {
    int n, k;
    std::cin >> n >> k;
    std::unordered_set<int> s;
    for (int i = 0; i < k; ++i) {
        int x;
        std::cin >> x;
        s.insert(x);
    }
    const int K = 1000007;
    std::vector<int> dp(n + 1, 0);
    dp[0] = 1; // стартовая площадка
    for (int i = 1; i <= n; ++i) {
        if (s.count(i)) {
            dp[i] = 0; // на пилу нельзя наступать
        }
        else {
            if (i >= 1) dp[i] = (dp[i] + dp[i - 1]) % K;
            if (i >= 2) dp[i] = (dp[i] + dp[i - 2]) % K;
        }
    }
    if (dp[n] == 0)
        std::cout << "Game over";
    else
        std::cout << dp[n];

    return 0;
}
