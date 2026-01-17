#include <iostream>
#include <vector>

int main() {
    int t;
    std::cin >> t;
    std::vector<int> results;
    results.reserve(t);

    for (int _ = 0; _ < t; ++_) {
        int n;
        std::cin >> n;
        int winner_index = -1;
        int best = -1;
        for (int i = 1; i <= n; ++i) {
            int a, b;
            std::cin >> a >> b;
            if (a <= 10 && b > best) {
                best = b;
                winner_index = i;
            }
        }
        results.push_back(winner_index);
    }
    for (int idx : results) {
        std::cout << idx << "\n";
    }
    return 0;
}
