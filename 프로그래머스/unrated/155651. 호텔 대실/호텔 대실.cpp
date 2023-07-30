#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> book_time) {
    int answer = 1,i,j,k,t=0;
    vector<pair<int,int>> s;
    vector<int> v(2561,0);
    for(i=0;i<book_time.size();i++){
        book_time[i][0].erase(book_time[i][0].begin()+2,book_time[i][0].begin()+3);
        book_time[i][1].erase(book_time[i][1].begin()+2,book_time[i][1].begin()+3);
        if((stoi(book_time[i][1])+10)%100>=60)
            s.push_back({stoi(book_time[i][0]),stoi(book_time[i][1])+110-60});  
        else
            s.push_back({stoi(book_time[i][0]),stoi(book_time[i][1])+10});
    }
    for(i=0;i<book_time.size();i++){
        for(j=s[i].first;j<s[i].second;j++){
            v[j]++;
        }
    }
    sort(v.begin(),v.end());
    int sz = v.size();
    return v[sz-1];
}