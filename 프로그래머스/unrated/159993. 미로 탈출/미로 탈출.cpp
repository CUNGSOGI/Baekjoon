#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<string> maps) {
    int answer = 0, i, j, l = 0;
    vector<vector<int>> a(100, vector<int>(100, -1));
    queue<pair<int, int>> q;
    int dx[4] = { -1,0,1,0 };
    int dy[4] = { 0,1,0,-1 };
    for (i = 0; i < maps.size(); i++) {
        for (j = 0; j < maps[i].size(); j++) {
            if (maps[i][j] == 'S') q.push({ i,j });
        }
    }

    a[q.front().first][q.front().second] = 0;
    int t = 0, t2 = 0;
    while (!q.empty()) {
        pair<int, int> xy = q.front();
        q.pop();
        for (i = 0; i < 4; i++) {
            int x = xy.first, y = xy.second;
            x += dx[i], y += dy[i];
            if (x >= maps.size() || y >= maps[0].size() || x < 0 || y < 0)  continue;
            else if (maps[x][y] == 'X')  continue;
            else {
                t++;
                if (maps[x][y] == 'L' && l == 0) {
                    l++;
                    t+= a[xy.first][xy.second];
                    a = vector<vector<int>> (100, vector<int>(100, -1));
                    a[x][y]=t;
                    t = 0;
                    q = queue<pair<int, int>>();
                    q.push({ x,y });
                    break;
                }
                else if (maps[x][y] == 'E' && l == 1)
                    return (a[xy.first][xy.second] + t);
                if (a[x][y] >= 0) {
                    t = 0;
                    continue;
                }
                a[x][y] = a[xy.first][xy.second] + t;
                q.push({ x,y });
                t = 0;
                continue;
            }
            }
        }
    return -1;
}