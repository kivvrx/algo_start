#include <iostream>
#include <vector>

int main() {
    int n, a;
    std::cin >> n;
    std::vector<int> a_n;
    int next, prev;
    while (n--) {
        prev = -2;
        std::cin >> a;
        bool minus_minus = false;
        bool plus_plus = false;
        bool mixed = false;
        int sum = 0;
        if (a >= 2) {
            for (int i = 0; i < a; ++i) {
                if (i >= 1) prev = next;
                std::cin >> next;
                if (next + prev == -2) minus_minus = true;
                else if (next + prev == 2) plus_plus = true;
                else if (next + prev == 0) mixed = true;
                sum += next;
            }
        }
        if (minus_minus) sum += 2 + 2;
        else if (mixed) { ; }
        else sum += -2 + -2;
        a_n.push_back(sum);
    }
    for (const auto& aa : a_n) std::cout << aa << '\n';
    return 0;
}
