#include <iostream>
#include <string>
#include <vector>

int main() {
    std::string s;
    std::cin >> s;

    std::vector<int> result;
    int n = s.size();

    for (int i = 0; i < n; ) {
        int j = i;
        while (j < n && s[j] == s[i]) {
            j++;
        }
        int len = j - i;
        if (len > 1) {
            result.push_back(len - 1);
        }
        i = j;
    }

    if (result.empty()) {
        std::cout << "MEGA TEST!\n";
    }
    else {
        for (int x : result) {
            std::cout << x << " ";
        }
        std::cout << "\n";
    }

    return 0;
}
