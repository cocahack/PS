#include <bits/stdc++.h>
using namespace std;

bool check_valid(string& s)
{
    stack<char> ss;
    for(int i=0; i<s.size(); ++i) {
        if(s[i] == ')') {
            if(ss.empty()) return false;
            ss.pop();
        } else {
            ss.push(s[i]);
        }
    }
    
    return ss.empty();
}

string recur(string s)
{
    if(s.empty()) return s;
    
    int x = 0, left = 0, right = 0;
    for(;x < s.size(); ++x) {
        if(s[x] == '(') left++;
        else right++;
        
        if(left == right) break;
    }
    string u = string(s.begin(), s.begin()+x+1);
    string v = string(s.begin()+x+1, s.end());
    
    if(check_valid(u)) return u + recur(v);
    
    string new_str = "(" + recur(v) + ")";
    for(int i=1; i<u.size()-1; ++i) {
        if(u[i] == '(') new_str += ')';
        else new_str += '(';
    }
    return new_str;
}

string solution(string p) {
    return recur(p);
}

