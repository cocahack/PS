class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool checked[10]{0,};
        
        for(int i=0; i<9; ++i) {
            memset(checked, 0, sizeof checked);
            for(int j=0; j<9; ++j) {
                if(board[i][j] == '.') continue;
                int v = board[i][j] - '0';
                if(checked[v]) return false;
                checked[v] = true;
            }
        }
        
        for(int i=0; i<9; ++i) {
            memset(checked, 0, sizeof checked);
            for(int j=0; j<9; ++j) {
                if(board[j][i] == '.') continue;
                int v = board[j][i] - '0';
                if(checked[v]) return false;
                checked[v] = true;
            }
        }
        
        for(int i=0; i<9; ++i) {
            memset(checked, 0, sizeof checked);
            int start_y = 3 * (i / 3), start_x = 3 * (i % 3);
            for(int j=0; j<9; ++j) {
                int y = start_y + j / 3, x = start_x + j % 3;
                if(board[y][x] == '.') continue;
                int v = board[y][x] - '0';
                if(checked[v]) return false;
                checked[v] = true;
            }
        }
        
        return true;
    }
};

