#include <iostream>
#include <vector>
#include <string>

int main() {
    int t;
    std::cin >> t;
    std::vector<std::string> results;
    results.reserve(t);
    while (t--) {
        int n;
        std::cin >> n;
        bool found = false;
        int x_ans = -1, y_ans = -1, z_ans = -1;
        for (int x = 0; x <= n / 3 && !found; ++x) {
            for (int y = 0; y <= n / 5 && !found; ++y) {
                int rest = n - 3 * x - 5 * y;
                if (rest >= 0 && rest % 7 == 0) {
                    int z = rest / 7;
                    x_ans = x;
                    y_ans = y;
                    z_ans = z;
                    found = true;
                }
            }
        }
        if (found) {
            results.push_back(std::to_string(x_ans) + " " +
                std::to_string(y_ans) + " " +
                std::to_string(z_ans));
        }
        else {
            results.push_back("-1");
        }
    }
    for (const auto& res : results) {
        std::cout << res << '\n';
    }
    return 0;
}
