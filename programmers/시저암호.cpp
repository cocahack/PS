#include <bits/stdc++.h>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    for(char c : s){
        if(c >= 'a' && c <= 'z'){
            int new_c = c + n;
            if(new_c > 'z') new_c -= 26;
            answer += (char)new_c;
        } else if(c >= 'A' && c <= 'Z'){
            char new_c = c + n;
            
            if(new_c > 'Z') new_c -= 26;
            answer += (char)new_c;
        } else {
            answer += c;
        }
    }
    return answer;
}
