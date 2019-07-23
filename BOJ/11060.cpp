#include <bits/stdc++.h>
using namespace std;

constexpr int MAX = 987654321;
int N, arr[1000], cache[1000];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N;
  for(int i=0; i<N; ++i) cin >> arr[i];

  fill(cache, cache+N, MAX);

  cache[N-1] = 0;
  for(int i = N-1; i >= 0; --i) {
    for(int j = i-1; j >= 0; --j){
      if(j + arr[j] >= i) {
        cache[j] = min(cache[j], cache[i] + 1);
      }
    }
  }

  cout << (cache[0] == MAX ? -1 : cache[0]);

  return 0;
}
