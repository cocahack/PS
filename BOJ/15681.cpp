#include <bits/stdc++.h>
using namespace std;

constexpr int MAX_NODE = 10e5+1;
int N, R, Q;

vector<int> tree[MAX_NODE];
int vs[MAX_NODE];
bool visited[MAX_NODE]{0,};

int make_tree(int root) {
  int& ret = vs[root];
  if(ret != -1) return ret;

  ret = 1;
  visited[root] = true;
  for(auto& child : tree[root]) {
    if(!visited[child]) {
      ret += make_tree(child);
    }
  }
  return ret;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N >> R >> Q;
  int u, v, q;

  for (int i = 0; i < N - 1; ++i) {
    cin >> u >> v;
    tree[u].push_back(v);
    tree[v].push_back(u);
  }

  memset(vs, -1, sizeof vs);
  make_tree(R);

  for (int j = 0; j < Q; ++j) {
    cin >> q;
    cout << vs[q] << "\n";
  }
  return 0;
}

