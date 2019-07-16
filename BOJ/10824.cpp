#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string a, b, c, d;
    cin >> a >> b >> c >> d;
    a += b;
    c += d;

    ll aa = stoll(a), cc = stoll(c);

    cout << aa + cc;

    return 0;
}
