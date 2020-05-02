#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;
int answer = INF;
int N, W;
bool checked[8][1<<15]{0,};

inline int get_dist(int last, int cur, int clockwise) {
    if (!clockwise) swap(last, cur);
    return  (cur - last <= 0 && cur != last ? N + cur - last : cur - last);
}

void dfs(vector<int>& weak, vector<int>& dist, int u, int visited, int depth) {
    if(depth >= answer || (u == dist.size() && visited != (1 << W) - 1)) return;

    if(checked[u][visited]) return;
    checked[u][visited] = true;
     
    int origin_visited = visited, d = dist[u], j, last, move;
    for(int i=0; i<W; ++i) {
        if(visited & (1 << i)) continue;

        j = i, move = 0, last = weak[i];
        while(visited != (1 << W) - 1 || (visited & (1 << j)) != 0) {
            move += get_dist(last, weak[j], 1);
            last = weak[j];
            if(move > d) break;
            visited |= 1 << j;
            j = (j + 1) % W;
        }

        if(visited == (1 << W) - 1) {
            answer = min(answer, depth);
            return;
        }
        else dfs(weak, dist, u + 1, visited, depth + 1);

        visited = origin_visited;

        j = i, move = 0, last = weak[i];
        while(visited != (1 << W) - 1 || (visited & (1 << j)) != 0) {
            move += get_dist(last, weak[j], 0);
            last = weak[j];
            if(move > d) break;
            visited |= 1 << j;
            j = (j + W - 1) % W;
        }

        if(visited == (1 << W) - 1) {
            answer = min(answer, depth);
            return;
        }
        else dfs(weak, dist, u + 1, visited, depth + 1);

        visited = origin_visited;
    }
}


int solution(int n, vector<int> weak, vector<int> dist) {
    N = n;
    W = weak.size();
    sort(dist.begin(), dist.end(), greater<int>());
    
    dfs(weak, dist, 0, 0, 1);
    return answer == INF ? -1 : answer;
}

