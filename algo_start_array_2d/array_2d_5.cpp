#include <iostream>
#include <vector>

int main() {
    int N, M;
    std::cin >> N >> M;
    std::vector<std::vector<int>> a(N, std::vector<int>(M));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            std::cin >> a[i][j];

    long long count = 0;

    for (int i = 0; i + 1 < N; ++i) {
        for (int j = 0; j + 3 < M; ++j) {
            bool top_edges = (a[i][j] == 1 && a[i][j + 3] == 1);
            bool top_middle = (a[i][j + 1] == 1 && a[i][j + 2] == 1);
            bool bot_edges = (a[i + 1][j] == 1 && a[i + 1][j + 3] == 1);
            bool bot_middle = (a[i + 1][j + 1] == 1 && a[i + 1][j + 2] == 1);

            if (top_edges && bot_middle)  ++count; // вариант 1
            if (top_middle && bot_edges)  ++count; // вариант 2
        }
    }

    std::cout << count << '\n';
    return 0;
}
