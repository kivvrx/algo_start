#include <iostream>
#include <unordered_map>
#include <limits>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    std::unordered_map<int, std::pair<int, int>> positions;
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        if (positions.count(a[i]) == 0) {
            positions[a[i]] = { i, i }; // первое вхождение
        }
        else {
            positions[a[i]].second = i; // обновляем последнее вхождение
        }
    }
    int max_distance = -1;
    int result_value = std::numeric_limits<int>::max();
    for (const auto& entry : positions) {
        int value = entry.first;
        int first = entry.second.first;
        int last = entry.second.second;
        int distance = (first == last) ? -1 : last - first - 1;
        if (distance > max_distance || (distance == max_distance && value < result_value)) {
            max_distance = distance;
            result_value = value;
        }
    }
    std::cout << result_value << ' ' << max_distance << '\n';
    return 0;
}