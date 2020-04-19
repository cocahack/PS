#include <bits/stdc++.h>

using namespace std;

int solution(int n, vector<string> data) {
    string friends = "ACFJMNRT";
    unordered_map<char, int> ctoidx;

	vector<pair<int, int>> ct;
	vector<pair<char, int>> cond;
    
    for(int i=0; i<friends.size(); i++) ctoidx[friends[i]] = i;
    for(auto d: data) {
        int t1 = ctoidx[d[0]], t2 = ctoidx[d[2]],  v = d[4]-'0'+1;
        char condition = d[3];
        ct.emplace_back(t1, t2);
        cond.emplace_back(condition, v);
    }
    


    int answer = 0;

    vector<int> a(8); 
    for(int i=0; i<8; i++) a[i] = i;
    
    do {
        bool is_answer = true;

        for(int i=0; i<cond.size(); ++i) {
            int distance = abs(a[ct[i].first] - a[ct[i].second]), v = cond[i].second;
            char c = cond[i].first;

            if(c == '=') {
                is_answer = distance == v;
            } else if (c == '<') {
                is_answer = distance < v;
            } else {
                is_answer = distance > v;
            }

            if(!is_answer) break;
        }

        if(is_answer) answer++;
    } while (next_permutation(a.begin(), a.end()));

    return answer;
}

