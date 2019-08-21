#include <bits/stdc++.h>
using namespace std;
inline void convert_lower(string& s)
{
    for(char& c : s) {
        if(c >= 'A' && c <= 'Z') {
            c += 32;
        }
    }
}
int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    list<string> q;
    set<string> s;
    
    if(cacheSize == 0) {
        return cities.size() * 5;
    }

    for(auto city : cities) {
        convert_lower(city);
        if(q.empty()) {
            q.push_front(city);
            answer += 5;
        } else if (s.find(city) != s.end()) {
            q.remove(city);
            q.push_front(city);
            answer += 1;
        } else {
            if(s.size() == cacheSize) {
                string back_s = q.back();
                s.erase(back_s);
                q.pop_back();
            }
            q.push_front(city);
            answer += 5;
        }
        s.insert(city);
    }

    return answer;
}

