#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size(), 0);
    stack<int> s;
    int i;
    for(i=0; i<prices.size(); ++i){
        while(s.size()) {
            int stack_top = s.size() ? s.top() : -1;
            if (prices[stack_top] > prices[i]) {
                s.pop();
                answer[stack_top] = i - stack_top;
            } else {
                break;
            }
        }
        s.push(i);
    }

    while(s.size()){
        int idx = s.top();
        s.pop();
        answer[idx] = i - idx - 1;
    }

    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    auto a = solution({1,2,3,2,3});

    for(auto i : a){
        cout << i << " ";
    }

    return 0;

}
