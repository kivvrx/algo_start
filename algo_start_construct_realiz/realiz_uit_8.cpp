#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<std::pair<int, int>> chapters(n);
    for (int i = 0; i < n; ++i) {
        int l, r;
        std::cin >> l >> r;
        chapters[i] = { l, r };
    }
    int k;
    std::cin >> k;
    int answer = 0;
    for (int i = 0; i < n; ++i) {
        int l = chapters[i].first;
        int r = chapters[i].second;
        if (k <= r) {
            // начиная с этой главы и все последующие непрочитаны
            answer = n - i;
            break;
        }
    }
    std::cout << answer << '\n';
    return 0;
}
