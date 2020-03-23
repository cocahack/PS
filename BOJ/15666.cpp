#include <bits/stdc++.h>
using namespace std;

int N, M, arr[8], seq[8];

void print_seq() {
  for (int i = 0; i < M; ++i) {
    cout << seq[i] << " ";
  }
  cout << "\n";
}

void recur(int num){
  if(num == M) {
    print_seq();
    return;
  }

  vector<int> used;

  for(int i=0; i<N; ++i) {
    bool go = true;

    for(auto u : used) {
      if (u == arr[i]) {
        go = false;
        break;
      }
    }

    if(go && (num - 1 == -1 || seq[num-1] <= arr[i])) {
      seq[num] = arr[i];
      used.push_back(arr[i]);
      recur(num + 1);
    }
  }

}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N >> M;
  for (int i = 0; i < N; ++i) cin >> arr[i];
  sort(arr, arr+N);

  recur(0);

  return 0;
}

