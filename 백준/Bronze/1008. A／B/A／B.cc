#include <stdio.h>

int main() {
    float a, b;
    scanf("%f %f", &a, &b);
    printf("%.9f", (double)a / b);
}