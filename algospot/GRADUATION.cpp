#include <bits/stdc++.h>
using namespace std;

int n, k, m, l;
const int INF = 987654321;
constexpr int MAXN = 12;
int pre[MAXN], classes[10];
int cache[10][1<<MAXN];

int bit_count(int n)
{
    bitset<sizeof(int) * CHAR_BIT> bs(n);
    return bs.count();
}

int graduate(int semester, int taken)
{
    if(bit_count(taken) >= k) return 0;

    if(semester == m) return INF;

    int& ret = cache[semester][taken];
    if(ret != -1) return ret;
    ret = INF;

    int can_take = (classes[semester] & ~taken);

    for(int i=0; i<n; ++i){
        if((can_take & (1 << i)) && (taken & pre[i]) != pre[i]){
            can_take &= ~(1 << i);
        }
    }

    for(int take = can_take; take > 0; take = ((take - 1)) & can_take){
        if(bit_count(take) > l) continue;
        ret = min(ret, graduate(semester + 1, taken | take) + 1);
    }

    ret = min(ret, graduate(semester + 1, taken));

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, i, j, tmp, tmp2;

    cin >> t;
    while(t--){
        memset(pre, 0, sizeof pre);
        memset(classes, 0, sizeof classes);
        memset(cache, -1, sizeof cache);

        cin >> n >> k >> m >> l;
        for(i=0; i<n; ++i){
            cin >> tmp;
            for(j=0; j<tmp; ++j){
                cin >> tmp2;
                pre[i] |= (1 << tmp2);
            }
        }

        for(i=0; i<m; ++i){
            cin >> tmp;
            for(j=0; j<tmp; ++j){
                cin >> tmp2;
                classes[i] |= (1 << tmp2);
            }
        }

        int ret = graduate(0, 0);
        if(ret == INF) cout << "IMPOSSIBLE\n";
        else cout << ret << "\n";
    }

    return 0;
}
