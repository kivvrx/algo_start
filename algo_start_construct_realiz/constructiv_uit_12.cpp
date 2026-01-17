#include <iostream>
#include <vector>
#include <unordered_map>

static long long ceil_log2_div(long long n, long long f) {
    // Возвращает ceil(log2(n / f)) для n > f > 0
    long long k = 0;
    long long cur = f;
    while (cur < n) {
        cur *= 2; // удвоение текущего запаса правильных элементов
        ++k;
    }
    return k;
}

int main() {
    int t;
    std::cin >> t;
    std::vector<long long> results;
    results.reserve(t);

    while (t--) {
        int n;
        std::cin >> n;

        std::unordered_map<long long, int> freq;
        freq.reserve(static_cast<std::size_t>(n * 2));

        int f = 0;
        for (int i = 0; i < n; ++i) {
            long long x;
            std::cin >> x;
            int c = ++freq[x];
            if (c > f) f = c;
        }

        if (f == n) {
            results.push_back(0);
            continue;
        }

        long long swaps = static_cast<long long>(n - f);
        long long copies = ceil_log2_div(n, f);
        results.push_back(swaps + copies);
    }

    for (long long ans : results) {
        std::cout << ans << '\n';
    }

    return 0;
}



//#include <iostream>
//#include <vector>
//#include <unordered_map>
//#include <algorithm>
//// число которое возвращает функция не может быть нецелым 
//// это число это число сколько копий нужно сделать если например получается 1.5
//// то c++ округлит вниз но это не правильно потому что нужно больше 1 копии
//// значит округляем вверх прибавив b - 1 
//long long ceil_div(long long a, long long b) {
//    return (a + b - 1) / b;
//}
//int main() {
//    int t;
//    std::cin >> t;
//    std::vector<long long> results;
//    results.reserve(t);
//
//    while (t--) {
//        int n;
//        std::cin >> n;
//        std::unordered_map<long long, int> freq;
//        freq.reserve(n * 2);
//
//        int f = 0;
//        for (int i = 0; i < n; ++i) {
//            long long x;
//            std::cin >> x;
//            int c = ++freq[x];
//            if (c > f) f = c;
//        }
//
//        if (f == n) {
//            results.push_back(0);
//            continue;
//        }
//
//        long long swaps = n - f;
//        // частное это сколько усиленных копий нужно чтобы хватило 
//        // правильных элементов на весь массив
//        // теперь самое главное почему n и почему 2f
//        // n потому что нам надо чтобы все n чисел были одинаковые 
//        // было два массива исходный и копия
//        // A: 0 0 1 2 3 4 5 6 7 8
//        // B: 0 0 1 2 3 4 5 6 7 8
//
//        // после первых обменов собрали все нули в A
//        // A: 0 0 0 0 3 4 5 6 7 8
//        // B: 1 2 1 2 7 8 3 4 5 6
//        
//        // теперь копируем усиленный A  получаем C
//        // A: 0 0 0 0 3 4 5 6 7 8
//        // B: 1 2 1 2 7 8 3 4 5 6
//        // C: 0 0 0 0 3 4 5 6 7 8
//        
//        // начинаем перекладывать нули из C в A
//        // обмен A[4]=3 и C[0]=0
//        // A: 0 0 0 0 0 4 5 6 7 8
//        // C: 3 0 0 0 3 4 5 6 7 8
//        
//        // ещё один обмен A[5]=4 и C[1]=0
//        // A: 0 0 0 0 0 0 5 6 7 8
//        // C: 3 4 0 0 3 4 5 6 7 8
//        
//        // продолжаем пока в A не станет n нулей
//        // A: 0 0 0 0 0 0 0 0 0 0
//        // судя по этому получается что после каждой копии мы получаем 2f (уже после перестановки)
//        // одинаковых элементов  тоесть каждая копия дает 2f нужных нам элементов но не сразу 
//        // как только мы сделали копию а после того как мы сделали копию плюс переставили
//        // 2f элементов тоесть каждая копия прибавляет к массиву 2f элементов 
//        // хорошо значит получается что 1 копия дает 2f элементов 
//        // копия это операция по условию задачи значит очевидно что нужно перестановок
//        // n - f теперь осталось узнать сколько копий нужно 
//        // если одна копия дает нам 2f элементов в массиве 
//        // а нам нужно n элементов значит число копий * 2f мы получим число элементов 
//        long long copies = ceil_div(n, 2LL * f); 
//        results.push_back(swaps + copies);
//    }
//
//    for (long long ans : results) {
//        std::cout << ans << '\n';
//    }
//
//    return 0;
//}
