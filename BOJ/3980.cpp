#include <bits/stdc++.h>
using namespace std;

int answer, player[11][11], visited[11];

void sum(int n, int acc) {
  if(n == 11) {
    answer = max(answer, acc);
    return;
  }

  for(int i=0; i<11; ++i) {
    if(visited[i] || player[n][i] == 0) continue;
    visited[i] = true;
    sum(n+1, acc + player[n][i]);
    visited[i] = false;
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  while(t--) {
    for(int i=0; i<11; ++i) for(int j=0; j<11; ++j) cin >> player[i][j];
    memset(visited, 0, sizeof visited);
    answer = -1;

    sum(0, 0);
    cout << answer << "\n";
  }

  return 0;
}
