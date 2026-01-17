#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    if (n == 1) {
        std::cout << 2;
        return 0;
    }
    std::vector<int> dp(3);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;
    for (int i = 3;; ++i) {
       int dpi = dp[i - 1] + dp[i - 2];
        if (dpi == n) {
            std::cout << i;
            break;
        }
        if (dpi > n) {
            std::cout << -1;
            break;
        }
        dp.push_back(dpi);
    }
    return 0;
}
