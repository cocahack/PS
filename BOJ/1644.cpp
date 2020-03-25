#include <bits/stdc++.h>
using namespace std;

constexpr int ULIMIT = 4 * 10e6;
int N;
vector<int> primes;
vector<bool> is_prime(ULIMIT, true);

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N;

  for(int i = 2; i*i<=N; ++i) {
    int j = 2;
    while(i*j <= N) {
      is_prime[i*j] = false;
      ++j;
    }
  }

  for (int i = 2; i <= N; ++i) {
    if(is_prime[i]) primes.push_back(i);
  }

  int lo = 0, hi = 0, acc = 0, answer = 0;

  while(hi < primes.size()) {
    if(acc <= N) {
      if(acc == N) answer++;
      acc += primes[hi++];
    } else {
      acc -= primes[lo++];
    }
  }

  while(lo < hi) {
    if(acc == N) {
      answer++;
      break;
    }
    acc -= primes[lo++];
  }

  cout << answer;

  return 0;
}

