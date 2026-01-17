#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>

int main() {
    std::string s;
    std::cin >> s;
    int digits = 0, upper = 0, lower = 0;
    std::set<char> digit_set, upper_set, lower_set;
    for (char c : s) {
        if (std::isdigit(static_cast<unsigned char>(c))) {
            ++digits;
            digit_set.insert(c);
        }
        else if (std::isupper(static_cast<unsigned char>(c))) {
            ++upper;
            upper_set.insert(c);
        }
        else if (std::islower(static_cast<unsigned char>(c))) {
            ++lower;
            lower_set.insert(c);
        }
    }
    int max_count = std::max({ digits, upper, lower });
    std::vector<char> result;
    if (digits == max_count && !digit_set.empty()) {
        result.push_back(*digit_set.begin());
    }
    if (upper == max_count && !upper_set.empty()) {
        result.push_back(*upper_set.begin());
    }
    if (lower == max_count && !lower_set.empty()) {
        result.push_back(*lower_set.begin());
    }

    for (char c : result) {
        std::cout << c << ' ';
    }
    return 0;
}