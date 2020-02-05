#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll INF = 10e15;

ll v;
vector<ll> c{1, 10, 25};
vector<ll> cache(101, INF);

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  cache[0] = 0;
  for(int i=1; i<=100; ++i) {
    for(auto coin : c) {
      if(i - coin >= 0) cache[i] = min(cache[i], cache[i-coin] + 1);
    }
  }

  while (t--) {
    cin >> v;
    ll answer = 0ll;

    while(v) {
      answer += cache[v % 100];
      v /= 100;
    }
    cout << answer << "\n";
  }

  return 0;
}
