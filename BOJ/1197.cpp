#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Edge {
  int from, to, val;
  Edge(int _f, int _t, int _v):from(_f), to(_t), val(_v){}
  Edge() {from = to = val = 0;}
  bool operator < (const Edge &rhs) const {
    if(val != rhs.val) return val < rhs.val;
    if(from != rhs.from) return from < rhs.from;
    return to < rhs.to;
  }
};

int V, E;
vector<Edge> e;
int parent[10001], nrank[10001];

int find(int v)
{
  return v == parent[v] ? v : (parent[v] = find(parent[v]));
}

void Union(int u, int v)
{
  u = find(u), v = find(v);
  if(u == v) return;

  if(nrank[u] < nrank[v]) swap(u, v);

  parent[v] = u;
  nrank[u] += (nrank[u] == nrank[v] ? 1 : 0);
}

ll solution(vector<Edge> &e)
{
  ll ret = 0;

  for(auto E : e) {
    int parent_from = find(E.from), parent_to = find(E.to);
    if(parent_from != parent_to){
      ret += E.val;
      Union(parent_from, parent_to);
    }
  }

  return ret;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> V >> E;
  e = vector<Edge>(E);

  for(int i=0; i<E; ++i) {
    cin >> e[i].from >> e[i].to >> e[i].val;
  }

  sort(e.begin(), e.end());

  for(int i=1; i<=10000; ++i){
    parent[i] = i, nrank[i] = 1;
  }

  cout << solution(e);

  return 0;
}
