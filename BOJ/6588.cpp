#include <bits/stdc++.h>
using namespace std;
bool primes[1000001]{0,};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  primes[2] = true;

  for(int i=3; i<=1000000; ++i){
    if(i%2 == 0) continue;

    bool is_prime = true;
    for(int j=2; j*j <= i; ++j){
      if(i % j == 0) {
        is_prime = false;
        break;
      }
    }

    if(is_prime) primes[i] = true;
  }

  int n;
  while(1) {
    cin >> n;
    if (!n) break;

    for (int i=2; i<1000001; ++i) {
      if (i >= n) continue;
      if(primes[i] && primes[n-i]){
        int ni = n - i;
        if(i > ni) swap(i, ni);
        cout << n << " = " << i << " + " << ni << "\n";
        break;
      }
    }
  }

  return 0;
}
