#include <iostream>
#include <map>

int main() {
    int n, m;
    std::cin >> n >> m;
    std::map<int, int> freq;
    for (int i = 0; i < n * m; ++i) {
        int v;
        std::cin >> v;
        ++freq[v];
    }
    int x;
    std::cin >> x;
    int greater = -1;
    auto it_up = freq.upper_bound(x);
    if (it_up != freq.end()) {
        greater = it_up->first;
    }
    int smaller = -1;
    auto it_low = freq.lower_bound(x);
    if (it_low == freq.begin()) {
    }
    else {
        --it_low;
        smaller = it_low->first;
    }
    std::cout << greater << '\n';
    std::cout << smaller << '\n';
    return 0;
}