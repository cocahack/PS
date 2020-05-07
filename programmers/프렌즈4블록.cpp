#include <bits/stdc++.h>

using namespace std;

bool check(int y, int x, vector<string>& board) {
    return board[y][x] != '#'
        && board[y][x] == board[y][x+1] 
        && board[y][x] == board[y+1][x] 
        && board[y][x] == board[y+1][x+1];
}

int remove_blocks(int m, int n, vector<string>& board) {
    vector<pair<int, int>> p;
    int ret = 0;
    
    for(int y=0; y<m-1; ++y) {
        for(int x=0; x<n-1; ++x) {
            if(check(y, x, board)) {
                p.emplace_back(y, x);
                p.emplace_back(y, x+1);
                p.emplace_back(y+1, x);
                p.emplace_back(y+1, x+1);
            }
        }
    }
    
    for(auto& point : p) {
        if(board[point.first][point.second] != '#') {
            board[point.first][point.second] = '#';
            ret++;
        }
    }
    return ret;
}

void push_blocks(int m, int n, vector<string>& board) {
    for(int x=0; x<n; ++x) {
        for(int y=m-1; y>=0; --y) {
            if(board[y][x] == '#') {
                int i = y;
                while(i >= 0) {
                    if(board[i][x] != '#') break;
                    --i;
                }
                int diff = y - i;
                for(int j=i; j>=0; --j) {
                    board[j+diff][x] = board[j][x];
                    board[j][x] = '#';
                }
            }
        }
    }
}


int solution(int m, int n, vector<string> board) {
    int answer = 0;
    
    while(1) {
        int removed_blocks = remove_blocks(m, n, board);
        if(!removed_blocks) break;
        answer += removed_blocks;
        push_blocks(m, n, board);
    }
    
    return answer;
}

