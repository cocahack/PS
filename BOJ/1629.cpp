#include <bits/stdc++.h>
using namespace std;
using ll = long long;
unordered_map<ll, ll> cache;
ll a, b, c;

ll dp(ll bb){
  if(bb == 1) return a % c;
  if(cache.find(bb) != cache.end()) return cache[bb] % c;

  ll ret = (dp(bb/2) * dp(bb - (bb / 2))) % c;
  cache[bb] = ret;

  return ret;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> a >> b >> c;

  cout << dp(b);

  return 0;
}
