class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(coins.empty()) {
            return -1;
        }
        
        if(!amount) return 0;
        
        vector<int> dp(amount + 1, -1);
        for(int c : coins) {
            if(c > amount) continue;
            dp[c] = 1;
        }
        
        for(int i=1; i<=amount; ++i) {
            for(int c : coins) {
                if(i - c > 0 && dp[i-c] != -1) {
                    dp[i] = (dp[i] == -1 ? dp[i-c]+1 : min(dp[i], dp[i-c]+1));
                }
            }
        }
        
        return dp[amount];
    }
};

