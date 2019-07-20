#include <bits/stdc++.h>
using namespace std;
constexpr int MAX = 1000;
int arr[MAX]{0,}, ascend_cache[MAX]{0,}, descend_cache[MAX]{0,};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N;
  cin >> N;
  for(int i=0; i<N; ++i) cin >> arr[i];

  for(int i=0; i<N; ++i){
    int max_subseq = 0;
    for(int j=0; j<i; ++j){
      if(arr[j] < arr[i]) max_subseq = max(ascend_cache[j], max_subseq);
    }
    ascend_cache[i] = max_subseq + 1;
  }

  for(int i=N-1; i>=0; --i){
    int max_subseq = 0;
    for(int j=N-1; i<j; --j){
      if(arr[j] < arr[i]) max_subseq = max(descend_cache[j], max_subseq);
    }
    descend_cache[i] = max_subseq + 1;
  }

  int answer = max(ascend_cache[N-1], descend_cache[0]);

  for(int i=0; i<N; ++i){
    answer = max(answer, ascend_cache[i] + descend_cache[i] - 1);
  }

  cout << answer;

  return 0;
}
