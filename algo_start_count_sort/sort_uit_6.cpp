#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    std::sort(a.begin(), a.end());
    a.erase(std::unique(a.begin(), a.end()), a.end());
    int m = a.size();
    for (int i = 0; i < k; i++) {
        if (i < m) {
            // тут главное что на каждой итерации мы обнул€ем предыдущее 
            // тоесть в предыдущем зашиты все отнимани€ перед следующим шагом
            // потому что полное обнуление означает сумму предыдущих а значит 
            // когда отнимаем предыдущее это и есть все отн€ти€ дл€ следующего числа
            // тут важно еще понимать что предыдущий уже "немного" отн€т от того предыдущего

            long long diff = (i == 0 ? a[0] : a[i] - a[i - 1]);
            std::cout << diff << "\n";
        }
        else {
            std::cout << 0 << "\n";
        }
    }
    return 0;
}
