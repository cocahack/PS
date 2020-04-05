#include <bits/stdc++.h>
using namespace std;
int graph[51][51];
bool visited[51];

struct Node {
    int vertex, w;
    Node(int v):vertex(v){}
    Node(int v, int _w):vertex(v),w(_w){}
    bool operator < (const Node& rhs) const {
        if(w != rhs.w) return w > rhs.w;
        return vertex > rhs.vertex;
    }
};

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    memset(graph, -1, sizeof graph);
    for(auto r : road) {
        if(graph[r[0]][r[1]] == -1) {
        	graph[r[0]][r[1]] = r[2];
	        graph[r[1]][r[0]] = r[2];
        } else {
        	graph[r[0]][r[1]] = min(graph[r[0]][r[1]], r[2]);
	        graph[r[1]][r[0]] = min(graph[r[1]][r[0]], r[2]);
        }
    }

    priority_queue<Node> q;
    q.push(Node(1, 0));
    
    while(q.size()) {
        auto curr = q.top();
        q.pop();
        
        if(visited[curr.vertex]) continue;
        if(curr.w <= K) answer++;
        visited[curr.vertex] = true;
        
        for(int i=1; i<=N; ++i) {
            if( i == curr.vertex || visited[i] || graph[curr.vertex][i] == -1 ) continue;
            q.push(Node(i, curr.w + graph[curr.vertex][i]));
        }
    }
    

    return answer;
}

