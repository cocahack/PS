#include <bits/stdc++.h>
using namespace std;
 
int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    multiset<int> bb;
    for(int b : B) bb.insert(b);
    
    for(int a : A){
        auto iter = bb.upper_bound(a);
        if(iter != bb.end() && a < *iter){
            answer++;
            bb.erase(iter);
        } else {
            bb.erase(bb.begin());
        }
    }
    
    return answer;
}
