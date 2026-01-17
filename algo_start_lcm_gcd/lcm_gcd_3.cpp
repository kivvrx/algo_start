#include <iostream>
#include <vector>
int gcd_recursive(int a, int b) {
	return b == 0 ? a : gcd_recursive(b, a % b);
}

int gcd_vector(const std::vector<int>& numbers) {
	if (numbers.empty()) return 0;

	int result = numbers[0];
	for (size_t i = 1; i < numbers.size(); i++) {
		result = gcd_recursive(result, numbers[i]);
		if (result == 1) break;
	}
	return result;
}


int main() {
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	for (auto& aa : a) std::cin >> aa;
	std::cout << gcd_vector(a);
    return 0;
}
