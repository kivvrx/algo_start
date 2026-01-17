#include <iostream>
#include <vector>

int main() {
    int N, M;
    std::cin >> N >> M;
    std::vector<std::vector<int>> a(N, std::vector<int>(M));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            std::cin >> a[i][j];
    std::vector<int> good;
    for (int j = 0; j < M; j++) {
        bool ok = true;
        for (int i = 0; i + 1 < N; i++) {
            if (a[i][j] > a[i + 1][j]) {
                ok = false;
                break;
            }
        }
        if (ok) good.push_back(j + 1); // нумерация с 1
    }
    if (good.empty()) {
        std::cout << -1 << "\n";
    }
    else {
        for (size_t k = 0; k < good.size(); k++) {
            if (k) std::cout << " ";
            std::cout << good[k];
        }
        std::cout << "\n";
    }
    return 0;
}