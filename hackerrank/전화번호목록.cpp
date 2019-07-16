#include <bits/stdc++.h>
using namespace std;
unordered_set<string> dic;

bool solution(vector<string> phone_book) {
    for(auto p : phone_book){
        dic.insert(p);
    }
    
    for(auto p : phone_book){
        string t = "";
        for(int i=0; i<p.size()-1; ++i){
            t += p[i];
            if(dic.find(t) != dic.end()) return false;
        }
    }
    
    return true;
}
