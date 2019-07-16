#include<bits/stdc++.h>
using namespace std;
int seq[1001];
int visited[1001];

int dfs(int v){
    if(visited[v]) return 1;

    visited[v] = true;

    return dfs(seq[v]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n;
    cin >> t;

    while(t--){
        int answer = 0;
        memset(visited, 0, sizeof visited);
        cin >> n;
        for(int i=1; i<=n; ++i) cin >> seq[i];
        for(int i=1; i<=n; ++i){
            if(!visited[i]){
                answer += dfs(i);
            }
        }
        cout << answer << "\n";
    }

    return 0;

}
