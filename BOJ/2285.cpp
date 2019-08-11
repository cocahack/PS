#include <bits/stdc++.h>
using namespace std;
using ll = long long;
pair<int, int> info[100000];
int n;
ll total = 0ll;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  for(int i=0; i<n; ++i) {
    cin >> info[i].first >> info[i].second;
    total += info[i].second;
  }
  sort(info, info+n);

  ll acc = 0LL;
  for(int i=0; i<n; ++i) {
    acc += info[i].second;
    if(acc >= (total + 1) / 2) {
      cout << info[i].first;
      break;
    }
  }

  return 0;
}

