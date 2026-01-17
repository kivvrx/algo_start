#include <iostream>
#include <map>

int main() {
    int n;
    std::cin >> n;
    std::map<int, int> freq;
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        ++freq[x];
    }
    int max_count = 0;
    int result = 0;
    for (const auto& [num, count] : freq) {
        if (count > max_count || (count == max_count && num > result)) {
            max_count = count;
            result = num;
        }
    }
    std::cout << result;
    return 0;
}
