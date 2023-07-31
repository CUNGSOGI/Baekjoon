#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.size(),0);
    stack<pair<int,int>> s;
    int i,j;
    for(i=1;i<numbers.size();i++){
        if(numbers[i-1]>=numbers[i])
            s.push({numbers[i-1],i-1}),answer[i-1]=-1;
        else if(numbers[i-1]<numbers[i])
            answer[i-1]=numbers[i];
        for(j=s.size();j>0;j--){
            if(!s.empty()&&s.top().first<numbers[i]){
                answer[s.top().second]=numbers[i];
                s.pop();
            }
            else if(s.top().first>=numbers[i])
                break;
        }
    }
    answer[answer.size()-1]=-1;
    return answer;
}