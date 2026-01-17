#include <iostream>
#include <vector>
#include <limits>

int main() {
    int n;
    std::cin >> n;
    std::vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    long long min_sum = std::numeric_limits<long long>::max();

    for (int i = 0; i < n; ) {
        long long value = a[i];
        int j = i;
        while (j < n && a[j] == value) {
            j++;
        }
        long long road_sum = value * static_cast<long long>(j - i);
        if (road_sum < min_sum) {
            min_sum = road_sum;
        }
        i = j;
    }

    std::cout << min_sum << "\n";
    return 0;
}
