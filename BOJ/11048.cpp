#include <bits/stdc++.h>
using namespace std;
int maze[1001][1001]{0,}, n, m, dp[1001][1001];

int check_location(int y, int x){
  return x >= 1 && x <= m && y >= 1 && y <= n;
}

int delta[3][2] {1, 0, 0, 1, 1, 1};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m;
  memset(dp, -1, sizeof dp);
  for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j) cin >> maze[i][j];
  dp[1][1] = maze[1][1];
  for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j) for(int k=0; k<3; ++k) {
    int dy = i - delta[k][0], dx = j - delta[k][1];
    if(check_location(dy, dx)){
      dp[i][j] = max(dp[i][j], dp[dy][dx] + maze[i][j]);
    }
  }

  cout << dp[n][m];

  return 0;
}
