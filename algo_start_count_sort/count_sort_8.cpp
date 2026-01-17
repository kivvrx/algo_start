#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> nneg, neg;
    nneg.reserve(n);
    neg.reserve(n);
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        if (x >= 0) nneg.push_back(x);
        else neg.push_back(x);
    }
    std::sort(nneg.begin(), nneg.end()); // неубывание
    std::sort(neg.begin(), neg.end(), std::greater<int>()); // невозрастание
    for (int x : nneg) std::cout << x << " ";
    for (int x : neg) std::cout << x << " ";
    std::cout << "\n";
    return 0;
}