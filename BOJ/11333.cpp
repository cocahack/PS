#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1000000007;
ll dp[10001] {0,};

int solution(int n) {
    dp[3] = 3;

    for(int i=6; i<=n; i+=3){
        dp[i] = ((dp[i-3] % MOD) * (dp[3] % MOD)) % MOD;
        int add = 4;
        for(int j=i-6; j>0; j-=3){
            dp[i] = ((dp[i] % MOD) + (((dp[j] % MOD) * (add % MOD)) % MOD)) % MOD;
            add += 2;
        }
        dp[i] = ((dp[i] % MOD) + (add % MOD)) % MOD;
    }

    return dp[n];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t, n;
	cin >> t;
	while(t--){
		cin >> n;
		cout << solution(n) << "\n";
	}
	return 0;
}
