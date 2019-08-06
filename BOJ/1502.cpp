#include <bits/stdc++.h>
using namespace std;

int i, j, a, b, m, n;
bool visited[9][9], found = false;
int delta[4][2]{-1, 0, 0, -1, 1, 0, 0, 1};
int covered = 0;
inline bool check_boundary(int y, int x)
{
  return y > 0 && y <= m && x >0 && x <= n;
}

void dfs(int y, int x)
{
  if(!check_boundary(y, x) || visited[y][x]) return;
  if(y == a && x == b) {
    if(covered == m * n - 1) {
      found = true;
      cout << 1 << "\n";
      cout << y << " " << x << "\n";
    }
    return;
  }

  covered++;
  visited[y][x] = true;

  for(int i=0; i<4; ++i){
    dfs(y+delta[i][0], x+delta[i][1]);
    if(found) {
      cout << y << " " << x << "\n";
      return;
    }
  }

  covered--;
  visited[y][x] = false;

}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  while(t--) {
    cin >> m >> n >> i >> j >> a >> b;
    memset(visited, 0, sizeof visited);
    covered = 0;
    found = false;
    dfs(i, j);
    if(!found) cout << "-1\n";
  }

  return 0;
}

