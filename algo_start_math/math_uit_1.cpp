#include <iostream>
#include <vector>
int main() {
    int t;
    std::cin >> t;
    std::vector<int> ans;
    while (t--) {
        int l1, r1, l2, r2;
        int anss = -1;
        std::cin >> l1 >> r1 >> l2 >> r2;

        // проверка пересечения
        int left = std::max(l1, l2);
        int right = std::min(r1, r2);

        if (left <= right) {
            // пересечение есть
            anss = std::max(l1, l2);
        }
        else {
            // пересечения нет
            anss = l1 + l2;
        }
        ans.push_back(anss);
    }
    for (int i = 0; i < ans.size(); ++i) {
        std::cout << ans[i] << '\n';
    }
    return 0;
}
