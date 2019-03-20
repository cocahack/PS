#include <bits/stdc++.h>
using namespace std;
constexpr int MAX = 200;
double center[MAX+1]{0, };

bool is_possible(int n, int m, double mid)
{
    for(int start = 0; start < m; ++start){
        int rest = n - 1, last = start, iter = start + 1;

        while (rest > 0 && iter < m){
            if(center[iter] - center[last] >= mid){
                last = iter;
                rest--;
            }
            iter++;
        }
        if(rest == 0) return true;
    }
    return false;
}

double solve(int n, int m)
{
    double low = .0, high = 241.0, mid;

    while (fabs(high - low) > 2e-4){
        mid = (low + high) / 2.0;
        if(is_possible(n, m, mid)){
            low = mid;
        } else {
            high = mid;
        }
    }

    return low;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << showpoint << setprecision(2);

    int c, n, m;
    cin >> c;

    while(c--){
        cin >> n >> m;
        for(int i=0; i < m; ++i) cin >> center[i];
        cout << solve(n, m) + 0.005 << "\n";
    }


    return 0;
}
