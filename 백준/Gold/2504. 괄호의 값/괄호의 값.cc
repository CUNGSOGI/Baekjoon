#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>

using namespace std;

int t=1;
string n;
stack<pair<char,int>> v;
vector<int> vi(31,0);

void st(int i) {
	v.push({ n[i], i});
	for (int j = i+1; j < n.length(); j++) {
		if (v.empty() || '(' == n[j] || '[' == n[j]) {
			st(j);
			break;
		}
		if ((v.top().first == '(' && n[j] == ')') || (v.top().first == '[' && n[j] == ']')) {
			vi[v.top().second] = t;
			vi[j] = t;
			t++;
			v.pop();
		}
	}
}

int f(int i, int j) {
	if (i > j) return 1;
	int k = i+1;
	for (k; k < j; k++) {
		if (vi[i] == vi[k])
			break;
	}
	if (vi[i] == vi[j] && n[i] == '(') return 2 * f(i + 1, j - 1);
	else if(vi[i] == vi[j] && n[i] == '[') return 3 * f(i + 1, j - 1);
	else return f(i, k) + f(k + 1, j);
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int r=0,l=0,br=0,bl=0;
	cin >> n;
	st(0);
	if (!v.empty()) {
		cout << '0';
		return 0;
	}
	cout << f(0, n.length()-1);
}
