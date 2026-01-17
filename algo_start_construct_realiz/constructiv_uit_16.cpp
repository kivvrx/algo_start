#include <iostream>
#include <vector>

int main() {
    int t;
    std::cin >> t;
    std::vector<std::vector<int>> answers;
    answers.reserve(t);

    for (int _ = 0; _ < t; ++_) {
        int n;
        std::cin >> n;
        std::vector<int> arr;
        arr.reserve(n);
        for (int i = 0; i < n; ++i) {
            arr.push_back(2 * i + 1); // нечётные числа
        }
        answers.push_back(std::move(arr));
    }
    for (const auto& arr : answers) {
        for (int x : arr) {
            std::cout << x << " ";
        }
        std::cout << "\n";
    }
    return 0;
}
