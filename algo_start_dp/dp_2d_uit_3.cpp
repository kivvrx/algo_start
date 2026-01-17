// 1 dp в каждой клетке хранится максимальная сумма монет на данной клетке
// 2 база это первая клетка сколько в ней монет
// 3 переход это максимум из левой верхней 
// 4 идем слева направо по столбцам и сверху вниз по строкам
// 5 ответ это правая нижняя клетка dp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int K = 1000007;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> grid(N, vector<int>(M));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> grid[i][j];
    vector<vector<long long>> dp(N, vector<long long>(M, LLONG_MIN));
    dp[0][0] = grid[0][0];
    // первая строка вправо
    for (int j = 1; j < M; ++j)
        dp[0][j] = dp[0][j - 1] + grid[0][j];
    // первый столбец  вниз
    for (int i = 1; i < N; ++i)
        dp[i][0] = dp[i - 1][0] + grid[i][0];
    //////////////////////
    for (int i = 1; i < N; ++i) {
        for (int j = 1; j < M; ++j) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
        }
    }
    long long result = (dp[N - 1][M - 1]) % K;
    cout << result;
    return 0;
}
