struct Event {
    int p, h, idx;
    bool is_end;
    Event(int _p, int _h, int _idx, bool _e): p(_p), h(_h), idx(_idx), is_end(_e){}
    Event() {}
    bool operator < (const Event& rhs) const {
        if (p != rhs.p) return p < rhs.p;
        if (is_end != rhs.is_end) return is_end < rhs.is_end;
        if (is_end == rhs.is_end && is_end == false) {
            return h > rhs.h;
        }
        if (is_end == rhs.is_end && is_end == true) {
            return h < rhs.h;
        }
        return idx < rhs.idx;
    }
};

struct Building {
    int h, idx;
    Building(int _h, int _idx): h(_h), idx(_idx){}
    bool operator < (const Building& rhs) const {
        if (h != rhs.h) return h < rhs.h;
        return idx < rhs.idx;
    }
};

class Solution {
    set<Building> b;
    vector<Event> e;
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        for(int i = 0; i < buildings.size(); ++i) {
            auto& building = buildings[i];
            e.push_back(Event(building[0], building[2], i, false));
            e.push_back(Event(building[1], building[2], i, true));
        }
        
        sort(e.begin(), e.end());
        
        vector<vector<int>> answer;
    
        for(int i = 0; i < e.size(); ++i) {
            auto& event = e[i];
            if(event.is_end) {
                int last_height = b.rbegin()->h;
                b.erase(Building(event.h, event.idx));
                
                if(b.empty()) {
                    answer.push_back({event.p, 0});
                }
                else if(b.rbegin()->h < last_height) {
                    answer.push_back({event.p, b.rbegin()->h});
                }
            } else {
                if (b.empty() || b.rbegin()->h < event.h) {
                    answer.push_back({event.p, event.h});
                } 
                b.insert(Building(event.h, event.idx));
            }
        }
        
        return answer;
    }
};

