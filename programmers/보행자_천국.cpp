#include <bits/stdc++.h>

using namespace std;

int MOD = 20170805;
int cache[500][500][2];
int M, N;

inline bool check_boundary(int y, int x) {
    return y >= 0 && x >= 0 && y < M && x < N;
}

inline int add_with_mod(int a, int b) {
    return ((a % MOD) + (b % MOD)) % MOD;
}

int dp(const vector<vector<int>>& city, int y, int x, bool before_down) {
    if(!check_boundary(y, x) || city[y][x] == 1) {
        return 0;
    }
    if(y == M-1 && x == N-1) return 1;
    
    int& ret = cache[y][x][before_down];
    if(ret != -1) return ret;
    ret = 0;
    
    if(city[y][x] == 2) {
        if(before_down) {
            ret = add_with_mod(ret, dp(city, y+1, x, before_down));
        } else {
            ret = add_with_mod(ret, dp(city, y, x+1, before_down));
        }
    } else {
        ret = add_with_mod(ret, dp(city, y+1, x, true));
        ret = add_with_mod(ret, dp(city, y, x+1, false));
    }

    return ret;
}

int solution(int m, int n, vector<vector<int>> city_map) {
    M = m, N = n;
    memset(cache, -1, sizeof cache);
    return dp(city_map, 0, 0, false);
}

