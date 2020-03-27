#include <bits/stdc++.h>
using namespace std;

constexpr int ULIMIT = 10e4;
constexpr int LOW = -ULIMIT * 1000 - 1;

int N, answer = LOW, arr[ULIMIT];
vector<vector<int>> cache;

int dp(int curr, bool removed) {
  if(curr == N) return LOW;

  int& ret = cache[curr][removed];
  if(ret != LOW) return ret;

  ret = arr[curr];

  ret = max(ret, dp(curr+1, removed) + arr[curr]);

  if(!removed) {
    ret = max(ret, dp(curr+1, true));
  }

  answer = max(answer, ret);
  return ret;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N;
  cache = vector<vector<int>>(N, vector<int>(2, LOW));

  for (int i = 0; i < N; ++i) cin >> arr[i];

  dp(0, false);

  cout << answer;
  return 0;
}

