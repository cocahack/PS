#include <bits/stdc++.h>
using namespace std;

constexpr int ULIMIT = 10e3, MAX_VAL = 10e6 + 1;
int N, val[ULIMIT][3], cache[ULIMIT][3]{0,};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; ++i) cin >> val[i][0] >> val[i][1] >> val[i][2];

  int answer = MAX_VAL;

  for (int k = 0; k < 3; ++k) {

    for (int i = 0; i < 3; ++i) {
      cache[0][i] = (i == k ? val[0][i] : MAX_VAL);
    }

    for (int i = 1; i < N; ++i) {
      for (int j = 0; j < 3; ++j) {
        cache[i][j] = min(cache[i-1][(j+2)%3], cache[i-1][(j+4)%3]) + val[i][j];
      }
    }

    for (int i = 0; i < 3; ++i) {
      if(k != i) {
        answer = min(answer, cache[N-1][i]);
      }
    }
  }

  cout << answer;

  return 0;
}

