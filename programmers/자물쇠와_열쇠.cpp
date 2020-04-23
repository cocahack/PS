#include <string>
#include <vector>

using namespace std;

int extended_lock[60][60]{0,};
int M, N, hole = 0;
bool visited[60][60][4]{0,};
int delta[4][2]{-1, 0, 0, 1, 1, 0, 0, -1};

inline bool between_lock(int pos) {
    return N <= pos && pos < 2*N;
}

bool check_correct(int y, int x, vector<vector<int>>& key) {
    bool ret = true, b = false;
    int checked_hole = 0;
    
    for(int i=0; i<M; ++i) {
        for(int j=0; j<M; ++j) {
            if(!between_lock(y+i) || !between_lock(x+j)) continue;
            else {
                if(!extended_lock[y+i][x+j] && key[i][j]) {
                    checked_hole++;
                }
                if(extended_lock[y+i][x+j] && key[i][j]) b = true;
            }
            if(b) break;
        }
        if(b) break;
    }
    
    return !b && checked_hole == hole; 
}

vector<vector<int>> rotate(vector<vector<int>> key) {
    vector<vector<int>> ret(M, vector<int>(M, 0));
    
    for(int i=0; i<M; ++i) {
        for(int j=0; j<M; ++j) {
            ret[i][j] = key[M-j-1][i];
        }
    }
    
    return ret;
}

inline bool check_boundary(int y, int x) {
    return !(y + M - 1 < N || x + M - 1 < N || y >= 2*N || x >= 2*N);
}

bool dfs(int y, int x, int r, vector<vector<int>>& key) {
    if(!check_boundary(y, x)) return false;
    if(visited[y][x][r]) return false;
    visited[y][x][r] = true;
    
    bool ret = check_correct(y, x, key);
    
    if(!ret) {
    	for(int i=0; i<4; ++i) {
            ret |= dfs(y + delta[i][0], x + delta[i][1], r, key);
            if(ret) break;
        }
    }
    
    if(!ret) {
        vector<vector<int>> new_key = key;
    	for(int i=0; i<4; ++i) {
            new_key = rotate(new_key);
            ret |= dfs(y, x, (r+1) % 4, new_key);
            if(ret) break;
        }
    }
    
    return ret;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
	M = key.size(), N = lock.size();
    
    for(int i=0; i<N; ++i) for(int j=0; j<N; ++j) {
        extended_lock[i+N][j+N] = lock[i][j];
        if(!lock[i][j]) hole++;
    }
    
    return dfs(N, N, 0, key);
}

