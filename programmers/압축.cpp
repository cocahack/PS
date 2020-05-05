#include <bits/stdc++.h>

using namespace std;

struct Dict {
    int num = 1;
    unordered_map<string, int> _d;
    Dict(){}

    void insert(const string& s) {
        _d.insert({s, num++});
    }

    int find(const string& s) {
        return _d.find(s) != _d.end() ? _d[s] : -1;
    }
};

vector<int> solution(string msg) {
    vector<int> answer;

    Dict d = Dict();
    string t = "A";

    for(int i=0; i<26; ++i) {
        t[0] = 'A' + (char)i;
        d.insert(t);
    }

    int idx = 0;
    while(idx < msg.size()) {
        string k = "";
        int last_val = -1, j = 0;
        for(j = 0; idx + j < msg.size(); ++j) {
            k += msg[idx + j];
            if(d.find(k) == -1) break;
            last_val = d.find(k);
        }
        d.insert(k);
        answer.push_back(last_val);
        idx += j;
    }

    return answer;
}

