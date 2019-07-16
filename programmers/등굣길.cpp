#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int MOD = 1000000007;
ll cache[101][101] {0,};
bool puddle[101][101]{0,};

bool check_point(int y, int x, int m, int n)
{
    return ((y >= 0 && y < n) && (x >= 0 && x < m));
}

int solution(int m, int n, vector<vector<int>> puddles)
{
    for(auto v : puddles){
        puddle[v[1]-1][v[0]-1] = true;
    }

    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            if(puddle[i][j]) continue;
            else if(i+j==1) cache[i][j] = 1;
            else cache[i][j] =( (check_point(i-1, j, m, n)? cache[i-1][j] % MOD : 0) +
                                (check_point(i, j-1, m, n)? cache[i][j-1] % MOD : 0) ) % MOD;
        }
    }

    return cache[n-1][m-1] ;
}
