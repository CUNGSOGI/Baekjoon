#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int solution(vector<string> board) {
    int answer = 0,i,j,t=0;
    vector<vector<int>> a(100, vector<int>(100, -1));
    queue<pair<int,int>> q;
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    for(i=0;i<board.size();i++){
        for(j=0;j<board[0].size();j++){
            if(board[i][j]=='R') q.push({i,j});
        }
    }
    
    a[q.front().first][q.front().second]=0;
    
    while(!q.empty()){
        pair<int,int> xy =q.front();
        q.pop();
        for(i=0;i<4;i++){
            int x=xy.first,y=xy.second;
            while(1){
                if(x>=board.size()||y>=board[0].size()||x<0||y<0) break;
                if(board[x][y]=='D') break;
                x+=dx[i],y+=dy[i];
            }
            x-=dx[i],y-=dy[i];
            if(board[x][y]=='G')
                return (a[xy.first][xy.second]+1);
            if(a[x][y]>=0) continue;
            a[x][y]=a[xy.first][xy.second]+1;
            q.push({x,y});
        }
    }
    return -1;
}