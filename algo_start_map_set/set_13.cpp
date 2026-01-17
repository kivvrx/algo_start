#include <iostream>
#include <set>
#include <vector>

struct t {
    int a, b;
    bool operator<(const t& other) const {
        return (a < other.a) || (a == other.a && b < other.b);
    }
    friend std::istream& operator>>(std::istream& in, t& obj) {
        return in >> obj.a >> obj.b;
    }
};

int main() {
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;

    std::set<t> slots;
    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        t ob{};
        std::cin >> ob;
        slots.insert(ob);
    }

    std::vector<t> v;

    while (a < c || (a == c && b <= d)) {
        t obj{ a, b };
        if (!slots.count(obj)) {
            v.push_back(obj);
        }
        b += 15;
        if (b == 60) {
            ++a;
            b = 0;
        }
    }

    std::cout << v.size() << "\n";
    for (auto& slot : v) {
        std::cout << slot.a << " " << slot.b << "\n";
    }

    return 0;
}
