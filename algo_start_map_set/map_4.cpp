#include <iostream>
#include <map>
#include <string>
#include <limits>

int main() {
    int n;
    std::cin >> n;
    std::map<std::string, std::pair<int, int>> grades;
    for (int i = 0; i < n; ++i) {
        std::string name;
        int score;
        std::cin >> name >> score;

        if (!grades.count(name)) {
            grades[name] = { score, score };
        }
        else {
            grades[name].first = std::min(grades[name].first, score); 
            grades[name].second = std::max(grades[name].second, score);
        }
    }
    std::string unstable;
    int max_diff = -1;
    for (const auto& [name, range] : grades) {
        int diff = range.second - range.first;
        if (diff > max_diff || (diff == max_diff && name < unstable)) {
            max_diff = diff;
            unstable = name;
        }
    }
    std::cout << unstable;
    return 0;
}
