#include <bits/stdc++.h>

using namespace std;
void dfs(vector<vector<int>>& computers, vector<bool>& visited, int u)
{
    visited[u] = true;
    for(int v=0; v<computers[u].size(); ++v){
        if(!visited[v] && computers[u][v]){
            dfs(computers, visited, v);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    vector<bool> visited(n, 0);
    for(int i=0; i<n; ++i){
        if(!visited[i]) {
            dfs(computers, visited, i);
            ++answer;
        }
    }
    
    return answer;
}
