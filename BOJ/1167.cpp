#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> children;
vector<bool> visited;
int answer = 0, n;

int get_perimeter(int here)
{
  visited[here] = true;
  int max_depth = 0, local_sum = 0;

  for(auto child : children[here]){
    int there = child.first, value = child.second;
    if(visited[there]) continue;
    int child_max_depth = get_perimeter(there) + value;
    local_sum = max(local_sum, max_depth + child_max_depth);
    if(max_depth < child_max_depth) {
      max_depth = child_max_depth;
    }
  }

  answer = max(answer, local_sum);

  return max_depth;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  children = vector<vector<pair<int, int>>>(n, vector<pair<int, int>>());
  visited = vector<bool>(n, false);
  int here, there, dist;

  for(int i=0; i<n; ++i) {
    cin >> here;
    while (1) {
      cin >> there;
      if (there == -1) break;
      cin >> dist;
      children[here - 1].push_back(make_pair(there - 1, dist));
    }
  }

  get_perimeter(0);

  cout << answer;

  return 0;
}
