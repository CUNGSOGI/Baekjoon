#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int i, n, s = 0, e = 0, ms = 0, me = 0, sum = 0, m = INT_MIN;
	cin >> n;
	vector<int> v(n,0);
	for (i = 0; i < n; i++)
		cin >> v[i];
	for (i = 0; i < n; i++) {
		if (v[i] + sum >= v[i])
			e += 1, sum += v[i];
		else
			s = i,e=i,sum=v[i];
		if (m < sum) {
			ms = s, me = e,m=sum;
		}
	}
	cout << m;
}