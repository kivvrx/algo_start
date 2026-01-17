#include <iostream>
#include <vector>
// встретятся если координаты будут равны 
// первого и второго у нас координата только по x
// x + at = y - bt
// t = (y-x)/(a+b)
// должно быть целочисленное деление
int main() {
    int t;
    std::cin >> t;
    std::vector<int> results;
    while (t--) {
        long long x, y, a, b;
        std::cin >> x >> y >> a >> b;
        long long delta = y - x;
        long long step = a + b;
        if (delta % step == 0) {
            results.push_back(delta / step);
        }
        else {
            results.push_back(-1);
        }
    }
    for (int res : results) {
        std::cout << res << '\n';
    }
    return 0;
}
