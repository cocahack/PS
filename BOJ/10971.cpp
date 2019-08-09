#include <bits/stdc++.h>
using namespace std;
int n, cost[11][11]{0,};
constexpr int INF = 987654321;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  for(int i=0; i<n; ++i) for(int j=0; j<n; ++j) cin >> cost[i][j];
  int answer = INF;

  vector<int> arr(n, 0);
  for(int i=0; i<n; ++i) arr[i] = i;
  int travel_cost;
  do {
    travel_cost = 0;
    bool success = true;
    for(int i=0; i<n; ++i) {
      int u = arr[i], v = i == n - 1 ? arr[0] : arr[i+1];
      if(cost[u][v] == 0) {
        success = false;
        break;
      }
      travel_cost += cost[u][v];
    }
    if(success) answer = min(answer, travel_cost);
  } while (next_permutation(arr.begin(), arr.end()));

  cout << answer;

  return 0;
}

