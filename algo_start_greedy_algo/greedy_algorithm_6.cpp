//игроки могут выбирать любую карту каждый ход если  есть карта которая 
//гарантированно сильнее любой 
//карты противника, можно просто играть её каждый раз и выигрывать.
//поэтому, вся игра сводится к сравнению максимальных карт 
//если максимальная карта первого игрока > максимальной карты второго
//то первый игрок может всегда побеждать играя её

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int main() {
    int t;
    std::cin >> t;
    std::vector<std::string> results;

    for (int test = 0; test < t; ++test) {
        int n, k1, k2;
        std::cin >> n >> k1 >> k2;
        std::vector<int> a(k1), b(k2);
        for (int i = 0; i < k1; ++i) {
            std::cin >> a[i];
        }
        for (int i = 0; i < k2; ++i) {
            std::cin >> b[i];
        }
        int maxA = *std::max_element(a.begin(), a.end());
        int maxB = *std::max_element(b.begin(), b.end());
        results.push_back(maxA > maxB ? "YES" : "NO");
    }
    for (const std::string& res : results) {
        std::cout << res << '\n';
    }
    return 0;
}

