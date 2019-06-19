#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, m;
vector<ll> mm(10000, 0);

bool is_possible(ll value)
{
  ll num = m;

  for(int i=0; i<m; ++i){
    num += value / mm[i];
  }

  return num < n;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;
  for(int i=0; i<m; ++i) cin >> mm[i];

  if(n <= m) {
    cout << n;
    return 0;
  }

  ll lo = 0, hi = *(max_element(mm.begin(), mm.end())) * n, mid;

  while(lo + 1 < hi){
      mid = (lo + hi) / 2;
      if(is_possible(mid)) lo = mid;
      else hi = mid;
  }

  ll k = lo;

  for(int i=0; i<m; ++i) n -= k / mm[i];
  n -= m;

  int answer = 0;

  while(answer < m){
    if((k + 1) % mm[answer] == 0) --n;
    if(n == 0) break;
    ++answer;
  }

  cout << answer + 1;

  return 0;
}
