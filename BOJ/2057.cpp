#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long ;
ull f[21], n;
bool success = false;
void dfs(int i, ull rest)
{
  if(i >= 20) return;
  if(success) return;

  if(rest == f[i]) {
    cout << "YES";
    success = true;
    return;
  }
  if(rest < f[i]) return;

  dfs(i+1, rest);
  if(success) return;

  dfs(i+1, rest - f[i]);
  if(success) return;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  f[0] = 1ULL;
  for(ull i=1; i<=19; ++i) {
    f[i] = f[i-1] * i;
  }

  dfs(0, n);

  if(!success) cout << "NO";

  return 0;
}

