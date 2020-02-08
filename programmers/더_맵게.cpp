#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    multiset<int> q;
    
    for(auto s : scoville) q.insert(s);
    
    while(q.size() > 1 && *q.begin() < K) {
        auto first = q.begin();
        int fv = *first;
        q.erase(first);
        auto second = q.begin();
        int se = *second;
        q.erase(second);
        int new_scovile = fv + (se * 2);
        q.insert(new_scovile);
        answer++;
    }
   
    return *q.begin() >= K ? answer : -1;
}
