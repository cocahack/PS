#include <bits/stdc++.h>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    
   	int idx = 0;
    while(k && idx < number.size()){
        if(answer.empty() || answer.back() >= number[idx]){
            answer.push_back(number[idx++]);
        } else {
            answer.pop_back();
            k--;
        }
    }
    
    for(; idx < number.size(); ++idx){
        answer += number[idx];
    }
    
    while(k--){
        answer.pop_back();
    }
 
    return answer;
}
