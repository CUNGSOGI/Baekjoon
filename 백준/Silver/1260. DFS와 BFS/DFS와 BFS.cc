#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
int n, m, v, i, j, a, b ,vt[1001][1001] = { 0 };
vector<int> r;
vector<int> vi(1001, 0);
void DFS(int c) {
	vi[c] = 1;
	r.push_back(c);
	for (int i = 1; i <= n; i++) {
		if (vt[c][i] == 1 && vi[i] == 0)
			DFS(i);
	}
}

void BFS(int c) {
	queue<int> q;
	q.push(c);
	vi[c] = 1;
	r.push_back(c);
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (i = 1; i <= n; i++) {
			if (vt[x][i] == 1 && vi[i] == 0)
				q.push(i), vi[i] = 1, r.push_back(i);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> v;
	for (i = 0; i < m; i++)
		cin >> a >> b, vt[a][b] = 1, vt[b][a] = 1;
	DFS(v);
	for (i = 0; i < r.size(); i++)
		cout << r[i] << " ";
	cout << "\n";
	r.clear();
	fill(vi.begin(), vi.end(), 0);
	BFS(v);
	for (i = 0; i < r.size(); i++)
		cout << r[i] << " ";
}