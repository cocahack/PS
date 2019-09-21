#include <bits/stdc++.h>
using namespace std;
int dp[101][21][2];
string scroll, devil, angel;

int solve(int k, int w, int b) {
  if(k > devil.size()) return 0;
  if(w == scroll.size()) return 1;

  int& ret = dp[k][w][b];
  if(ret != -1) return ret;
  ret = 0;

  for(int i=k+1; i <= devil.size(); ++i ){
    if((b ? angel[i-1] : devil[i-1] ) == scroll[w]) ret += solve(i, w+1, b ^ 1);
  }

  return ret;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> scroll >> devil >> angel;
  memset(dp, -1, sizeof dp);

  int answer = solve(0, 0, 0) + solve(0, 0, 1);

  cout << answer;
  return 0;
}

