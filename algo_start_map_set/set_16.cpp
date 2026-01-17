#include <iostream>
#include <set>
#include <string>

int main() {
    int n;
    std::cin >> n;
    std::set<std::string> times;
    bool conflict = false;
    for (int i = 0; i < n; ++i) {
        std::string t;
        std::cin >> t;
        if (times.count(t)) {
            conflict = true;
        }
        times.insert(t);
    }
    std::cout << (conflict ? "NO" : "YES") << "\n";
    return 0;
}
