// 1 dp количество способов добраться до клетки
// 2 база = 1 кузнечик стоит на левой верхней клетке
// 3 для ij клетки берем пути слева на - 1 и -2 назад и также сверху
// 4 идём слева направо и сверху вниз
// 5 ответ правая нижняя клетка 
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int N, M;
    cin >> N >> M;
    double f = 1e6 + 7;
    const int K = 1000007;
    vector<vector<int>> dp(N + 1, vector<int>(M + 1, 0));
    dp[1][1] = 1;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (i == 1 && j == 1) continue;
            long long paths = 0;
            if (i > 1) paths += dp[i - 1][j];
            if (i > 2) paths += dp[i - 2][j];
            if (j > 1) paths += dp[i][j - 1];
            if (j > 2) paths += dp[i][j - 2];
            dp[i][j] = paths % K;
        }
    }
    cout << dp[N][M];
    return 0;
}
