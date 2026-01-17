#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

int main() {
    int t;
    std::cin >> t;
    std::vector<std::string> out;

    while (t--) {
        int n, k, x;
        std::cin >> n >> k >> x;
        std::vector<int> v;
        for (int i = 1; i <= k; ++i) {
            if (i != x) {
                v.push_back(i);
            }
        }
        if (v.empty()) {
            out.push_back("NO");
            continue;
        }
        std::sort(v.begin(), v.end(), std::greater<int>());

        std::vector<int> result;
        int mn = n;
        while (mn > 0) {
            bool found = false;
            for (int val : v) {
                if (val <= mn) {
                    result.push_back(val);
                    mn -= val;
                    found = true;
                    break;
                }
            }
            if (!found) {
                break;
            }
        }

        if (mn == 0) {
            out.push_back("YES");
            out.push_back(std::to_string(result.size()));
            std::ostringstream oss;
            for (size_t i = 0; i < result.size(); ++i) {
                oss << result[i];
                if (i + 1 < result.size()) {
                    oss << ' ';
                }
            }
            out.push_back(oss.str());
        }
        else {
            out.push_back("NO");
        }
    }
    for (const std::string& line : out) {
        std::cout << line << '\n';
    }
    return 0;
}
