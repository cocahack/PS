#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll INF = 987654321;
int n, m;
vector<pair<ll, ll>> graph[501];
ll upper[501];
bool can_reach[501]{0,};

void dfs(int u) {
    if(can_reach[u]) return;
    can_reach[u] = true;
    for(auto e : graph[u]) {
        dfs(e.first);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    fill(upper, upper + 501, INF);
    cin >> n >> m;
    ll a, b, c;

    for(int i=0; i<m; ++i) {
        cin >> a >> b >> c;
        graph[a].push_back(make_pair(b, c));
    }
    
    dfs(1);

    upper[1] = 0;
    bool updated;

    for(int i=1; i<=n; ++i){
        updated = false;
        for(int j=1; j<=n; ++j) {
            for(auto e : graph[j]) {
                if(upper[j] + e.second < upper[e.first]) {
                    if(!(can_reach[j] || can_reach[e.first])) {
                        continue;
                    } 
                    upper[e.first] = upper[j] + e.second;
                    updated = true;
                }
            }
        }
        if(!updated) break;
    }

    if(updated) {
        cout << -1;
    } else {
        for(int i=2; i<=n; ++i){
            cout << (!can_reach[i] || upper[i] == INF ? -1 : upper[i]) << "\n";
        }
    }

    return 0;
}

