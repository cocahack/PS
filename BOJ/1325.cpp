#include <bits/stdc++.h>
using namespace std;

vector<int> graph[10001];
int n, m;
bool visited[10001]{0,};

struct Node_Info{
  int n, c;
  Node_Info(int _n, int _c): n(_n), c(_c) {}
  Node_Info(){}
  bool operator < (const Node_Info& rhs) const {
    if(c != rhs.c) return c > rhs.c;
    return n < rhs.n;
  }
};

set<Node_Info> answer;

int dfs(int node) {
  int ret = 1;

  visited[node] = true;

  for(int i=0; i<graph[node].size(); ++i){
    int next = graph[node][i];
    if(visited[next]) continue;
    ret += dfs(graph[node][i]);
  }

  return ret;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int a, b;
  cin >> n >> m;
  for(int i=0; i<m; ++i) {
    cin >> a >> b;
    graph[b].push_back(a);
  }

  for(int i=1; i<=n; ++i) {
    memset(visited, 0, sizeof visited);
    answer.insert(Node_Info(i, dfs(i)));
  }

  int max_val = answer.begin()->c;
  for(auto s : answer) {
    if(s.c != max_val) break;
    cout << s.n << " ";
  }

  return 0;
}

