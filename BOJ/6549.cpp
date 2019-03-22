#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int MAX = 100000;
ll rec[MAX+1];

ll solve(int left, int right)
{
    if(left == right) return rec[left];

    int mid = (left + right) / 2;

    ll ret = solve(left, mid);
    ret = max(solve(mid+1, right), ret);

    int lo = mid, hi = mid + 1;
    ll height = min(rec[lo], rec[hi]);

    ret = max(ret, height * 2);

    while (left < lo || hi < right){
        if(hi < right && (lo == left || rec[lo-1] < rec[hi+1])){
            ++hi;
            height = min(height, rec[hi]);
        } else{
            --lo;
            height = min(height, rec[lo]);
        }
        ret = max(ret, height * (hi - lo + 1));
    }

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    while(1){
        cin >> n;
        if(n == 0) break;
        for(int i=0; i<n; ++i) cin >> rec[i];
        cout << solve(0, n - 1) << "\n";
    }

    return 0;
}
