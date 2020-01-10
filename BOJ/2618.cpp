#include <bits/stdc++.h>
using namespace std;

int n, w;
int dp[1001][1001]{0,}, dispatch[1001][1001]{0,};
pair<int,int> events[1003];

inline int calculate_dist(int from, int to)
{
  return abs(events[from].first - events[to].first) + abs(events[from].second - events[to].second);
}

int solve(int p1, int p2)
{
  int here = max(p1, p2) + 1;
  if(here == w + 2) return 0;

  int& ret = dp[p1][p2];
  if(ret != -1) return ret;

  int dispatch_p1 = solve(here, p2) + calculate_dist(p1, here);
  int dispatch_p2 = solve(p1, here) + calculate_dist(p2, here);

  dispatch[p1][p2] = (dispatch_p1 < dispatch_p2 ? 1 : 2);

  return ret = min(dispatch_p1, dispatch_p2);
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> w;

  memset(dp, -1, sizeof dp);

  events[0] = {1,1};
  events[1] = {n, n};
  for(int i=2; i<w+2; ++i) {
    cin >> events[i].first >> events[i].second;
  }

  cout << solve(0, 1) << "\n";

  for(int p1 = 0, p2 = 1; max(p1, p2) + 1 < w + 2; ) {
    cout << dispatch[p1][p2] << "\n";
    if(dispatch[p1][p2] == 1) {
      p1 = max(p1, p2) + 1;
    } else {
      p2 = max(p1, p2) + 1;
    }
  }

  return 0;
}
