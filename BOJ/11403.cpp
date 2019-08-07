#include <bits/stdc++.h>
using namespace std;

int graph[101][101]{0,}, n;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  for(int i=0; i<n; ++i) for(int j=0; j<n; ++j) cin >> graph[i][j];

  for(int k=0; k<n; ++k){
    for(int i=0; i<n; ++i) {
      for(int j=0; j<n; ++j) {
        graph[i][j] = graph[i][j] || (graph[i][k] && graph[k][j]);
      }
    }
  }

  for(int i=0; i<n; ++i) {
    for(int j=0; j<n; ++j){
      cout << graph[i][j] << " ";
    }
    cout << "\n";
  }

  return 0;
}

