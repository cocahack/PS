#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  long long sn2 = 0, sn1 =0, sn0 = 1;

  if(n == 0) {
    cout << 0;
  } else if(n == 1) {
    cout << 1;
  } else {
    for(int i=2; i<=n; ++i){
      sn2 = sn1, sn1 = sn0;
      sn0 = sn2 + sn1;
    }
    cout << sn0;
  }

  return 0;
}

