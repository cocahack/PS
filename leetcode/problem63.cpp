class Solution {
    int delta[2][2]{0,1,1,0};
    vector<vector<int>> memo;
public:
    bool check_boundary(vector<vector<int>>& obstacleGrid, int y, int x) {
        return y >= 0 && x >= 0 && y < obstacleGrid.size() && x < obstacleGrid[0].size();
    }
    
    int dp(vector<vector<int>>& obstacleGrid, int y, int x) {
        if(obstacleGrid[0][0]) return 0;
        if(y == obstacleGrid.size() - 1 && x == obstacleGrid[0].size() -1) return 1;
        int& ret = memo[y][x];
        if(ret != -1) return ret;
        
        ret = 0;
        for(int i=0; i<2; ++i) {
            int next_y = y + delta[i][0], next_x = x + delta[i][1];
            if(check_boundary(obstacleGrid, next_y, next_x) && obstacleGrid[next_y][next_x] != 1) {
                ret += dp(obstacleGrid, next_y, next_x);
            } 
        }
        
        return ret;
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.size() == 0) return 0;
        
        memo = vector<vector<int>>(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), -1));
        
        return dp(obstacleGrid, 0, 0);
    }
};
