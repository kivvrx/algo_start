// 1 dp хранит количество способ попасть на клетку ij
// 2 база начальной клетки равна 1 если начало не равно 0 тогда решения нет
// 3 переход смотрим на правую и верхние клетки если имеются 
// 4 ответ левый нижний элемент
// 5 идем по строкам справа налево сверху вниз
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> grid[i][j];

    if (grid[0][m - 1] == 0) {
        cout << -1;
        return 0;
    }
    const int K = 1000007;
    vector<vector<long long>> dp(n, vector<long long>(m, 0));
    dp[0][m - 1] = 1; // стартовая точка
    for (int i = 0; i < n; ++i) {
        for (int j = m - 1; j >= 0; --j) {
            if (i == 0 && j == m - 1) continue; // старт уже задан
            if (grid[i][j] == 0) continue;      // клетка заблокирована
            long long from_top = (i > 0) ? dp[i - 1][j] : 0;
            long long from_right = (j < m - 1) ? dp[i][j + 1] : 0;

            dp[i][j] = (from_top + from_right) % K;
        }
    }
    cout << (dp[n - 1][0] == 0 ? -1 : dp[n - 1][0]);
    return 0;
}
