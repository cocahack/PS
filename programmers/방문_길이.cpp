#include <bits/stdc++.h>
using namespace std;

bool visited[11][11][11][11]{0,};
int y = 5, x = 5, answer = 0;
int delta[4][2]{-1, 0, 1, 0, 0, 1, 0, -1};
unordered_map<char, int> ctoidx;

inline bool check_boundary(int y, int x) {
    return y >= 0 && x >= 0 && y < 11 && x < 11;
}

void recursion(const string& dirs, int idx) {
    if(idx == dirs.size()) return;
    
    int dix = ctoidx[dirs[idx]];
    
    int ny = y + delta[dix][0], nx = x + delta[dix][1];
    
    if(!check_boundary(ny, nx)){
        recursion(dirs, idx+1);
        return;
    } 
    
    if(!visited[y][x][ny][nx]) {
        answer++;
    	visited[y][x][ny][nx] = true;
    	visited[ny][nx][y][x] = true;
    }
  	
    y = ny, x = nx;
    recursion(dirs, idx+1);
}

int solution(string dirs) {
    ctoidx.insert(make_pair('U',0));
    ctoidx.insert(make_pair('D',1));
    ctoidx.insert(make_pair('R',2));
    ctoidx.insert(make_pair('L',3));
    
    recursion(dirs, 0);
    
	return answer;
}

