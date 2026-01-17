#include <iostream>
#include <map>
#include <string>

int main() {
    int n;
    std::cin >> n;
    std::map<char, int> count;
    for (int i = 0; i < n; ++i) {
        std::string plate;
        std::cin >> plate;
        char first = plate[0];
        if (count[first] == 0) {
            std::cout << first << " ";
        }
        else {
            std::cout << first << "_" << count[first] << " ";
        }
        count[first]++;
    }
    return 0;
}
