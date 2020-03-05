#include <bits/stdc++.h>
using namespace std;

int n, m, board[300][300]{0,};
bool visited[300][300]{0,};
int delta[4][2]{-1,0,0,1,1,0,0,-1};

inline bool check_boundary(int y, int x) {
  return y >= 0 && x >= 0 && y < n && x < m;
}

void dfs(int y, int x) {
  visited[y][x] = true;
  for(int i=0; i<4; ++i) {
    int ny = y + delta[i][0], nx = x + delta[i][1];
    if(check_boundary(ny, nx) && board[ny][nx] > 0 && !visited[ny][nx]) {
      dfs(ny, nx);
    }
  }
}

bool is_separated() {
  memset(visited, 0, sizeof visited);
  bool checked = false;
  for(int i=0; i<n; ++i) {
    for(int j=0; j<m; ++j) {
      if(board[i][j] > 0) {
        dfs(i, j);
        checked = true;
        break;
      }
    }

    if(checked) break;
  }

  for(int i=0; i<n; ++i) {
    for(int j=0; j<m; ++j) {
      if(board[i][j] < 0) {
        board[i][j] = 0;
      }
      if(board[i][j] > 0 && !visited[i][j]) {
        return true;
      }
    }
  }

  return false;
}



void melt(int y, int x, int count) {
  int melt_count = 0;
  for(int i=0; i<4; ++i) {
    int ay = y + delta[i][0], ax = x + delta[i][1];
    if(check_boundary(ay, ax) ){
      if(board[ay][ax] == 0 || (board[ay][ax] < 0 && board[ay][ax] != count)) {
        melt_count++;
      }
    }
  }

  board[y][x] -= melt_count;
  if(board[y][x] <= 0) {
    board[y][x] = count;
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;

  for(int i=0; i<n; ++i) for(int j=0; j<m; ++j) cin >> board[i][j];
  int answer = 0;

  while(true) {
    answer++;
    bool no_tips = true;

    for(int i=0; i<n; ++i) {
      for(int j=0; j<m; ++j) {
        if(board[i][j]){
          melt(i, j, answer * -1);
          no_tips = false;
        }
      }
    }

    if(no_tips) break;

    if(is_separated()) {
      cout << answer;
      return 0;
    }
  }

  cout << 0;
  return 0;
}

