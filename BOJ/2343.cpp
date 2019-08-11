#include <bits/stdc++.h>
#define for1d(size, exp) for(int i=0; i<size; ++i) exp;
using namespace std;
int n, m, lessons[100001];

bool check_possible(int length)
{
  int d = m, temp = 0, i = 0;
  while(i < n) {
    if(temp == 0 && lessons[i] > length) return false;
    if(lessons[i] + temp <= length) {
      temp += lessons[i];
      ++i;
    } else {
      d--;
      temp = 0;
    }
    if(d <= 0 && i < n) return false;
  }

  return (d-1) >= 0;
}


int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;
  for1d(n, cin >> lessons[i]);

  int lo = 0, hi = 1000000001, mid;

  while(lo + 1 < hi) {
    mid = (lo + hi) / 2;
    if(check_possible(mid)) {
      hi = mid;
    } else {
      lo = mid;
    }
  }

  cout << (check_possible(lo) ? lo : hi);

  return 0;
}

