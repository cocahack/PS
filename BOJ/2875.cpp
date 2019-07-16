#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;

    int t = min(n / 2, m);
    n -= t * 2, m -= t, k -= (n + m);

    while(t > 0 && k > 0){
        t--;
        k -= 3;
    }

    cout << t;

    return 0;
}
