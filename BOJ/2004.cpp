#include <bits/stdc++.h>
using namespace std;

int get_multiple(int x, int base)
{
  int ret = 0;
  for(long long i=base; x/i >= 1; i*=base) {
    ret += x/i;
  }
  return ret;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  cin >> n >> m;

  int a2 = get_multiple(n, 2),
  a5 = get_multiple(n, 5),
  b2 = get_multiple(m, 2),
  b5 = get_multiple(m, 5),
  c2 = get_multiple(n-m, 2),
  c5 = get_multiple(n-m, 5);

  cout << min(a2 - b2 - c2, a5 - b5 - c5);

  return 0;
}

