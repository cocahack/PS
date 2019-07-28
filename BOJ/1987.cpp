#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
int R, C;
vector<string> board(20);
bool used[26]{0,};
int delta[4][2] {0, 1, 0, -1, -1, 0, 1, 0};
inline bool check_boundary(int y, int x)
{
  return y >= 0 && y < R && x >= 0 && x < C;
}

int dfs(int y, int x)
{
  int c = board[y][x] - 'A';
  if(!check_boundary(y, x) || used[c]) return 0;

  used[c] = true;

  int ret = 0, dy, dx;

  for(int i=0; i<4; ++i){
    dy = y + delta[i][0], dx = x + delta[i][1];
    ret = max(ret, 1 + dfs(dy, dx));
  }

  used[c] = false;

  return ret;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> R >> C;
  for(int i = 0; i < R; ++i) cin >> board[i];

  cout << dfs(0, 0);

  return 0;
}

