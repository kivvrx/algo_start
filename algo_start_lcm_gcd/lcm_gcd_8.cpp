#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> 
struct v {
    int a, b;
};
bool sr(const v& f1, const v& f2) {
    return 1LL * f1.a * f2.b < 1LL * f2.a * f1.b;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<v> result;
    for (int b = 2; b <= n; ++b) {
        for (int a = 1; a < b; ++a) {
            if (std::gcd(a, b) == 1) {
                result.push_back({ a, b });
            }
        }
    }
    std::sort(result.begin(), result.end(), sr);
    for (const auto& f : result) {
        std::cout << f.a << '/' << f.b << '\n';
    }
    return 0;
}