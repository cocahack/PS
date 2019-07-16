#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N, M;
  cin >> N >> M;

  if(N == 1){
    cout << 1;
  } else if (N == 2) {
    cout << (M >= 7 ? 4 : (M / 2) + (M % 2));
  } else {
    if(M < 4) cout << M;
    else if(M < 7) cout << 4;
    else cout << M - 2;
  }

  return 0;
}
