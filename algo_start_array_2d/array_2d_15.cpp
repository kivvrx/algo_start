#include <iostream>
#include <vector>

int main() {
    int N;
    std::cin >> N;
    std::vector<std::vector<int>> a(N, std::vector<int>(N));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            std::cin >> a[i][j];
    for (int i = 0; i < N; ++i) {
        std::swap(a[i][i], a[N - 1 - i][i]);
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cout << a[i][j];
            if (j + 1 < N) std::cout << ' ';
        }
        std::cout << '\n';
    }
    return 0;
}