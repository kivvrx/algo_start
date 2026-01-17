#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    if (n < 3) {
        std::cout << "Goroshek ne na vershine...";
        return 0;
    }

    std::vector<int> peaks;
    for (int i = 1; i < n - 1; i++) {
        if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
            peaks.push_back(i);
        }
    }

    if (peaks.size() < 2) {
        std::cout << "Goroshek ne na vershine...";
        return 0;
    }

    // так как как массив пиков уже отсортирован по возрастанию индексов максимальное расстояние 
    // будет между самым левым и самым правым пиком
    int max_distance = peaks.back() - peaks.front();

    std::cout << max_distance;
    return 0;
}