#include <bits/stdc++.h>
using namespace std;
constexpr int ULIMIT = 1e6;

int fenwick[ULIMIT + 1]{0,};

void add(int pos, int val) {
    ++pos;
    while(pos < ULIMIT+1) {
        fenwick[pos] += val;
        pos += (pos & -pos);
    }
}

int sum(int pos) {
    ++pos;
    int ret = 0;
    while(pos > 0) {
        ret += fenwick[pos];
        pos &= (pos-1);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, a, b, c;
    cin >> N;
    while(N--) {
        cin >> a;
        if(a==1) {
            cin >> b;
            int lo = 0, hi = ULIMIT, s, mid;
            while(lo + 1 < hi) {
                mid = (lo + hi) / 2;
                s = sum(mid);
                if(b <= s) {
                    hi = mid;
                } else {
                    lo = mid;
                }
            }
            cout << hi << "\n";
            add(hi, -1);
        } else {
            cin >> b >> c;
            add(b, c);
        }
    }

    return 0;
}

