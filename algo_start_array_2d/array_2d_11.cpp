#include <iostream>
#include <vector>

int main() {
    int N;
    std::cin >> N;
    std::vector<std::vector<int>> a(N, std::vector<int>(N));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            std::cin >> a[i][j];
    int maxVal = -1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) continue;              // главная диагональ
            if (i + j == N - 1) continue;      // побочная диагональ
            if (a[i][j] > maxVal) maxVal = a[i][j];
        }
    }
    std::cout << maxVal << "\n";
    return 0;
}