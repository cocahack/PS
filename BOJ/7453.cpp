#include <bits/stdc++.h>
using namespace std;

constexpr int ULIMIT = 4 * 10e3;
int N, a[ULIMIT], b[ULIMIT], c[ULIMIT], d[ULIMIT];
vector<int> t;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; ++i) cin >> a[i] >> b[i] >> c[i] >> d[i];

  long long answer = 0;

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      t.push_back(a[i]+b[j]);
    }
  }

  sort(t.begin(), t.end());

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      int sum = c[i]+d[j];
      auto lower = lower_bound(t.begin(), t.end(), -sum);
      auto upper = upper_bound(t.begin(), t.end(), -sum);

      if(*lower + sum == 0) {
        answer += upper - lower;
      }
    }
  }
  cout << answer;

  return 0;
}

