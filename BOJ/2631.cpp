#include <bits/stdc++.h>
using namespace std;

int N;
int arr[201];
int memo[201]{0,};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N;
  for(int i=1; i<=N; ++i) cin >> arr[i];

  for(int i=1; i<=N; ++i) {
    memo[i] = 1;
    for(int j=0; j<i; ++j) {
      if(arr[j] < arr[i]) memo[i] = max(memo[i], memo[j] + 1);
    }
  }

  cout << N - *max_element(memo + 1, memo + N + 1);

  return 0;
}

