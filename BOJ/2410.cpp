#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll cache[1000001]{0,};
constexpr int MOD = 1000000000;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;

    cache[0] = 1;
    for (auto i = 1; i <= n; i <<= 1) {
        for (auto j = i; j <= n; ++j) {
            cache[j] = (cache[j] + cache[j - i]) % MOD;
        }
    }

    cout << cache[n];

    return 0;
}
