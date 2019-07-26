#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N;
  cin >> N;

  if(N % 2 == 0){
    cout << "I LOVE CBNU";
    return 0;
  }

  vector<string> v(N/2 + 2, "");

  for(int i=0; i<N; ++i){
    v[0] += '*';
  }

  for(int i=0; i<N/2; ++i){
    v[1] += ' ';
  }
  v[1] += '*';

  for(int i=0; i<N/2; ++i) {
    for(int j=0; j<N/2+i+2; ++j) {
      if(j == N/2 - i - 1) {
        v[i+2] += '*';
      } else if(j == N / 2 + i + 1){
        v[i+2] += '*';
      } else {
        v[i+2] += ' ';
      }
    }
  }

  for(auto s : v) {
    cout << s << "\n";
  }

  return 0;
}
