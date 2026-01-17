#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

int main() {
    int n;
    std::cin >> n;
    std::unordered_map<std::string, std::vector<std::string>> phonebook;
    for (int i = 0; i < n; ++i) {
        std::string number, name;
        std::cin >> number >> name;
        phonebook[name].push_back(number);
    }
    int t;
    std::cin >> t;

    for (int i = 0; i < t; ++i) {
        std::string query;
        std::cin >> query;
        auto it = phonebook.find(query);
        if (it != phonebook.end()) {
            const std::vector<std::string>& numbers = it->second;
            for (size_t j = 0; j < numbers.size(); ++j) {
                std::cout << numbers[j];
                if (j + 1 < numbers.size()) {
                    std::cout << ' ';
                }
            }
            std::cout << '\n';
        }
        else {
            std::cout << "Not found\n";
        }
    }
    return 0;
}