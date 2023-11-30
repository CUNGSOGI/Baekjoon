#pragma warning(disable:4996)
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<math.h>

using namespace std;

bool cmp(pair<int,int> a,pair<int,int> b) {
	if (a.first < b.first) return true;
	else if (a.first == b.first && a.second < b.second) return true;
	else return false;
}

int main() {
	int n;
	scanf("%d", &n);

	int i,j, a, b;
	vector<pair<int, int>> v;
	v.push_back({ 0,600 }); v.push_back({ 1320,0 });
	for (i = 0; i < n; i++) {
		scanf("%d %d", &a, &b);
		v.push_back({ ((a/100)*60+a%100) - 10, ((b / 100) * 60 + b % 100)+10});
	}

	vector<int> t;
	sort(v.begin(), v.end(),cmp);
	for (i = 1, a = v[0].second; i <= n + 1; i++) {
		if(a<v[i].first)
			t.push_back(abs(v[i].first -a));
		if (a < v[i].second) a = v[i].second;
	}
	sort(t.rbegin(), t.rend());
	printf("%d", t[0]);
}