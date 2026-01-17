#include <iostream>
#include <unordered_set>

int main() {
    int n, k;
    std::cin >> n >> k;
    std::unordered_set<int> a_v;

    for (int i = 0; i < n; ++i) {
        int a_i;
        std::cin >> a_i;
        int diff = k - a_i;
        // тоесть проверяем очередной элемент которого еще нету в хеш таблице
        if (a_v.count(diff)) {
            std::cout << "YES";
            return 0;
        }
        a_v.insert(a_i);
    }

    std::cout << "NO";
    return 0;
}