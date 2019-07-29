#include <bits/stdc++.h>
using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    
    priority_queue<long long> q;
    for(auto w : works) q.push(w);
    
    while(n-- && q.size()) {
        auto work = q.top();
        q.pop();
        
        if(work-1 > 0) q.push(work-1);
    }
    
    while(q.size()){
        auto work = q.top();
        q.pop();
        
        answer += work * work;
    }
    
    return answer;
}
