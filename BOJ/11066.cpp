#include <bits/stdc++.h>
using namespace std;

int n, dp[501][501], arr[501], acc[501]{0,};

int sub_sum(int x, int y)
{
  return acc[y] - acc[x-1];
}

int solve(int x, int y) {
  if(x > n || y > n) return 0;
  if(x == y) return 0;

  int& ret = dp[x][y];
  if(ret != -1) return ret;

  ret = solve(x, x) + solve(x+1, y) + sub_sum(x, y);

  for(int i=x+1; i<y; ++i) {
    ret = min(ret, solve(x, i) + solve(i + 1 , y) + sub_sum(x, y));
  }

  return ret;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  while(t--){
    memset(dp, -1, sizeof dp);
    cin >> n;
    for(int i=1; i<=n; ++i) { cin >> arr[i]; acc[i] = acc[i-1] + arr[i]; }
    cout << solve(1, n) << "\n";
  }


  return 0;
}

