#include <bits/stdc++.h>
#define for1d(size) for(int i=0; i<size; ++i)
using namespace std;

int allquot[51]{0,};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  for1d(n) cin >> allquot[i];

  sort(allquot, allquot + n);

  cout << allquot[0] * allquot[n-1];

  return 0;
}

