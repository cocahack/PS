#include <bits/stdc++.h>
using namespace std;

unordered_set<int> s;

struct Event{
    int loc, idx;
    bool end;
    Event(int loc_, int idx_, bool end_):loc(loc_), idx(idx_), end(end_){}
    bool operator < (const Event& e) const {
        if(loc != e.loc) return loc < e.loc;
        if(idx != e.idx) return idx < e.idx;
        return end < e.end;
    }
};

int solution(vector<vector<int>> routes) {
    int answer = 0;
    vector<Event> v;
    for(int i=0; i<routes.size(); ++i){
        v.push_back(Event(routes[i][0], i, false));
        v.push_back(Event(routes[i][1], i, true));
    }
    sort(v.begin(), v.end());

    for(auto e : v){
        if(!e.end) s.insert(e.idx);
        else {
            if(s.find(e.idx) != s.end()){
                answer++;
                s.clear();
            }
        }
    }

    return answer;
}

