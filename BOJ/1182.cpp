#include <bits/stdc++.h>
#define for1d(size, exp) for(int i=0; i<size; ++i) exp;
using namespace std;
int n, s, arr[20], answer = 0;

void dfs(int idx, bool last_included, int acc) {
  if(last_included && acc == s) ++answer;
  if(idx >= n) return;

  dfs(idx+1, true, acc+arr[idx]);
  dfs(idx+1, false, acc);
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> s;
  for1d(n, cin >> arr[i]);

  dfs(0, false, 0);

  cout << answer;

  return 0;
}

