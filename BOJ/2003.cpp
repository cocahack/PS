#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m, arr[10000], acc = 0, left = 0, cnt = 0;
  cin >> n >> m;
  for(int i=0; i<n; ++i) cin >> arr[i];

  for(int right=0; right<n;) {
    int loc = acc + arr[right];
    if(loc > m) {
      acc -= arr[left];
      ++left;
    }
    else {
      acc = loc;
      ++right;
      if(acc == m) ++cnt;
    }
  }

  cout << cnt;
  return 0;
}
