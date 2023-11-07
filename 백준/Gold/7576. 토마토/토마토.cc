#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int m, n, i, j, k, t = 0, qn = 0;
	int dx[4] = { -1,0,1,0 }, dy[4] = { 0,1,0,-1 };
	queue<pair<int, int>> q;
	cin >> m >> n;
	vector<vector<int>> v(n, vector<int>(m, -1));
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			cin >> k, v[i][j] = k;
			if (k == 1)
				q.push({ i,j }); ///2,5 3,4
		}
	}
	qn = q.size();
	while (!q.empty()) {
		if (qn == 0)
			qn = q.size(), t++;
		pair<int, int> xy = q.front();
		q.pop();
		qn--;
		for (i = 0; i < 4; i++) {
			int x = xy.first, y = xy.second;
			x += dx[i], y += dy[i];
			if (x >= n || y >= m || x < 0 || y < 0) continue;
			if (v[x][y] == 1 || v[x][y] == -1) continue;
			v[x][y] = 1;
			q.push({ x,y });
		}
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if (v[i][j] == 0) {
				cout << -1;
				return 0;
			}
		}
	}
	cout << t;
}