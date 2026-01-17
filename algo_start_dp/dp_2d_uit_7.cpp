// 1 dp хранит количество способов добраться до ij из 1 1
// 2 база dp[1][1] = 1 если стартовая клетка не заминирована
// 3 dp[i][j] = 0 если заминирована иначе смотрим на сумму слева и сверху
// 4 идём слева направо и сверху вниз
// 5 dp[N][M] > 0 ответ иначе -1
#include <iostream>
#include <vector>
using namespace std;
const int KK = 1000007;
int main() {
    int N, M, K;
    cin >> N >> M >> K;
    auto isgood = [&](int i, int j) {
        return (i % K == 0 && j % K == 0);
    };
    if (isgood(1, 1) || isgood(N, M)) {
        cout << -1;
        return 0;
    }
    vector<vector<int>> dp(N + 1, vector<int>(M + 1, 0));
    dp[1][1] = 1;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (i == 1 && j == 1) continue;
            if (isgood(i, j)) {
                dp[i][j] = 0;
            }
            else {
                dp[i][j] = ((i > 1 ? dp[i - 1][j] : 0) + (j > 1 ? dp[i][j - 1] : 0)) % KK;
            }
        }
    }
    if (dp[N][M] == 0) cout << -1;
    else cout << dp[N][M];
    return 0;
}
