#pragma warning(disable:4996)
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<algorithm>
#include<utility>	
#define M 9999999

using namespace std;

void BFS(int p, int m, vector<int> &c, vector<vector<int>> &meeting, int cnt) {
	vector<int> v;
	vector<int>::size_type it;
	int i;
	v.push_back(p);
	c[p] = cnt;
	for (it = 0; it < v.size(); it++) {
		int r = v[it];
		for (i = 1; i <= m; i++) {
			if (meeting[r][i] == 1 && c[i] == 0) {
				v.push_back(i);
				c[i] = cnt;
			}
		}
	}
}

int main() {
	int i, j, k, l, m, n;
	scanf("%d %d", &m, &n);//정점의 갯수, 간선의 수
	vector<vector<int>> meeting(m + 1, (vector<int>(m + 1, M)));
	for (i = 1; i <= m; i++) meeting[i][i] = 0;
	
	vector<int> ck(m+1,0);
	for (i = 0; i < n; i++) {
		scanf("%d %d", &j, &k);
		meeting[j][k] = meeting[k][j] = 1;
	}

	for (i = 1, j = 1; i <= m; i++) {
		if (ck[i] == 0) {
			BFS(i, m, ck, meeting, j);
			j++;
		}
	}

	printf("%d\n", j - 1);
	vector<int> w(j, M);
	vector<int> z(j, 0);
	///플로이드-워셜 알고리즘
	for (k = 1; k <= m; k++) {
		for (j = 1; j <= m; j++) {
			for (i = 1; i <= m; i++)
				meeting[i][j] = min(meeting[i][j], meeting[i][k] + meeting[k][j]);
		}
	}
	for (i = 1; i <= m; i++) {
		k = 0;
		for (j = 1; j <= m; j++) {
			if (meeting[i][j] == M) meeting[i][j] = 0;
			if (k < meeting[i][j]) k = meeting[i][j];
		}
		l = ck[i];
		if (k < w[l]) {
			w[l] = k;
			z[l] = i;
		}
	}
	sort(z.begin(), z.end());
	for (vector<int>::size_type it = 1; it < z.size(); it++)
		printf("%d\n", z[it]);
	return 0;
}