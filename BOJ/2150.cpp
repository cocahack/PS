#include <bits/stdc++.h>
using namespace std;
constexpr int ULIMIT = 1e4;

int V, E, scc_counter, v_counter;
vector<int> graph[ULIMIT + 1];
vector<vector<int>> sccs;
vector<int> scc_id;
vector<int> discovered;
stack<int> st;
vector<set<int>> answer;

int scc(int curr) {
  int ret = discovered[curr] = v_counter++;
  st.push(curr);

  for(auto next: graph[curr]) {
    if(discovered[next] == -1) {
      ret = min(ret, scc(next));
    } else if(scc_id[next] == -1) {
      ret = min(ret, discovered[next]);
    }
  }

  if(ret == discovered[curr]) {
    answer.emplace_back();
    while(true) {
      int t = st.top();
      st.pop();
      scc_id[t] = scc_counter;
      answer[scc_counter].insert(t);
      if(t == curr) break;
    }
    ++scc_counter;
  }
  return ret;
}

void tarjan() {
  scc_id = discovered = vector<int>(V+1, -1);

  scc_counter = v_counter = 0;
  for(int i = 1; i <= V; ++i) if(discovered[i] == -1) scc(i);
}

bool comp(const set<int>& lhs, const set<int>& rhs) {
  return (*lhs.begin()) < (*rhs.begin());
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> V >> E;
  int u,v;

  for(int i=0; i<E; ++i) {
    cin >> u >> v;
    graph[u].push_back(v);
  }

  tarjan();

  sort(answer.begin(), answer.end(), comp);

  cout << scc_counter << "\n";

  for(auto a : answer) {
    for(auto vertex : a) {
      cout << vertex << " ";
    }
    cout << "-1\n";
  }

  return 0;
}

