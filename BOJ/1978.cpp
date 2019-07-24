#include <bits/stdc++.h>
using namespace std;

bool prime[1001]{0,};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  prime[2] = true;
  for(int i=3; i<1000; i+=2) {
    bool is_prime = true;
    for(int j=3; j*j <= i; ++j){
      if(i % j == 0) {
        is_prime = false;
        break;
      }
    }
    prime[i] = is_prime;
  }

  int N, a, answer = 0;
  cin >> N;

  while(N--) {
    cin >> a;
    answer += prime[a] ? 1 : 0;
  }

  cout << answer;

  return 0;
}
