#include <bits/stdc++.h>
using namespace std;
constexpr int MAX = 1001;
int board[MAX][MAX], dp[MAX][MAX]{0,}, a, b;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> a >> b;
  string s;
  for(int i=1; i<=a; ++i) {
    cin >> s;
    for(int j=1; j<=b; ++j){
      board[i][j] = s[j-1] - '0';
    }
  }

  int max_width = 0;

  for(int i=1; i<=a; ++i){
    for(int j=1; j<=b; ++j) {
      if(board[i][j]) {
        dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
        max_width = max(max_width, dp[i][j]);
      }
    }
  }

  cout << max_width * max_width;

  return 0;
}

