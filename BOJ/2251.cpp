#include <bits/stdc++.h>
using namespace std;

set<int> answer;

set<tuple<int,int,int,int,int>> visited;

int max_b[3];
int b[3];

void dfs(int from, int to, bool force)
{
  if(!force && visited.find(make_tuple(b[0], b[1], b[2], from, to)) != visited.end()) return;
  if(!b[from]) return;

  visited.insert(make_tuple(b[0], b[1], b[2], from, to));
  int liter = min(max_b[to] - b[to], b[from]);
  b[to] += liter;
  b[from] -= liter;

  if(!b[0]) answer.insert(b[2]);

  int another = 3 - from - to;

  dfs(from, another, false);
  dfs(to, another, false);
  dfs(another, to, false);
  dfs(another, from, false);

  b[to] -= liter;
  b[from] += liter;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);


  cin >> max_b[0] >> max_b[1] >> max_b[2];

  b[2] = max_b[2];

  dfs(2, 0, 0);

  for(int i : answer){
    cout << i << " ";
  }

  return 0;
}
