#include <bits/stdc++.h>
#define for1d(size) for(int i=0; i<size; ++i)
using namespace std;
int v,e,s;
vector<pair<int,int>> graph[20001];
int dst[20001];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> v >> e >> s;
  fill(dst, dst+v+1, 2000000);
  dst[s] = 0;

  int a,b,c;
  for1d(e) {
    cin >> a >> b >> c;
    graph[a].push_back({b, c});
  }

  auto compare = [](int lhs, int rhs) { return dst[lhs] > dst[rhs]; };

  priority_queue<int, vector<int>, decltype(compare)> q(compare);
  q.push(s);

  while(q.size()) {
    int cur = q.top();
    q.pop();

    for(auto p : graph[cur]) {
      int next_v = p.first, w = p.second;
      if(dst[cur] + w < dst[next_v]) {
        dst[next_v] = dst[cur] + w;
        q.push(next_v);
      }
    }
  }

  for1d(v) {
    if(dst[i+1] == 2000000) {
      cout << "INF\n";
    } else {
      cout << dst[i+1] << "\n";
    }
  }

  return 0;
}

