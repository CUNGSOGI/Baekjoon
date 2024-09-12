#pragma warning(disable:4996)
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
	int m, n, r = 2501;
	char c;
	scanf("%d %d", &n, &m); //n==y, m==x
	vector<vector<int>> nm(n,vector<int>(m,0));
	for (int i=0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf(" %c",&c);
			if (c == 'B')
				nm[i][j] = 1;
		}
	}

	vector<vector<int>> nm1(8, vector<int>(8, 0));
	vector<vector<int>> nm2(8, vector<int>(8, 0));
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if(j%2==1&&i%2==1)
				nm1[i][j] = 1;
			if (j % 2 == 0 && i % 2 == 0)
				nm1[i][j] = 1;
			if (j % 2 == 1 && i % 2 == 0)
				nm2[i][j] = 1;
			if (j % 2 == 0 && i % 2 == 1)
				nm2[i][j] = 1;
		}
	}
	
	queue<pair<int, int>> q;
	for (int i = 0; i <= n-8; i++) {
		for (int j = 0; j <= m-8; j++)
			q.push({i, j});
	}

	while (!q.empty()) {
		int y=q.front().first, x=q.front().second,t=0;
		for (int i = 0; i < 8;i++) {
			for (int j = 0; j < 8;j++) {
				if (nm[i + y][j + x] == nm1[i][j]) continue;
				else t++;
			}
		}
		if (r > t)
			r = t;
		t = 0;
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (nm[i + y][j + x] == nm2[i][j]) continue;
				else t++;
			}
		}
		if (r > t)
			r = t;
		q.pop();
	}
	printf("%d", r);
}