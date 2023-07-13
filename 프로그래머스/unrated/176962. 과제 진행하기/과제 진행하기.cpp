#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

struct plan{
    string n;
    int s,p;
};

bool cmp(const plan &x,const plan &y){
    return x.s>y.s;
}

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    vector<int> stop;
    vector<plan> v;
    int i,j,t=0,k=0;
    for(i=0;i<plans.size();i++){
        t=(int)(stoi(plans[i][1]))*60;
        reverse(plans[i][1].begin(),plans[i][1].end());
        for(j=plans[i][1].size()-3;j>=0;j--){
           // if('0'<plans[i][1][j]&&plans[i][1][j]<'9')
              t+=(plans[i][1][j]-'0')*pow(10,j);  
        }
        v.push_back({plans[i][0],t,stoi(plans[i][2])});
    }
    sort(v.rbegin(),v.rend(),cmp);
    
    for(i=1;i<plans.size();i++){
        if(v[i].s-v[i-1].s<v[i-1].p){
            v[i-1].p-=v[i].s-v[i-1].s;
            stop.push_back(i-1);
        }
        else if(v[i].s-v[i-1].s==v[i-1].p){
            answer.push_back(v[i-1].n);    
        }
        else if(v[i].s-v[i-1].s>v[i-1].p){
            answer.push_back(v[i-1].n);
            for(j=stop.size()-1,k=v[i].s-v[i-1].s-v[i-1].p;j>=0;j--){
                if(k==0)
                    break;
                if(k<v[stop[j]].p){
                    v[stop[j]].p-=k;
                    k=0;
                }
                else if(k>v[stop[j]].p){
                    k-=v[stop[j]].p;
                    answer.push_back(v[stop[j]].n);
                    stop.pop_back();
                }
                else if(k==v[stop[j]].p){
                    k-=v[stop[j]].p;
                    answer.push_back(v[stop[j]].n);
                    stop.pop_back();
                }
            }
        }
        if(i==plans.size()-1&&stop.size()==0)
            answer.push_back(v[i].n);
        else if(i==plans.size()-1&&stop.size()>0){
            answer.push_back(v[i].n);
            for(j=stop.size()-1;j>=0;j--){
                answer.push_back(v[stop[j]].n);
            } 
        }
    } 
    return answer;
}