#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int t;
    std::cin >> t;
    std::vector<int> results;
    results.reserve(t);

    for (int _ = 0; _ < t; ++_) {
        int n;
        long long k;
        std::cin >> n >> k;
        std::vector<long long> a(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }
        std::sort(a.begin(), a.end());
        int max_len = 1; // хотя бы один элемент всегда допустим
        int l = 0;
        for (int r = 1; r < n; ++r) {
            if (a[r] - a[r - 1] > k) {
                l = r; // разрыв начинаем новое окно
            }
            max_len = std::max(max_len, r - l + 1);
        }
        int answer = n - max_len;
        results.push_back(answer);
    }
    for (int ans : results) {
        std::cout << ans << "\n";
    }
    return 0;
}
