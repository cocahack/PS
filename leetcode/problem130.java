class Solution {
    private int N;
    private int M;
    boolean[][] visited;

    private static final int DELTA[][] = {
        {-1, 0},
        {0, 1},
        {1, 0},
        {0, -1}
    };

    public void solve(char[][] board) {
        
        N = board.length;

        if(N == 0) return;
        
        M = board[0].length;
        if(M == 0) return;
        
        visited = new boolean[N][];

        for(int i=0; i<N; ++i) {
            visited[i] = new boolean[M];
            for(int j=0; j<M; ++j) {
                visited[i][j] = false;
            }
        }

        for(int i=0; i<N; ++i) {
            for(int j=0; j<M; ++j) {
                if (board[i][j] == 'X') {
                    visited[i][j] = true;
                }
                else if (board[i][j] == 'O' && !visited[i][j]) {
                    boolean result = checkSurrounded(board, i, j);
                    if (result) {
                        flipToStay(board, i, j);
                    }
                }
            }
        }


        for(int i=0; i<N; ++i) {
            for(int j=0; j<M; ++j) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
                else if (board[i][j] == 'A') {
                    board[i][j] = 'O';
                }
            }
        }

    }

    private void flipToStay(char[][] board, int y, int x) {
        board[y][x] = 'A';
        for (int i=0; i<4; ++i) {
            int dy = y + DELTA[i][0];
            int dx = x + DELTA[i][1];

            if (checkBoundary(dy, dx) && board[dy][dx] == 'O') {
                flipToStay(board, dy, dx);
            }
        }
    }

    private boolean checkSurrounded(char[][] board, int y, int x) {
        visited[y][x] = true;

        for (int i=0; i<4; ++i) {
            int dy = y + DELTA[i][0];
            int dx = x + DELTA[i][1];

            if(!checkBoundary(dy, dx)) {
                return true;
            }

            if (checkBoundary(dy, dx) && !visited[dy][dx] && board[dy][dx] == 'O') {
                boolean result = checkSurrounded(board, dy, dx);
                if(result) {
                    return true;
                }
            }
        }

        return false;
    }

    private boolean checkBoundary(int y, int x) {
        return y >= 0 && y < N && x >= 0 && x < M;
    }

}

