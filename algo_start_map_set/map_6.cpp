#include <iostream>
#include <map>
#include <string>

int main() {
    int n;
    std::cin >> n;
    // внешний map покупатель -> товар -> количество
    std::map<std::string, std::map<std::string, int>> sales;
    for (int i = 0; i < n; ++i) {
        std::string name, item;
        int qty;
        std::cin >> name >> item >> qty;
        sales[name][item] += qty;
    }
    for (const auto& [name, items] : sales) {
        std::cout << name << ":\n";
        for (const auto& [item, qty] : items) {
            std::cout << item << " " << qty << "\n";
        }
    }
    return 0;
}
