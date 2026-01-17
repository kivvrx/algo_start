//0 уже отсортировано
//1 если 1 уже слева или n уже справа то одним перетасовыванием подходящего подотрезка
//можно довести массив до отсортированного состояния
//3 когда n слева и 1 справа нельзя одновременно исправить оба края без затрагивания всего 
//массива  нужен дополнительный промежуточный шаг и суммарно выходит 3
//2 остальные случаи приводятся к отсортированному виду двумя корректными 
//перетасовками подходящих подотрезков

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int t;
    std::cin >> t;
    std::vector<int> results;
    results.reserve(t);

    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> a(n);
        for (int i = 0; i < n; ++i) std::cin >> a[i];
        // 0 
        if (std::is_sorted(a.begin(), a.end())) {
            results.push_back(0);
            continue;
        }
        // 1 
        if (a.front() == 1 || a.back() == n) {
            results.push_back(1);
            continue;
        }
        // 3 
        if (a.front() == n && a.back() == 1) {
            results.push_back(3);
            continue;
        }
        // 2
        results.push_back(2);
    }
    for (int ans : results) {
        std::cout << ans << '\n';
    }
    return 0;
}

