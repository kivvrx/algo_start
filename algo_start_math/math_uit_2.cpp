#include <iostream>
#include <vector>

int main() {
    int q;
    if (!(std::cin >> q)) return 0;
    std::vector<long long> results; 
    while (q--) {
        int n;
        std::cin >> n;
        long long sum = 0;
        for (int i = 0; i < n; ++i) {
            int x;
            std::cin >> x;
            sum += x;
        }
        long long p = (sum + n - 1) / n;// мы что то делим на n
        // тоесть сколько раз делится число на n если мы к нему прибавим n
        // то мы увеличиваем это что то это сколько раз на 1 
        // отнимаем - 1 для того чтобы если делится нацело то округление шло вниз так как
        // и так у нас уже все нормально
        results.push_back(p);
    }
    for (long long ans : results) {
        std::cout << ans << "\n";
    }
    return 0;
}
