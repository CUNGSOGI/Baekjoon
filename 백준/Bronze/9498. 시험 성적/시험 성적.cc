#include <stdio.h>

int main() {
    int a, b;
    scanf("%d", &a);
    if (90 <= a && 100 >= a)
        printf("%c", 'A');
    else if (80 <= a && 89 >= a)
        printf("%c", 'B');
    else if (70 <= a && 79 >= a)
        printf("%c", 'C');
    else if (60 <= a && 69 >= a)
        printf("%c", 'D');
    else
        printf("%c", 'F');

}