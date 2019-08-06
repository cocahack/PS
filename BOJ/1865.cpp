#include <bits/stdc++.h>
using namespace std;
constexpr int INF = 500 * 10000 + 1;
int n, m, w;
int upper[501];

void bellman_ford(vector<pair<int, int>> graph[501])
{
  fill(upper, upper + 501, INF);

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
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int tc, a, b, c;
  cin >> tc;

  while(tc--) {
    cin >> n >> m >> w;
    vector<pair<int, int>> graph[501];
    for(int i=0; i<m; ++i) {
      cin >> a >> b >> c;
      graph[a].push_back(make_pair(b, c));
      graph[b].push_back(make_pair(a, c));
    }
    for(int i=0; i<w; ++i) {
      cin >> a >> b >> c;
      graph[a].push_back(make_pair(b, -1 * c));
    }
    bellman_ford(graph);
  }

  return 0;
}

