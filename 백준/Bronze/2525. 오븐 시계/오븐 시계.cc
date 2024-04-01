#include<stdio.h>

int main() {
	int a, b,c;
	scanf("%d %d %d", &a, &b, &c);
	b += c;
	while (1) {
		if (b >= 60) {
			a += 1;
			b -= 60;
		}
		else {
			printf("%d %d", a, b);
			return 0;
		}
		if (a >= 24)
			a -= 24;
	}
}