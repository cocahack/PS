#include <bits/stdc++.h>
using namespace std;
constexpr int ULIMIT = 1e4+1;
constexpr int MOD = 1e9;
int N, M;
enum Color { White, Gray, Black } visited[ULIMIT]{White,};
vector<int> graph[2][ULIMIT];
bool available[2][ULIMIT]{0,};
vector<int> cache(ULIMIT, -1);
bool above_9digits = false;

void dfs(bool direction, int u) {
  if(available[direction][u]) return;
  available[direction][u] = true;
  for(int v : graph[direction][u]) {
    dfs(direction, v);
  }
}

int dp(int u) {
  if(visited[u] == Black) return cache[u];
  if(visited[u] == Gray) throw "Cycle detected";

  cache[u] = 0;
  visited[u] = Gray;
  if(u == 2) cache[2] = 1;

  for(int v : graph[0][u]) {
    if(available[0][v] && available[1][v]) {
      long long acc = cache[u] + dp(v);
      if(acc >= MOD) {
        above_9digits = true;
        acc -= MOD;
      }
      cache[u] = acc;
    }
  }

  visited[u] = Black;
  return cache[u];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N >> M;
  int u, v;
  for(int i=0; i<M; ++i) {
    cin >> u >> v;
    graph[0][u].push_back(v);
    graph[1][v].push_back(u);
  }

  dfs(0, 1);
  dfs(1, 2);

  try {
    int answer = dp(1);
    if(above_9digits) {
      int len = 0, cp = answer;
      while(cp) {
        len++;
        cp /= 10;
      }
      while(9 - len) {
        cout << 0;
        ++len;
      }
      cout << answer;
    } else{
      cout << answer;
    }
  } catch (...) {
    cout << "inf";
  }

  return 0;
}

