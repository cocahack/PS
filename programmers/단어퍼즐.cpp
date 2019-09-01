#include <bits/stdc++.h>
using namespace std;
int dp[20001]{0,};
constexpr int INF = 200000;

int solve(const string& t, const int len, const vector<string>& strs, int begin)
{
    if(begin == len) return 0;
    if(begin > len) return INF;
    
    int& ret = dp[begin];
    if(ret != -1) return ret;
    
    ret = INF;
    
    for(auto s : strs) {
        if(len - begin < s.size()) continue;
        bool is_passed = true;
        for(int i=0; i<s.size(); ++i) {
            if(t[begin+i] != s[i]) {
                is_passed = false;
                break;
            }
        }
        if(is_passed) ret = min(ret, solve(t, len, strs, begin + s.size()) + 1);
    }
    return ret;
}

int solution(vector<string> strs, string t)
{
    int answer = 0;
    
    memset(dp, -1, sizeof dp);
    
    answer = solve(t, t.size(), strs, 0);
    return answer == INF ? -1 : answer;
}

