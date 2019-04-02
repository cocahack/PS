#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;
constexpr int INF = 50001;

int solution(int n, vector<vector<int>> edge) {
    int i, ans = 0;
    vector<vector<int>> graph(n+1, vector<int>{});
    vector<bool> visited(n+1, false);

    for(i = 0; i < edge.size(); ++i){
        graph[edge[i][0]].push_back(edge[i][1]);
        graph[edge[i][1]].push_back(edge[i][0]);
    }

    queue<int> nodes;
    nodes.push(1);

    int max_val = 0;
    vector<int> min_path (n+1, INF);
    min_path[1] = 0;

    while (nodes.size()){
        auto node = nodes.front();
        nodes.pop();
        if(visited[node]) continue;

        for(i = 0; i < graph[node].size() ; ++i){
            int dest = graph[node][i];
            if(visited[dest]) continue;
            min_path[dest] = min(min_path[dest], min_path[node] + 1);
            max_val = max(max_val, min_path[dest]);
            if(!visited[dest]){
                nodes.push(dest);
            }
        }

        visited[node] = true;
    }

    for(i = 1; i <= n; ++i){
        ans += (min_path[i] == max_val ? 1 : 0);
    }

    return ans;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << solution(6, {{3, 6}, {4, 3}, {3, 2}, {1, 3}, {1, 2}, {2, 4}, {5, 2}}) << "\n";

    return 0;
}
