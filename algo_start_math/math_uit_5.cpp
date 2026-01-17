#include <iostream>
#include <vector>
#include <string>

int main() {
    int t;
    std::cin >> t;
    std::vector<std::string> out;
    out.reserve(t);
    for (int i = 0; i < t; ++i) {
        long long A, B;
        std::cin >> A >> B;
        if (B == 1) {
            out.emplace_back("NO");
            continue;
        }
        long long x, y, z;
        if (B == 2) {
            // x = A, y = 5A, z = 6A
            x = A;
            y = 5 * A;
            z = 6 * A;
        }
        else {
            // x = A, y = A(B-1), z = AB
            x = A;
            y = A * (B - 1);
            z = A * B;
        }
        out.emplace_back("YES\n" + std::to_string(x) + " " + std::to_string(y) + " " + std::to_string(z));
    }
    for (const auto& s : out) {
        std::cout << s << '\n';
    }
    return 0;
}
