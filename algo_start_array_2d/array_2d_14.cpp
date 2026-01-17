#include <iostream>
#include <vector>

int main() {
    int N, M;
    std::cin >> N >> M;
    std::vector<std::vector<char>> res(N, std::vector<char>(M));
    char cur = 'A';
    for (int s = 0; s <= N - 1 + M - 1; s++) {
        for (int i = 0; i < N; i++) {
            int j = s - i;
            if (j < 0 || j >= M) continue;
            res[i][j] = cur;
            cur++;
            if (cur > 'Z') cur = 'A';
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            std::cout << res[i][j];
            if (j + 1 < M) std::cout << " ";
        }
        std::cout << "\n";
    }
    return 0;
}
//1 1 1  
//1 1 1
//1 1 1