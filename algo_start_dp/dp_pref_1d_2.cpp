// 1 2 3 
// 1 храним в dp количество способов попасть на i ступень
// 2 база написана в коде 
// 3 переход посчитать сумму позиций которые достижимы до точки i не более чем на 3
// ступени
// 4 идем слева направо 
// 5 ответ это n-й элемент массива 
#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    const int K = static_cast<int>(1e6) + 7;
    std::vector<int> dp(n + 1, 0);
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for (int i = 4; i <= n; ++i) {
        dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % K;
    }
    std::cout << dp[n];
    return 0;
}
