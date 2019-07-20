#include <bits/stdc++.h>
using namespace std;

int cache[100001]{0,};
constexpr int INF = numeric_limits<int>::max();

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N;
  cin >> N;

  for(int i=1; i<=N; ++i){
    int& cur = cache[i] = INF;
    for(int j=1; j*j<=i; ++j){
      cur = min(cur, cache[i-j*j]+1);
    }
  }

  cout << cache[N];

  return 0;
}
