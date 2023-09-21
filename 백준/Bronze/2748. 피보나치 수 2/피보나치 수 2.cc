#pragma warning(disable:4996)
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

long long int fibonacci(int n) {
    vector<long long int> v(n+2, 0);
    v[0] = 0, v[1] = 1;
    if (n == 0 || n == 1)
        return v[n];
    for (int i = 2; i <= n; i++)
        v[i] = v[i - 1] + v[i - 2];
    return v[n];
}//DP

int main() {
    int n;
    scanf("%d", &n);
    printf("%lld", fibonacci(n));
}