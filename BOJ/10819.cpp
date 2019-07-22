#include <bits/stdc++.h>
using namespace std;
int arr[8];
inline int int_abs(int a, int b)
{
  int ret = a - b;
  return ret < 0 ? -1 * ret : ret;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N;
  cin >> N;

  for(int i=0; i<N; ++i) cin >> arr[i];
  sort(arr, arr+N);

  int answer = 0;
  do {
    int sum = 0;
    for(int i=0; i<N-1; ++i){
      sum += int_abs(arr[i], arr[i+1]);
    }
    answer = max(answer, sum);
  } while ( std::next_permutation(arr, arr+N) );


  cout << answer;

  return 0;
}
