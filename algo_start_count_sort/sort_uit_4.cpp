#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

int main() {
    int t;
    std::cin >> t;
    std::vector<int> results;
    results.reserve(t);
    for (int _ = 0; _ < t; _++) {
        int n;
        std::cin >> n;
        std::vector<int> a(n);
        std::unordered_map<int, int> freq;
        for (int i = 0; i < n; i++) {
            std::cin >> a[i];
            freq[a[i]]++;
        }
        int distinct = static_cast<int>(freq.size());
        int duplicates = n - distinct; // сколько элементов нужно убрать чтобы остались 
        // только уникальные
        // если нужно убрать нечётное количество элементов придётся убрать ещё один 
        // какой-то уникальный
        // чтобы суммарное число удалений было чётным
        int answer = distinct - (duplicates % 2);
        results.push_back(answer);
    }
    for (int ans : results) {
        std::cout << ans << "\n";
    }
    return 0;
}
