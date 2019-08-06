#include <bits/stdc++.h>
using namespace std;
constexpr int INF = 500 * 10000 + 1;
int n, m;
vector<pair<int, int>> graph[501];
int upper[501];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  fill(upper, upper + 501, INF);
  cin >> n >> m;
  int a, b, c;

  for(int i=0; i<m; ++i) {
    cin >> a >> b >> c;
    graph[a].push_back(make_pair(b, c));
  }

  if(graph[1].empty()) {
    for(int i=2; i<=n; ++i) {
      cout << -1 << "\n";
    }
    return 0;
  }
    
  upper[1] = 0;
  bool updated;

  for(int i=1; i<=n; ++i){
    updated = false;
    for(int j=1; j<=n; ++j) {
      for(auto e : graph[j]) {
        if(upper[j] + e.second < upper[e.first]) {
          upper[e.first] = upper[j] + e.second;
          updated = true;
        }
      }
    }
    if(!updated) break;
  }

  if(updated) {
    cout << -1;
  } else {
    for(int i=2; i<=n; ++i){
      cout << (upper[i] == INF ? -1 : upper[i]) << "\n";
    }
  }

  return 0;
}

