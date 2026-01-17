#include <iostream>
int main() {
    int N, M;
    std::cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            std::cout << ((i + j) % 2);
            if (j + 1 < M) std::cout << ' ';
        }
        std::cout << '\n';
    }
    return 0;
}
