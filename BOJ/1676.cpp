#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, two = 0, five = 0;
  cin >> n;
  for(int i=1; i<=n; ++i){
    int k = i;
    while(1) {
      if(k % 2 == 0){
        two++;
        k/=2;
        continue;
      } else if(k % 5 == 0){
        five++;
        k/=5;
        continue;
      }
      break;
    }
  }

  cout << min(two, five);

  return 0;
}

