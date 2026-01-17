#include <iostream>
#include <vector>
#include <set>
#include <limits>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;
    std::vector<int> cost(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> cost[i];
    }
    int M;
    std::cin >> M;
    std::set<std::pair<int, int>> compatible;
    for (int i = 0; i < M; ++i) {
        int a, b;
        std::cin >> a >> b;
        --a; --b; // индексация с 0
        if (a > b) std::swap(a, b); 
        compatible.insert({ a, b });
    }
    int min_sum = std::numeric_limits<int>::max();

    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            for (int k = j + 1; k < N; ++k) {
                if (
                    compatible.count({ std::min(i,j), std::max(i,j) }) &&
                    compatible.count({ std::min(j,k), std::max(j,k) }) &&
                    compatible.count({ std::min(i,k), std::max(i,k) })
                    ) {
                    int total = cost[i] + cost[j] + cost[k];
                    min_sum = std::min(min_sum, total);
                }
            }
        }
    }
    if (min_sum == std::numeric_limits<int>::max()) {
        std::cout << -1 << "\n";
    }
    else {
        std::cout << min_sum << "\n";
    }

    return 0;
}
