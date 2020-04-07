#include <bits/stdc++.h>
using namespace std;
constexpr int MOD = 1000000007;

int memo[100001]{0,};

int solution(int n, vector<int> money) {
    sort(money.begin(), money.end());
    
    memo[0] = 1;
	for (int i=money[0] ; i<=n ; i+=money[0]) memo[i] = 1;
    
    for(int i=1; i<money.size(); ++i) {
        for(int j=0; j<=n; ++j) {
            if(j >= money[i]) {
                memo[j]= ((memo[j] % MOD) + (memo[j-money[i]] % MOD)) % MOD;
            }
        }
    }
    
    return memo[n];
}

