#include <bits/stdc++.h>
using namespace std;
vector<int> student;
vector<bool> visited;
vector<bool> finished;

int dfs(int v){
    if(visited[v] && !finished[v]){
        int k = student[v];
        int ret = 0;
        while(k != v){
            ret++;
            k = student[k];
        }
        return ret + 1;
    }

    if(visited[v] && finished[v]){
        return 0;
    }

    visited[v] = true;

    int ret = dfs(student[v]);
    finished[v] = true;
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n;
    cin >> t;

    while(t--){
        cin >> n;
        int answer = 0;
        student = vector<int>(n+1, 0);
        visited = vector<bool>(n+1, 0);
        finished = vector<bool>(n+1, 0);
        for(int i=1; i<=n; ++i) cin >> student[i];
        for(int i=1; i<=n; ++i) {
            if (!visited[i]) {
                answer += dfs(i);
            }
        }
        cout << (n - answer) << "\n";
    }

    return 0;
}
