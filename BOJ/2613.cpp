#include <bits/stdc++.h>
using namespace std;
int b[301]{0,}, n, m;


bool is_possible(int max_val)
{
    int i, sum, cnt, subset;

    for (i = 0, sum = 0, cnt = 0, subset = 1; i < n - 1; i++) {
        sum += b[i];
        if (sum > max_val) {
            if(cnt == 0) return false;
            sum = b[i];
            if(sum > max_val) return false;
            cnt = 1;
            ++subset;
        } else {
            ++cnt;
        }
    }
    if (sum + b[i] > max_val) subset++;

    return subset <= m;
}



int solve() {
    int lo = 0, hi = 30000, mid;

    while(lo + 1 < hi){
        mid = (lo + hi) / 2;
        if(is_possible(mid)){
            hi = mid;
        } else {
            lo = mid;
        }
    }

    return is_possible(lo) ? lo : hi;
}

void print_sets(int max_val)
{
    int sum = 0, cnt = 0, i;
    for(i = 0, sum = 0, cnt = 0; i < n; ++i){
        sum += b[i];
        if(sum > max_val){
            cout << cnt << " ";
            cnt = 0;
            sum = b[i];
            --m;
        }
        ++cnt;
        if(n - i == m) break;
    }

    while(m--) cout << cnt << " ", cnt = 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for(int i=0; i<n; ++i) cin >> b[i];


    int ans = solve();
    cout << ans << "\n";
    print_sets(ans);

    return 0;
}
