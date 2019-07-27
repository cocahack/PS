#include <bits/stdc++.h>
using namespace std;
int N, arr[10000]{0,};

void loop(int& answer, int& i, bool neg)
{
  while(i < N){
    if(i+1 == N) {
      answer += arr[i++];
      continue;
    }

    if(neg && arr[i] >= 0) {
      break;
    }

    int add = arr[i] + arr[i+1];
    int mul = arr[i] * arr[i+1];

    if(mul > add){
      answer += mul;
      i+=2;
    } else {
      answer += arr[i];
      i++;
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N;
  int pos = 0, neg = 0;

  for(int i=0; i<N; ++i) cin >> arr[i], arr[i] < 0 ? neg++ : pos++;
  sort(arr, arr + N);

  int i = 0, answer = 0;

  loop(answer, i, true);

  while(i < N && arr[i] == 0){
    i++;
  }

  sort(arr+i, arr+N, greater<int>());

  loop(answer, i, false);

  cout << answer;

  return 0;
}
