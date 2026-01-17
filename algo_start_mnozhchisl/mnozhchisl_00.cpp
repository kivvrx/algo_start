// 32 2 4 8 
#include <iostream>
int main() {
	int x;
	std::cin >> x;
	int count = 0;
	for (int i = 1; i*i <= x; ++i) {
		
		if (x % i == 0) {
			if (x / i == i) {
				count += 1;
			}
			else
			count += 2;
		}
	}
	std::cout << count;
	return 0;
}

// 100 
// 1*100 2*50 4*25 5*20  10*10 50*2