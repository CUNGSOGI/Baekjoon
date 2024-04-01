#include <stdio.h>

int main() {
	int x, y;
	scanf("%d %d", &x, &y);
	if (x < 0) {
		if (y < 0)
			printf("3");
		else
			printf("2");
	}
	else {
		if (y < 0)
			printf("4");
		else
			printf("1");
	}
}