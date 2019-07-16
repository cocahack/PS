#include <bits/stdc++.h>
using namespace std;

int solution(string arrangement) {
    int answer = 0;
    stack<char> s;
    for(int i=0; i < arrangement.size(); ++i) {
        char p = arrangement[i];
        if(p == '('){
            if(arrangement[i+1] == ')') {
                answer += s.size();
                i++;
            } else {
                s.push(p);
            }
        } else {
            answer++;
            s.pop();
        }
    }

    return answer;
}
