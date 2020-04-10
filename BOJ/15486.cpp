#include <bits/stdc++.h>
using namespace std;

constexpr int ULIMIT = 1e6 + (5 * 1e5);

int memo[ULIMIT+1]{0,}, t[ULIMIT+1], p[ULIMIT+1];
int N, answer = 0;

int dp(int day) {
  if(day > N) return 0;

  int& ret = memo[day];
  if(ret != -1) return ret;
  ret = 0;

  if(day + t[day] - 1 <= N) {
    ret = max(ret, dp(day + t[day]) + p[day]);
  }
  ret = max(ret, dp(day + 1));

  return ret;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N;
  for(int i=1; i<=N; ++i) cin >> t[i] >> p[i];
  memset(memo, -1, sizeof memo);

  cout << dp(1);

  return 0;
}

