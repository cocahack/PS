#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str, bomb;
    cin >> str >> bomb;

    deque<char> s;
    stack<int> idx_cache;
    int idx = 0;

    int i = 0;
    while(i < str.size()) {
        char c = str[i];
        if(bomb[idx] == c) {
            idx++;
        } else if(idx != 0) {
            idx = 0;
            continue;
        }
        s.push_back(c);
        idx_cache.push(idx);
        i++;
        if(idx == bomb.size()) {
            while(idx--) {
                s.pop_back();
                idx_cache.pop();
            }
            idx = idx_cache.empty() ? 0 : idx_cache.top();
        }
    }

    if(s.empty()) {
        cout << "FRULA";
        return 0;
    }

    string answer(s.size(), 0);
    for(i=0; i<answer.size(); ++i) {
        answer[i] = s.front();
        s.pop_front();
    }

    cout << answer;

    return 0;
}

