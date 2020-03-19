#include <bits/stdc++.h>
using namespace std;

int n, board[500][500], cache[500][500], answer = -1;
int delta[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};

inline bool check_boundary(int y, int x, int y_max, int x_max) {
  return y >= 0 && y < y_max && x >= 0 && x < x_max;
}

int dp(int y, int x) {
  if(!check_boundary(y, x, n, n)) {
    return 0;
  }

  int& ret = cache[y][x];
  if(ret != -1) return ret;

  ret = 1;
  for(auto & i : delta) {
    int ny = y + i[0], nx = x + i[1];
    if(!check_boundary(ny, nx, n, n) || board[ny][nx] <= board[y][x]) continue;
    ret = max(ret, dp(ny, nx) + 1);
  }
  return ret;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) cin >> board[i][j];
  memset(cache, -1, sizeof cache);

  for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
    if (cache[i][j] == -1) {
      answer = max(answer, dp(i, j));
    }
  }

  cout << answer;
  return 0;
}

