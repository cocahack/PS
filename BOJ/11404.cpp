#include <bits/stdc++.h>
using namespace std;
constexpr int INF = 987654321;
int n, m;
vector<vector<int>> buses(101, vector<int>(101, INF));

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int a, b, c;
  cin >> n >> m;
  for(int i=0; i<m; ++i){
    cin >> a >> b >> c;
    buses[a][b] = min(buses[a][b], c);
  }

  for(int i=1; i<=n; ++i) buses[i][i] = 0;

  for(int k=1; k<=n; ++k) {
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        buses[i][j] = min(buses[i][j], buses[i][k] + buses[k][j]);
      }
    }
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cout << (buses[i][j] == INF ? 0 : buses[i][j]) << " ";
    }
    cout << "\n";
  }

  return 0;
}

