/*
두 점 사이의 거리가 d 이하일 때 같은 집합으로 합친 뒤,
모든 점이 같은 집합에 속해있다면 더 좋은 답을 찾고,
그렇지 않다면 더 나쁜 답을 찾도록 한다.
*/

#include <bits/stdc++.h>
using namespace std;
constexpr int MAX = 100;
struct point{
    double _x, _y;
    point(double x, double y):_x(x), _y(y) {}
    point(){}
};
point center[MAX+1];

inline double distance(point* p1, point* p2)
{
    double value = sqrt(pow((p1->_x - p2->_x), 2) + pow((p1->_y - p2->_y), 2));
    return value;
}

int find(int parent[], int u)
{
    if(parent[u] == u) return u;
    return parent[u] = find(parent, parent[u]);
}

void union_nodes(int parent[], int u, int v)
{
    u = find(parent, u), v = find(parent, v);
    if(u == v) return;
    if(u > v) swap(u, v);
    parent[v] = u;
}

bool is_possible(int n, double d)
{
    int parent[MAX+1], i;
    for(i=0; i<n; ++i){ parent[i] = i; }
    for(i=0; i<n; ++i){
        for(int j=i; j<n; ++j){
            if(i == j) continue;
            if(isgreaterequal(sqrt(d * d), distance(&center[i], &center[j]))){
                union_nodes(parent, i, j);
            }
        }
    }

    int p = find(parent, 0);

    for(i=1; i<n; ++i) if(p != find(parent, i)) return false;
    return true;
}

double solve(int n)
{
    double lo = .0, hi = 1000.0, mid;

    while (fabs(hi - lo) > 10e-10){
        mid = (lo + hi) / 2.0;
        if(is_possible(n, mid)){
            hi = mid;
        } else {
            lo = mid;
        }
    }

    return hi;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << showpoint << setprecision(2);

    int c, n;
    double x, y;
    cin >> c;

    while(c--){
        cin >> n;
        for(int i=0; i < n; ++i){
            cin >> x >> y;
            center[i]._x = x;
            center[i]._y = y;
        }
        cout << floor((solve(n) + 0.005) * 100) / 100 << "\n";
    }


    return 0;
}
