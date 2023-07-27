#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls) {
    vector<int> answer;
    vector<int> v;
    int i,j;
    for(i=0;i<balls.size();i++){
        if(startX!=balls[i][0]||startY<=balls[i][1])
            v.push_back(pow(startX-balls[i][0],2)+pow(startY+balls[i][1],2));
        if(startX>=balls[i][0]||startY!=balls[i][1])
            v.push_back(pow(startX-2*m+balls[i][0],2)+pow(startY-balls[i][1],2));
        if(startX!=balls[i][0]||startY>=balls[i][1])
            v.push_back(pow(startX-balls[i][0],2)+pow(startY-2*n+balls[i][1],2));
        if(startX<=balls[i][0]||startY!=balls[i][1])
            v.push_back(pow(startX+balls[i][0],2)+pow(startY-balls[i][1],2));
        sort(v.begin(),v.end());
        answer.push_back(v[0]);
        v.clear();
        }
    return answer;
}
