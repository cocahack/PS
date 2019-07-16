#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> heights) {
    vector<int> answer = vector<int>(heights.size(), 0);
    vector<vector<int>> signal;
    signal.push_back({heights.back(), (int)heights.size()-1});
    stack<int> tower;
    
    for(int i=heights.size()-2; i>=0; --i){
        sort(signal.begin(), signal.end());
        auto iter = signal.begin();
        while(iter != signal.end() && (*iter)[0] < heights[i]){
            answer[(*iter)[1]] = i+1;
            iter++;
        }
        signal.erase(signal.begin(), iter);
        signal.push_back({heights[i], i});
    }
    
    
    return answer;
}
