//если два одинаковых символа стоят рядом то они должны быть заменены на разные 
//биты  что невозможно потому что одна буква  один бит
//следовательно если в строке есть два одинаковых символа подряд то решения нет
//каждая буква должна быть заменена на один бит
//если она стоит на чётных и нечётных позициях  она должна быть и 0 и 1 
//поэтому если одна буква встречается на позициях с разной чётностью  ответа нет
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

int main() {
    int t;
    std::cin >> t;
    std::vector<std::string> results;
    // ABCA контрипример почему нельзя проверить наивно два элемента 
    while (t--) {
        int n;
        std::string s;
        std::cin >> n >> s;
        std::unordered_map<char, int> parity; // буква -> чётность позиции (0 или 1)
        bool ok = true;
        for (int i = 0; i < n; ++i) {
            char c = s[i];
            int p = i % 2;
            if (parity.count(c)) {
                if (parity[c] != p) {
                    ok = false;
                    break;
                }
            }
            else {
                parity[c] = p;
            }
        }
        results.push_back(ok ? "YES" : "NO");
    }
    for (const std::string& res : results) {
        std::cout << res << '\n';
    }

    return 0;
}

