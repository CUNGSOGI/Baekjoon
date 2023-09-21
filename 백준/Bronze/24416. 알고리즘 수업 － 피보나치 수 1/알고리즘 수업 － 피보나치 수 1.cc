#pragma warning(disable:4996)
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int fib(int n) {
    if (n == 1|| n == 2)
        return 1;
    else return (fib(n - 1) + fib(n - 2));
}//재귀

int fibonacci(int n) {
    vector<int> v(n,0);
    v[0] = 0, v[1] = 1;
    for (int i = 2; i < n; i++)
        v[i] = v[i - 1] + v[i - 2];
    return n-2;
}//DP

int main() {
	int n;
	scanf("%d", &n);
    printf("%d %d", fib(n), fibonacci(n));
}