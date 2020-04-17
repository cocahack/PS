#include<bits/stdc++.h>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    
    stack<char> ss;
    
    for(auto c : s) {
        if(c == '(') {
            ss.push(c);
        } else {
            if(ss.empty()) {
                answer = false;
                break;
            }
            ss.pop();
        }
    }

    if(ss.size()) {
        answer = false;
    }

    return answer;
}

