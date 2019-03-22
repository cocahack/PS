#include <bits/stdc++.h>

using namespace std;
constexpr int MAX = 2001;
int card_size;
int dp[MAX][MAX];
int solve(const vector<int>& card_left, const vector<int>& card_right, int left, int right)
{
    if(card_size == left || card_size == right) return 0;
    
    int& ret = dp[left][right];
    if(ret != -1) return ret;
    
    ret = max(solve(card_left, card_right, left+1, right+1), solve(card_left, card_right, left+1, right));
    if(card_left[left] > card_right[right]) 
        ret = max(ret, solve(card_left, card_right, left, right+1)+card_right[right]);
    
    return ret;
}

int solution(vector<int> left, vector<int> right) {
    int answer = 0;
    
    card_size = left.size();
    memset(dp, -1, sizeof dp);
    
    answer = solve(left, right, 0, 0);
    
    return answer;
}
