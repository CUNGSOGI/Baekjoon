#include<algorithm>
#include<vector>
#include<iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,i,k,j,r=0;
	cin >> n;
	vector<int> v;
	for (i = 0, j = 0; i < n; j++,i++) {
		cin >> k,v.push_back(k);
		if (v[j] == 0) {
			v.pop_back();
			v.pop_back();
			j -= 2;
		}
	}
	for (i = 0; i < v.size(); i++)
		r += v[i];
	cout << r;
}