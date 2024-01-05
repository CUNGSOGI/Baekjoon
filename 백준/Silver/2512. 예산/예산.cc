#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m, i, j, t = 0, z = 0;
	cin >> n;
	vector<int> v(n, 0);
	for (i = 0; i < n; i++)
		cin >> v[i], t += v[i];
	cin >> m;
	sort(v.rbegin(), v.rend());

	if (t > m) {
		v.push_back(0);
		for (i = 1; i <= n; i++) {
			for (j = 0, z = 0; j < i; j++) {
				z += (v[j] - v[i]);
			}
			if (t - z <= m) break;
		}
		cout << v[i] + ((m - (t - z)) / i);
	}
	else
		cout << v[0];
}