#include <iostream>
#include <vector>
#include <limits>

int main() {
    int t;
    std::vector<long long> ans;
    std::cin >> t;
    while (t--) {
        int n;
        long long x;
        std::cin >> n >> x;
        std::vector<long long> a(n);
        for (int i = 0; i < n; ++i) std::cin >> a[i];
        int changes = 0;
        // v - a <= x  >>> 
        // |числа| = либо число если число >= 0 либо -число если число < 0
        // у нас число равно v - a 
        // раскроем |v-a| <= x 
        // 1 случай когда >= тогдда v - a <= x
        // 2 сслучай < Тогда -v + a <= x домножим на -1 будет v - a >= -x
        // получим -x <= v-a <= x прибавим +a
        // получим -x + a <= v <= x + a
        // a - x <= v <= a + x
        // Как найти границы пересечения
        //    Левая граница пересечения должна быть не меньше обеих левых границ, иначе мы 
        //    «залезем» в область, где хотя бы один интервал не действует.
        //    Поэтому берём максимум 
        //    Правая граница пересечения должна быть не больше обеих правых границ, 
        //    иначе мы «выйдем» за пределы хотя бы одного интервала.Поэтому берём минимум 
        long long L = a[0] - x;
        long long R = a[0] + x;
        for (int i = 1; i < n; ++i) {
            long long li = a[i] - x;
            long long ri = a[i] + x;
            // сужаем текущее допустимое окно
            if (li > L) L = li;
            if (ri < R) R = ri;
            // если окно стал пустым изменить v и начать новый промежуток
            if (L > R) {
                ++changes;
                L = li;
                R = ri;
            }
        }
        auto answ = changes;
        ans.push_back(answ);
    }
    for (const auto& aa : ans) std::cout << aa << '\n';
    return 0;
}
