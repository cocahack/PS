#include <bits/stdc++.h>
using namespace std;
char island[1001][1001] {0,};
int cache[1001][1001];
bool visited[1001][1001]{0,};
int n, m, start_y, start_x;

struct point
{
    int y, x;
    point(int y_ = 0, int x_ = 0):y(y_), x(x_){}
};

bool check_boundary(int y, int x)
{
    return (y > -1 && y < n) && (x > -1 && x < m);
}

int solve()
{
    int answer = -1;
    cache[start_y][start_x] = 0;

    queue<point> q;
    q.push(point(start_y, start_x));

    while (q.size()){
        auto p = q.front();
        q.pop();

        char cur = island[p.y][p.x];
        if(cur == '#' || visited[p.y][p.x]) continue;
        visited[p.y][p.x] = true;
        int& ref = cache[p.y][p.x];


        if(check_boundary(p.y - 1, p.x - 1)) ref = max(ref, cache[p.y-1][p.x-1]);
        if(check_boundary(p.y, p.x - 1)) ref = max(ref, cache[p.y][p.x-1]);
        if(check_boundary(p.y + 1, p.x - 1)) ref = max(ref, cache[p.y+1][p.x-1]);

        if(cur == 'C') ++ref;
        if(cur == 'O') answer = max(answer, ref);

        if(check_boundary(p.y - 1, p.x + 1)) q.push(point(p.y-1, p.x+1));
        if(check_boundary(p.y, p.x + 1)) q.push(point(p.y, p.x+1));
        if(check_boundary(p.y + 1, p.x + 1)) q.push(point(p.y+1, p.x+1));
    }

    return answer;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    memset(cache, -1, sizeof cache);

    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            cin >> island[i][j];
            if(island[i][j] == 'R'){
                start_y = i, start_x = j;
            }
        }
    }

    cout << solve();
    return 0;
}
