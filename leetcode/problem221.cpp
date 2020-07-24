class Solution {
public:
int maximalSquare(vector<vector<char>> matrix) {
    int N = matrix.size();

    if(N == 0) {
        return 0;
    }

    int M = matrix[0].size();

    vector<vector<int>> dp(N, vector(M, 0));

    int answer = 1;
    bool is_zero = true;

    for (int i=0; i<N; ++i) {
        for(int j=0; j<M; ++j) {
            if(matrix[i][j] == '1') {
                is_zero = false;
                dp[i][j] = 1;

                if(i-1 >= 0 && j-1 >= 0) {
                    int min_len = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1]));
                    if(min_len) {
                        dp[i][j] = min_len + 1;
                        answer = max(answer, min_len + 1);
                    }
                }
            }
        }
    }
    return is_zero ? 0 : answer * answer;
}
};

