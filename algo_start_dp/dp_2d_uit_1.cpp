// 1 dp матрица dp[i][j] кажда€ клетка значение 
// 2 база это dp[1][1] = 1
// 3 dp[i][j] = (dp[i-1][j] + dp[i][j-1])
// 4 нижн€€ права€ клетка
// 5 сначала по столбцам слева направо потом по строкам сверху вниз

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    int n, m;
    if (!(cin >> n >> m)) return 0;
    vector<vector<long long>> dp(n + 2, vector<long long>(m + 2, 0));
    dp[1][1] = 1;
    const int K = static_cast<int>(1e6) + 7;
    for (int i = 1; i <=n ; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (i == 1 && j == 1) continue;
            dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % K ;
        }
    }
    cout << dp[n][m];
    return 0;
}
