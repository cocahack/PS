#include <bits/stdc++.h>
#define for1d(size) for(int i=0; i<size; ++i)
using namespace std;

int arr[1000001];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N, B, C;
  cin >> N;
  long long answer = N;
  for1d(N) cin >> arr[i+1];
  cin >> B >> C;

  for1d(N) {
    arr[i+1] -= B;
    if(arr[i+1] > 0) {
      answer += arr[i+1] / C;
      answer += (arr[i+1] % C) > 0 ? 1 : 0;
    }
  }

  cout << answer;

  return 0;
}

