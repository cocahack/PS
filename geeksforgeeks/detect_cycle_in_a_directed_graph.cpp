bool dfs(vector<int> adj[], int u, vector<int>& seq, int count)
{
    bool ret = false;
    seq[u] = count;
    for(int v : adj[u]) {
        if(seq[v] != 0) {
            return true;
        }
        ret = dfs(adj, v, seq, count + 1);
        if(ret) return ret;
        
    }
    seq[u] = 0;
    
    return ret;
}

/*This is a function problem.You only need to complete the function given below*/
/*  Function to check if the given graph contains cycle
*   V: number of vertices
*   adj[]: representation of graph
*/
bool isCyclic(int V, vector<int> adj[])
{
    // Your code here
    vector<int> seq(V, 0);
    
    for(int i=0; i<V; ++i) {
        if(dfs(adj, i, seq, 1)) {
            return true;
        }
    }
    
    return false;
}


#include <bits/stdc++.h>
using namespace std;
int main() {

	int t;
	cin >> t;

	while(t--){

	    int v, e;
	    cin >> v >> e;

	    vector<int> adj[v];

	    for(int i =0;i<e;i++){
	        int u, v;
	        cin >> u >> v;
	        adj[u].push_back(v);
	    }

	    cout << isCyclic(v, adj) << endl;

	}

	return 0;
}

