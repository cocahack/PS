#include <bits/stdc++.h>
using namespace std;

vector<bool> prime(1000001, 0);

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  prime[2] = true;
  for(int i=3; i<1000000; i+=2) {
    bool is_prime = true;
    for(int j=3; j*j <= i; ++j){
      if(i % j == 0) {
        is_prime = false;
        break;
      }
    }
    prime[i] = is_prime;
  }

  int M, N;
  cin >> M >> N;

  for(int i=M; i<=N; ++i){
    if(prime[i]) cout << i << "\n";
  }

  return 0;
}

