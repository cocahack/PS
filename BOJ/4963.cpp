#include <bits/stdc++.h>
using namespace std;
int w, h, board[50][50];
bool visited[50][50];
int delta[8][2]{-1, 0, -1, -1, 0, -1, 1, -1, 1, 0, 1, 1, 0, 1, -1, 1};

inline bool check_boundary(int h, int w, int y, int x)
{
  return y >= 0 && y < h && x >= 0 && x < w;
}

void dfs(int h, int w, int y, int x)
{
  if(visited[y][x]) return;
  visited[y][x] = true;
  for(int i=0; i<8; ++i){
    int ny = y + delta[i][0], nx = x + delta[i][1];
    if(check_boundary(h, w, ny, nx) && board[ny][nx]) {
      dfs(h, w, ny, nx);
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  while(1) {
    cin >> w >> h;
    if(!w && !h) break;
    for(int i=0; i<h; ++i) {
      for(int j=0; j<w; ++j) {
        cin >> board[i][j];
      }
    }
    int answer = 0;
    memset(visited, 0, sizeof visited);
    for(int i=0; i<h; ++i) {
      for(int j=0; j<w; ++j) {
        if(board[i][j] && !visited[i][j]) {
          dfs(h, w, i, j);
          answer++;
        }
      }
    }
    cout << answer << "\n";
  }

  return 0;
}

