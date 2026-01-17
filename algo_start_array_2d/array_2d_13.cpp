#include <iostream>
#include <vector>

int main() {
    int N, M;
    std::cin >> N >> M;
    int k;
    std::cin >> k;
    std::vector<std::vector<int>> field(N, std::vector<int>(M, 0));
    std::vector<std::vector<bool>> mine(N, std::vector<bool>(M, false));
    for (int t = 0; t < k; t++) {
        int a, b;
        std::cin >> a >> b;
        --a; --b; // переводим в 0-индексацию
        mine[a][b] = true;
    }
    // направления для 8 соседей
    int dx[8] = { -1,-1,-1,0,0,1,1,1 };
    int dy[8] = { -1,0,1,-1,1,-1,0,1 };
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (mine[i][j]) continue;
            int cnt = 0;
            for (int d = 0; d < 8; d++) {
                int ni = i + dx[d], nj = j + dy[d];
                if (ni >= 0 && ni < N && nj >= 0 && nj < M && mine[ni][nj])
                    cnt++;
            }
            field[i][j] = cnt;
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (mine[i][j]) std::cout << "*";
            else std::cout << field[i][j];
            if (j + 1 < M) std::cout << " ";
        }
        std::cout << "\n";
    }
    return 0;
}
