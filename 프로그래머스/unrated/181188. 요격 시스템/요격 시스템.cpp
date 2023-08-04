#include <string>
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;

bool cmp(vector<int> &x,vector<int> &y){
    return x[1]<y[1];
}

int solution(vector<vector<int>> targets) {
    int answer = 1,i,j;
    sort(targets.begin(),targets.end(),cmp);
    for(i=1,j=0;i<targets.size();i++){
         if(targets[i][0]>=targets[j][1]){
            j=i;
            answer++;
        }
    }
    
    return answer;
}