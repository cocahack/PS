#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj, parent;
vector<int> b_time;

void dfs(int u, vector<bool>& visited, vector<int>& order)
{
    visited[u] = true;

    for(int i=0; i<adj[u].size(); ++i){
        int there = adj[u][i];
        if(!visited[there]){
            dfs(there, visited, order);
        }
    }
    order.push_back(u);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, t;
    cin >> n;

    adj = vector<vector<int>>(n+1, vector<int>{});
    parent = vector<vector<int>>(n+1, vector<int>{});
    b_time = vector<int>(n+1, 0);
    vector<bool> visited(n+1, false);

    for(int i=1; i<=n; ++i){
        cin >> t;
        b_time[i] = t;
        cin >> t;
        while(t != -1){
            adj[t].push_back(i);
            parent[i].push_back(t);
            cin >> t;
        }
    }

    vector<int> order, answer = vector<int>(n+1, 0);

    for(int i=1; i<=n; ++i){
        if(!visited[i]) dfs(i, visited, order);
    }

    reverse(order.begin(), order.end());

    for(auto u : order){
        int parent_max = 0;
        for(int i = 0; i < parent[u].size(); ++i){
            int v = parent[u][i];
            if(parent_max < answer[v]) parent_max = answer[v];
        }
        answer[u] = parent_max + b_time[u];
    }

    for(int i = 1; i <= n; ++i){
        cout << answer[i] << "\n";
    }


    return 0;
}
