#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll k, n;
ll cable[10001];

bool is_possible(ll len)
{
    ll count = 0;
    for(int i=0; i<k; ++i){
        count += cable[i] / len;
    }
    return count >= n;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> k >> n;

    for(int i=0; i<k; ++i) cin >> cable[i];
    sort(cable, cable + k);

    ll lo = 0, hi = cable[k-1], mid;

    while(lo + 1 < hi){
        mid = (lo + hi) / 2;
        if(is_possible(mid)) lo = mid;
        else hi = mid;
    }

    cout << (is_possible(hi) ? hi : lo) ;

    return 0;
}
