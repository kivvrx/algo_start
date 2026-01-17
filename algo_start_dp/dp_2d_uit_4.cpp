// 1 dp хранит в каждой клетке минимальное время чтобы добраться до ij
// 2 база это первый элемент в таблице отдыха
// 3 переход это максимум из левой или верхней клетки для текущей (судя по примерам)
// 4 идем слева направо сверху вниз
// 5 ответ это правая нижняя клетка 
// восстанавливаем обратно смотря на результаты каждой клетки
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> grid(N, vector<int>(M));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> grid[i][j];
    vector<vector<int>> dp(N, vector<int>(M));
    dp[0][0] = grid[0][0];
    // первая строка вправо
    for (int j = 1; j < M; ++j)
        dp[0][j] = dp[0][j - 1] + grid[0][j];
    // первый столбец вниз
    for (int i = 1; i < N; ++i)
        dp[i][0] = dp[i - 1][0] + grid[i][0];
    // максимум из сверху или слева + текущая клетка
    for (int i = 1; i < N; ++i) {
        for (int j = 1; j < M; ++j) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
        }
    }
    cout << dp[N - 1][M - 1] << '\n';
    /////////////////
    string path;
    int i = N - 1, j = M - 1;
    while (i > 0 || j > 0) {
        if (i == 0) {
            path += 'R';
            --j;
        }
        else if (j == 0) {
            path += 'D';
            --i;
        }
        else {
            // предпочтение R при равенстве
            if (dp[i][j - 1] >= dp[i - 1][j]) {
                path += 'R';
                --j;
            }
            else {
                path += 'D';
                --i;
            }
        }
    }
    reverse(path.begin(), path.end());
    cout << path;
    return 0;
}

