#include <iostream>
#include <vector>
#include <unordered_set>
int main() {
	int n;
	std::cin >> n;
	std::vector<int> v;
	std::unordered_set<int> s;
	for (int i = 0; i < n; ++i) {
		int k;
		std::cin >> k;
		if (s.count(k)) v.push_back(k);
		s.insert(k);
	}
	std::cout << v.size();
	return 0;
}