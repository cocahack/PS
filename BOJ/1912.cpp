#include <bits/stdc++.h>
using namespace std;
int cache[100001], n;
vector<int> arr;
int main()
{
    ios::sync_with_stdio(false);
    int n, maximum = -1000;
    cin >> n;
    arr = vector<int>(n+1);
    memset(cache, 0, sizeof(cache));
    for (int i = 1; i <= n; ++i) cin >> arr[i];
    
    cache[1] = arr[1];
    for (int i = 2; i <= n; ++i) {
        cache[i] = max(cache[i - 1] + arr[i], arr[i]);
        maximum = max(maximum, cache[i]);
    }
    maximum = max(maximum, cache[1]);
    cout << maximum << "\n";
    return 0;
}
