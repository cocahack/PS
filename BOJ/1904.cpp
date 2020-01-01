#include <bits/stdc++.h>
using namespace std;

constexpr int MOD = 15'746;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  vector<int> cache(n, 0);
  cache[1] = 1, cache[2] = 2;

  for(int i=3; i<=n; ++i) {
    cache[i] = ( (cache[i-1] % MOD) + (cache[i-2] % MOD) ) % MOD;
  }

  cout << cache[n];

  return 0;
}

