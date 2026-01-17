#include <iostream>
#include <vector>

int main() {
    int n;
    long long k;
    std::cin >> n >> k;

    std::vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::vector<long long> result;
    long long need = k;

    for (int i = 0; i < n; i++) {
        if (a[i] == need) {
            result.push_back(need);
            need++;
        }
    }

    if (result.empty()) {
        std::cout << "Slavyanskay golodovka\n";
    }
    else {
        for (long long x : result) {
            std::cout << x << " ";
        }
        std::cout << "\n";
    }

    return 0;
}
