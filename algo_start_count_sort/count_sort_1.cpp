#include <iostream>
#include <vector>
//Возьмём диапазон от –2 до 2:
//Числа: –2, –1, 0, 1, 2
//Всего : 5 значений
//Индексы : 0..4 (5 штук)
//Если бы мы взяли размер 4, то последнее число «2» некуда было бы положить.
int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    const int OFFSET = 10000; // по модулю
    const int K = 20001; // диапазон от -10000 до 10000
    std::vector<int> cnt(K, 0);
    for (int x : a) {
        cnt[x + OFFSET]++;
    }
    for (int i = 0; i < K; ++i) {
        while (cnt[i] > 0) {
            std::cout << (i - OFFSET) << ' ';
            cnt[i]--;
        }
    }
    std::cout << '\n';
    return 0;
}
