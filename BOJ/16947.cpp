#include <bits/stdc++.h>
using namespace std;

constexpr int ULIMIT = 3 * 10e2 + 1;
int N, answer[ULIMIT];
bool visited[ULIMIT]{0,};
vector<int> graph[ULIMIT];

int dfs(int curr, int before) {
  visited[curr] = true;

  int cycle_start = -1;
  for(auto next : graph[curr]) {
    if(next == before) continue;

    if(!visited[next]) {
      cycle_start = dfs(next, curr);
      if(cycle_start != -1){
        answer[curr] = 0;
        break;
      }
    } else {
      answer[curr] = 0;
      return next;
    }
  }

  return cycle_start == curr ? -1 : cycle_start;
}

int dfs2(int curr, int before) {
  if(answer[curr] != -1) return answer[curr];

  for(auto next: graph[curr]) {
    if(next == before) continue;

    int next_value = dfs2(next, curr);
    if(next_value == -1) continue;

    answer[curr] = next_value + 1;
    break;
  }

  return answer[curr];
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  memset(answer, -1, sizeof answer);
  cin >> N;
  int a, b;

  for (int i = 0; i < N; ++i) {
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  dfs(1, -1);
  bool detected = false;
  for(int i = 1; i<=N; ++i) {
    if(answer[i] == 0) {
      detected = true;
      break;
    }
  }

  if(!detected) {
    memset(answer, 0, sizeof answer);
  }

  for(int i = 1; i<=N; ++i) {
    if(answer[i] == -1) {
      dfs2(i, -1);
    }
  }

  for (int i = 0; i < N; ++i) {
    cout << answer[i+1] << " ";
  }
  cout << "\n";

  return 0;
}

