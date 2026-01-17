//1 в dp храним оптимальную сумму для i ступеньки
// 2 база для трех первых случаев очевидна
// 3 формула перехода max (из трех предыдущих) + число на данной ступеньки (раз
//уж мы на нее наступили)
//4 идем слева направо 
//5 ответ последнее элемент массива dp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int& x : a) std::cin >> x;
    std::vector<int> dp(n);
    dp[0] = a[0];
    if (n >= 2) dp[1] = std::max(dp[0], 0) + a[1];
    if (n >= 3) dp[2] = std::max({ dp[1], dp[0], 0 }) + a[2];
    for (int i = 3; i < n; ++i) {
        dp[i] = std::max({ dp[i - 1], dp[i - 2], dp[i - 3] }) + a[i];
    }
    int result = dp[n - 1];
    if (result >= 0)
        std::cout << "Income: " << result << '\n';
    else
        std::cout << "Debt: " << result << '\n';
    return 0;
}

