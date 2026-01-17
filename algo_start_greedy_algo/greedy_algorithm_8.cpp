//каждое переливание позволяет взять воду из одной бочки и добавить её в другую
//чтобы получить максимум в одной бочке мы должны перелить воду 
//из k самых больших бочек в самую большую
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int main() {
    int t;
    std::cin >> t;
    std::vector<long long> results;

    while (t--) {
        int n, k;
        std::cin >> n >> k;
        std::vector<long long> a(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }
        std::sort(a.begin(), a.end());
        long long maxl = a[n - 1];
        for (int i = 0; i < k; ++i) {
            maxl += a[n - 2 - i];
        }
        results.push_back(maxl); // min всегда можно сделать 0
    }
    for (long long res : results) {
        std::cout << res << '\n';
    }
    return 0;
}
