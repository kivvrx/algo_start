#include <iostream>
#include <vector>

int main() {
    int n, a, b;
    std::cin >> n >> a >> b;
    // пример если n четное ничего не изменится 
    // а если n нечетное то демократов будет на 1 больше 
    // чтобы это учесть надо прибавить единицу например n = 7 
    // 7+1/2 = 4 7/2 = 3 все правильно 
    int democrats = (n + 1) / 2; // нечётные
    int republicans = n / 2;     // чётные
    int total = a * b;
    // опять же потому что total может быть четным или нечетным
    int black = (total + 1) / 2; 
    int white = total / 2;
    bool possible = false; // возможно ли вообще рассадить
    bool demOnBlack = false; // демократы сидят на белых клетках а true наоборот

    if (democrats <= black && republicans <= white) {
        possible = true;
        demOnBlack = true;
    }
    else if (democrats <= white && republicans <= black) {
        possible = true;
        demOnBlack = false;
    }

    if (!possible) {
        std::cout << -1 << "\n";
        return 0;
    }

    std::vector<int> dem, rep;
    for (int i = 1; i <= n; ++i) {
        if (i % 2 == 1) dem.push_back(i);
        else rep.push_back(i);
    }

    std::vector<std::vector<int>> hall(a, std::vector<int>(b, 0));

    for (int i = 0; i < a; ++i) {
        for (int j = 0; j < b; ++j) {
            bool isBlack = ((i + j) % 2 == 0);
            if (demOnBlack == isBlack) {
                if (!dem.empty()) {
                    hall[i][j] = dem.back();
                    dem.pop_back();
                }
            }
            else {
                if (!rep.empty()) {
                    hall[i][j] = rep.back();
                    rep.pop_back();
                }
            }
        }
    }
    for (int i = 0; i < a; ++i) {
        for (int j = 0; j < b; ++j) {
            std::cout << hall[i][j] << (j + 1 == b ? '\n' : ' ');
        }
    }
    return 0;
}
