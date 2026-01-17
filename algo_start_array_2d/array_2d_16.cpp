#include <iostream>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cout << std::max(i, j);
            if (j + 1 < N) {
                std::cout << ' ';
            }
        }
        std::cout << '\n';
    }
    return 0;
}