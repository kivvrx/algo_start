#include <iostream>
#include <set>

int main() {
    int n, k;
    std::cin >> n >> k;
    std::set<int> a, b;
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        a.insert(x);
    }
    for (int i = 0; i < k; i++) {
        int x;
        std::cin >> x;
        b.insert(x);
    }
    bool subs = true;
    for (int x : a) {
        if (!b.count(x)) {
            subs = false;
            break;
        }
    }
    if (subs) std::cout << "YES\n";
    else std::cout << "NO\n";

    return 0;
}
