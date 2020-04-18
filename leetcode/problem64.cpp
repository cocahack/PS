class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> memo(m+1, vector<int>(n+1, -1));
        
        for(int i=0; i<m; ++i) {
            for(int j=0; j<n; ++j) {
                int left = memo[i+1][j];
                int up = memo[i][j+1];
                
                if(left == -1 && up == -1) {
                    memo[i+1][j+1] = 0;
                } else if(left == -1 || up == -1) {
                    memo[i+1][j+1] = max(left, up);
                } else {
                    memo[i+1][j+1] = min(left, up);
                }
                memo[i+1][j+1] += grid[i][j];
            }
        }
        
        return memo[m][n];
    }
};

