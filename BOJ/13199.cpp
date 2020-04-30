#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T, P, M, F, C;
    cin >> T;
    while(T--) {
        cin >> P >> M >> F >> C;
        int c0 = M / P * C;
        int scnt = c0 / F * C + c0 % F;
        if(scnt < F) {
            cout << 0 << "\n";
        } else {
            cout << (scnt - F) / (F - C) + 1 << "\n";
        }
    }
    return 0;
}

