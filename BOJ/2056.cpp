#include <bits/stdc++.h>
using namespace std;
constexpr int MAX = 10001;
int cost[MAX]{0,}, N;
vector<int> graph[MAX];
int visited[MAX]{0,};

int dfs(int u)
{
  if(visited[u]) return visited[u];

  int& ret = visited[u];
  ret = cost[u];
  for(int v : graph[u]){
    ret = max(ret, cost[u] + dfs(v));
  }

  visited[u] = ret;

  return ret;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string s;
  int t;
  cin >> N;
  for(int i=1; i<=N; ++i){
    int k;
    cin >> cost[i];
    cin >> k;

    while(k--){
      cin >> t;
      graph[t].push_back(i);
    }
  }

  int answer = 0;
  for(int i=1; i<=N; ++i){
    if(!visited[i]){
      answer = max(answer, dfs(i));
    }
  }

  cout << answer;
  return 0;
}

