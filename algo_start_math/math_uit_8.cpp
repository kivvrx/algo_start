#include <iostream>
#include <vector>

int main() {
    int t;
    std::cin >> t;
    std::vector<int> answers;
    answers.reserve(t);
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }
        int m;
        std::cin >> m;
        long long sum = 0;
        for (int j = 0; j < m; ++j) {
            int b;
            std::cin >> b;
            sum += b;
        }
        int k = static_cast<int>(sum % n); // итоговый левый сдвиг
        answers.push_back(a[k]); // верхняя карта после m перемешиваний
    }
    for (int ans : answers) {
        std::cout << ans << '\n';
    }
    return 0;
}
