// мы знаем что lcm(a,b) = (a/gcd(a,b)*b) 
// заметим что например 12 кратно 6 потому что 12 = 2*6 тоесть формула кратности 
// b = k * a  значит 
// допустим     у нас l = 5 r = 30 
// возьмем 5 предположим что это x тогда 5*k кратное число 5 
// а значит lcm(x,kx) = (x*kx) / x = kx 
// почему так? потому что наибольший общий делитель из x и kx это x  
// значит мы доказали что достаточно взять число x из диапазона lr и домножить 
// его на k (2,3,4,5...) и посмотреть если kx <= r то этот kx и будет  lcm и он входит 
// в интервал lr


#include <iostream>
#include <vector>

int main() {
    int t;
    std::vector<std::pair<int, int>> answer;
    std::cin >> t;
    while (t--) {
        int l, r;
        std::cin >> l >> r;
        std::pair<int, int> ans{-1, -1};
        if (2 * l <= r) {
            ans = { l, 2 * l };
        }
        answer.emplace_back(ans);
    }
    for (const auto& a : answer) std::cout << a.first << " " << a.second << "\n";
    return 0;
}

