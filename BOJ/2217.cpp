#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int N, ropes[100000]{0,};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N;

  for(int i=0; i<N; ++i) cin >> ropes[i];
  sort(ropes, ropes + N, greater<int>());

  int answer = 0;

  for(int i=0; i<N; ++i) {
    answer = max(answer, ropes[i] * (i+1));
  }

  cout << answer;

  return 0;
}
