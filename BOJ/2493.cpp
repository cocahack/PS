#include <bits/stdc++.h>
using namespace std;

struct tower_signal
{
    int idx, h;
    tower_signal(int h_, int idx_): idx(idx_), h(h_){}
    bool operator < (const tower_signal& s) const
    {
        if(h == s.h) return idx < s.idx;
        return h < s.h;
    }
};

vector<int> solution(vector<int>& heights) {
    vector<int> answer = vector<int>(heights.size(), 0);
    set<tower_signal> signals;
    signals.insert(tower_signal{heights.back(), (int)heights.size()-1});
    stack<int> tower;

    for(int i=heights.size()-2; i>=0; --i){
        auto iter = signals.begin();
        while(iter != signals.end() && iter->h < heights[i]){
            answer[iter->idx] = i+1;
            iter++;
        }
        signals.erase(signals.begin(), iter);
        signals.insert(tower_signal{heights[i], i});
    }


    return answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> towers(n, 0);
    for(int i=0; i<n ; ++i){
        cin >> towers[i];
    }
    auto answer = solution(towers);
    for(auto a : answer){
        cout << a << " ";
    }
}
