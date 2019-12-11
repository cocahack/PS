#include<bits/stdc++.h>
using namespace std;

constexpr int MAXVAL = 15;
int dp[MAXVAL+1]{0,};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  vector<int> t(n, 0);
  vector<int> p(n, 0);

  for(int i=0; i<n; ++i) cin >> t[i] >> p[i];

  int answer = 0;
  for(int i=0; i<n; ++i) {
    if(i + t[i] > n) continue;
    int max_before = 0;
    for(int j=0; j<i; ++j) {
      if(j + t[j] > i) continue;
      max_before = max(max_before, dp[j]);
    }
    dp[i] = p[i] + max_before;
    answer = max(answer, dp[i]);
  }

  cout << answer;

  return 0;
}
