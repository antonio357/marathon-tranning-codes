#include<iostream>

#define True 1
#define False 0

int func(int val, int reset) {
	static int counter;
	if (reset == True) counter = 0;
	counter += 1;
	if (val == 1) return counter;
	else if (val % 2 == 0) return func(val / 2, False);
	return func(val * 3 + 1, False);
}

int main() {
	int i, j, biggest, c, c_;
	while (!std::cin.eof()) {
		//scanf("%d %d", &i, &j) != EOF
		std::cin >> i >> j;
		biggest = 0;
		if (i <= j) {
			for (c = i; c <= j; c++) {
				c_ = func(c, True);
				if (c_ > biggest) biggest = c_;
			}
		}
		else {
			for (c = j; c <= i; c++) {
				c_ = func(c, True);
				if (c_ > biggest) biggest = c_;
			}
		}
		//printf("%d %d %d\n", i, j, biggest);
		std::cout << i << " " << j << " " << biggest << "\n";
	}
	return 0;
}