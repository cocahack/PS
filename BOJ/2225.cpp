#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll cache[201][201]{0,};
constexpr int MOD = 1'000'000'000;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N, K;
  cin >> N >> K;

  for(int i=0; i<=N; ++i) cache[i][1] = 1;

  for(int i=0; i<=N; ++i){
    for(int j=2; j<=K; ++j){
      for(int k=0; k<=i; ++k){
        cache[i][j] += cache[k][j-1];
        cache[i][j] %= MOD;
      }
    }
  }

  cout << cache[N][K];

  return 0;
}

