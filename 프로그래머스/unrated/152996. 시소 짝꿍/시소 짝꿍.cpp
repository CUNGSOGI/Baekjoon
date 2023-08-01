#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(vector<int> weights) {
    long long answer = 0,i,j;
    vector<int> v(1001,0);
    sort(weights.begin(),weights.end());
    for(i=0;i<weights.size();i++){
        for(j=i+1;j<weights.size();j++){
            if((weights[i]==weights[j]||weights[j]*2==weights[i]*3||weights[j]*2==weights[i]*4||weights[j]*3==weights[i]*4||weights[j]*3==weights[i]*2||weights[j]*4==weights[i]*3||weights[j]*4==weights[i]*2)){
                answer++;
            }
        }
    }
    return answer;
}