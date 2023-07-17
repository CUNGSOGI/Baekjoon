#include <string>
#include <vector>
using namespace std;

vector<int> pick_sum(3); //0 : 다이아, 1 : 철, 2 : 돌
vector<int> pick; // 곡괭이 종류 체크(순서는 위와 동일)

int clear = 0;
int answer = 2e9;

void func(int start, int end, vector<string>& minerals){
    if(start == end){
        int fatigue=0; // 곡괭이 피로도 체크
        int sum=0;
        int msize = minerals.size();
        
        for(int i=0;i<msize;i++){
            if(i!=0 && i%5==0){
                fatigue++;
            }
            
            if(fatigue == pick.size()) break;
            
            if(minerals[i] == "diamond"){
                if(pick[fatigue] == 0) sum++;
                else if(pick[fatigue] == 1) sum+=5;
                else if(pick[fatigue] == 2) sum+=25;
            }
            else if(minerals[i] == "iron"){
                if(pick[fatigue] == 0) sum++;
                else if(pick[fatigue] == 1) sum++;
                else if(pick[fatigue] == 2) sum+=5;
            }
            else if(minerals[i] == "stone"){
                if(pick[fatigue] == 0) sum++;
                else if(pick[fatigue] == 1) sum++;
                else if(pick[fatigue] == 2) sum++;
            }
        }
        answer = min(answer, sum);
        return;
    }
    
    for(int i=0;i<3;i++){
        if(pick_sum[i]>0){
            pick_sum[i]--;
            pick.push_back(i);
            func(start+1, end, minerals);
            pick.pop_back();
            pick_sum[i]++;
        }
    }
}

int solution(vector<int> picks, vector<string> minerals) {
    int msize = minerals.size();
    int psize = picks.size();
    
    for (int i=0; i<psize; i++) {
        for (int j=0; j<picks[i]; j++) {
            if (msize > 0) {
                clear++; // 캔 광물 개수 체크
                pick_sum[i]++; // 사용한 곡괭이 수 체크
                msize -= 5; // 광물 개수 제거
            }
        }
    }
    func(0, clear, minerals);
    return answer;
}