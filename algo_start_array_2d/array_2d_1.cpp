#include <iostream>
int main() {
    int n, m;
    std::cin >> n >> m;
    int total = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int x;
            std::cin >> x;
            if (x % 10 == 0) {
                total += x;
            }
        }
    }
    std::cout << total;
    return 0;
}