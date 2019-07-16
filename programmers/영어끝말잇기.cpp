#include <bits/stdc++.h>
using namespace std;
unordered_set<string> dic;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    string last_string = words[0];
    dic.insert(last_string);
    for (int idx = 1; idx < words.size(); ++idx){
        auto current_string = words[idx];
        if(dic.find(current_string) != dic.end() ||
           last_string.back() != current_string.front()){
            answer = {idx % n + 1, idx / n + 1};
            break;
        }
        dic.insert(current_string);
        last_string = current_string;
    }
    
    if(answer.size()) return answer;
    else return {0, 0};
}
