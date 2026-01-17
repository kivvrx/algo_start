#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <set>

int main() {
    int n, m;
    std::cin >> n;
    std::unordered_set<int> oleg;
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        oleg.insert(x);
    }
    std::cin >> m;
    std::set<int> san;
    for (int i = 0; i < m; ++i) {
        int x;
        std::cin >> x;
        if (!oleg.count(x)) {
            san.insert(x); // магнитик не разбился
        }
    }
    for (int x : san) {
        std::cout << x << " ";
    }
    std::cout << "\n";

    return 0;
}
