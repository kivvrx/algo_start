// нужно разбить массив так чтобы 
// каждый кусок был непустым
// все элементы были включены
// пор€док был сохранЄн
// штраф(модуль суммы * длина) был минимален
// минимальный когда сумма равна 0 
// значит будем идти пока сумма не станет 0 

#include <iostream>
#include <vector>
#include <string>
#include <cmath>

int main() {
    int t, n;
    std::cin >> t;
    std::vector<int> ans_v;

    while (t--) {
        std::cin >> n;
        std::vector<int> v_n(n);
        std::string s;
        std::cin >> s;

        for (int i = 0; i < n; ++i) {
            v_n[i] = s[i] == '+' ? 1 : -1;
        }

        int l = 0;
        int ans = 0;

        while (l < n) {
            int sum = 0;
            int r = l;

            while (r < n) {
                // вот это действие мы делаем каждый раз 
                // поэтому у нас как бы на каждой итерации длина равна 1 ѕ–»Ѕј¬Ћя≈ћјя
                // и мы как бы общую длину всегда получаем при прибавлении
                // тоесть сумма += 1*элемент + 1*элемент поэтому так получаетс€
                sum += v_n[r];
                if (sum == 0) break;
                ++r;
            }
            ans += (sum == 0 ? 0 : std::abs(sum));
            l = r + 1;
        }

        ans_v.push_back(ans);
    }

    for (const auto& vv : ans_v) std::cout << vv << '\n';
    return 0;
}
