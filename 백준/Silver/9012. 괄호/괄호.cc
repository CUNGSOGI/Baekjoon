#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

stack<char> st;
string s;

void vps(int i) {
	st.push(s[i]);
	for (int j = i + 1; j < s.length(); j++) {
		if (st.empty() || s[j] == '(') {
			vps(j);
			break;
		}
		if (st.top()=='('&&s[j] == ')')
			st.pop();
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, i, j;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> s;
		st = stack<char>();
		vps(0);
	if (st.empty())
		cout << "YES" <<'\n';
	else
		cout << "NO"<<'\n';
	}
}