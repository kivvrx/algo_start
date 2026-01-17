#include <iostream>
#include <map>
#include <set>
#include <string>

int main() {
    int n;
    std::cin >> n;
    std::map<std::string, std::pair<int, int>> products;
    for (int i = 0; i < n; ++i) {
        std::string name;
        int quantity, price;
        std::cin >> name >> quantity >> price;
        products[name] = { quantity, price };
    }
    int c;
    std::cin >> c;
    std::set<std::string> available;
    for (int i = 0; i < c; ++i) {
        std::string name;
        std::cin >> name;
        available.insert(name);
    }
    int total = 0;
    for (const auto& name : available) {
        if (products.count(name)) {
            total += products[name].first * products[name].second;
        }
    }
    std::cout << total << "\n";
    return 0;
}
