#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<int>> v(105, vector<int>(105, 0));
queue<pair<int, int>> q;
int t = 0;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

int bfs(int x, int y, vector<string> maps) {
    int i, j;
    q.push({ x,y });
    v[x][y] = 1;
    while (!q.empty()) {
        pair<int, int> xy = q.front();
        q.pop();
        for (i = 0; i < 4; i++) {
            x = xy.first, y = xy.second;
            x += dx[i], y += dy[i];
            if (x >= 0 && y >= 0&&x < maps.size() &&y < maps[i].size()) {
                if (maps[x][y] != 'X') {
                    if (v[x][y] != 0) continue;
                    q.push({ x,y });
                    v[x][y]++;
                    continue;
                }
            }
 
        }
        t += maps[xy.first][xy.second]-48;
    }
    return t;
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    int i, j;
    for (i = 0; i < maps.size(); i++) {
        for (j = 0; j < maps[0].size(); j++) {
            if (maps[i][j]!='X' && v[i][j] == 0) {
                bfs(i, j, maps);
                answer.push_back(t);
                t = 0;
            }
        }
    }
    sort(answer.begin(), answer.end());
    if (!answer.empty()) return answer;
    else {
        answer.push_back(-1);
        return answer;
    }
}