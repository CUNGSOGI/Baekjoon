#include <iostream>
#include <vector>
#include<algorithm>
#include<queue>

using namespace std;

int main() {
	int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };
	int n, m, i, j;
	char a[101] = {};
	queue<pair<int, int>> q;
	cin >> n >> m;
	vector<vector<int>> v(n, vector<int>(m, 0)), vi(n, vector<int>(m, 0));
	for (i = 0; i < n; i++) {
		cin >> a;
		for (j = 0; j < m; j++)
			v[i][j] = a[j] - 48;
	}
	q.push({ 0,0 });
	vi[0][0] = 1;
	while (!q.empty()){
		int x = q.front().second, y = q.front().first;
		q.pop();
		for (i = 0; i < 4; i++) {
			if (0 > x - dx[i] || x - dx[i] >= m || 0 > y - dy[i] || y - dy[i] >= n) continue;
			if (v[y - dy[i]][x - dx[i]] >= 1 && vi[y - dy[i]][x - dx[i]] == 0) {
				q.push({ y - dy[i],x - dx[i] });
				vi[y - dy[i]][x - dx[i]] = 1;
				v[y - dy[i]][x - dx[i]] = v[y][x] + 1;
			}
		}
	}
	cout << v[n-1][m-1];
}