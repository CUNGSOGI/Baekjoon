#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include<math.h>

using namespace std;

int n;
vector<vector<int>> v(26,vector<int>(2,0));
vector<int> vi(26, 0);

void pre(int a,int m) {
	if (a == 0) {
		vi[m]++;
		cout << (char)(m + 'A');
		if (v[m][0] != 0&&vi[v[m][0]]==0)	pre(0,v[m][0]);
		if (v[m][1] != 0 && vi[v[m][1]] == 0)	pre(0,v[m][1]);
	}
	if (a == 1) {
		vi[m]++;
		if (v[m][0] != 0 && vi[v[m][0]] == 0)	pre(1, v[m][0]);
		cout << (char)(m + 'A');
		if (v[m][1] != 0 && vi[v[m][1]] == 0)	pre(1, v[m][1]);
	}
	if (a == 2) {
		vi[m]++;
		if (v[m][0] != 0 && vi[v[m][0]] == 0)	pre(2, v[m][0]);
		if (v[m][1] != 0 && vi[v[m][1]] == 0)	pre(2, v[m][1]);
		cout << (char)(m + 'A');
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int i,j,z;
	char a;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> a;
		for (j = 0, z=a-'A'; j < 2; j++) {
			cin >> a;
			if(a!='.')
				v[z][j] = a - 'A';
		}
	}
	pre(0,0);
	cout << "\n";
	vi.assign(n, 0);
	pre(1, 0);
	cout << "\n";
	vi.assign(n, 0);
	pre(2, 0);
	cout << "\n";
}