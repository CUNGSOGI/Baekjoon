#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int x, int y, int n) {
    int answer = 0, i, j,chk=0;
    queue<int> q;
    vector<int> v(1000001,0);
    q.push(x);
    if(x==y) return 0;
    while (!q.empty()) {
        chk=q.front();
        q.pop();
        int dx[3] = { chk + n, chk * 2, chk * 3 };
        for (i = 0; i < 3; i++) {
            x = dx[i];
            if (y < x||v[x]!=0) continue;
            if (y == x) return v[chk]+1;
            q.push(x);
            v[x]=v[chk]+1;
        }
    }
    return -1;
}