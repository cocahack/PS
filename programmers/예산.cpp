#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;
    sort(d.begin(), d.end());
    int idx = 0; 
    while(budget && idx < d.size()){
        if(budget - d[idx] < 0) break;
        
        budget -= d[idx];
        idx++;
        answer++;
    }
    
    return answer;
}
