#include <bits/stdc++.h>
using namespace std;
constexpr int MAX = 8030000;
int L[MAX+1], M[MAX+1], G[MAX+1];

bool is_possible(int n, int k, int num)
{
    int tot = 0;
    for(int i=0; i<n; ++i){
        if(num >= L[i] - M[i]) {
            tot += (min(L[i], num) - (L[i] - M[i])) / G[i] + 1;
        }
    }
    return tot >= k;
}

int solve(int n, int k)
{
    int lo = 0, hi = MAX, mid;

    while (lo + 1 < hi){
        mid = (lo + hi) / 2;
        if(is_possible(n, k, mid)){
            hi = mid;
        } else {
            lo = mid;
        }
    }

    return is_possible(n, k, lo) ? lo : hi;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int c, n, k;
    cin >> c;

    while(c--){
        cin >> n >> k;
        for(int i=0; i < n; ++i){
            cin >> L[i] >> M[i] >> G[i];
        }
        cout << solve(n, k) << "\n";
    }


    return 0;
}
