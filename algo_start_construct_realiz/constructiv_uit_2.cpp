#include <iostream>
#include <vector>

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> base(n, k / n);
    for (int i = 0; i < k % n; ++i) {
        base[i] += 1;
    }
    //[a, b, c]
    //[c, a, b]
    //[b, c, a]

    std::vector<std::vector<int>> table(n, std::vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            table[i][(j + i) % n] = base[j];
        }
    }
    for (const auto& row : table) {
        for (int val : row) {
            std::cout << val << ' ';
        }
        std::cout << '\n';
    }

    return 0;
}
