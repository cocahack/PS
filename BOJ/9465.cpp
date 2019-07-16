#include <bits/stdc++.h>>
using namespace std;

int cache[2][100001]{0,};
int sticker[2][100001]{0,};

int solution(int n)
{
    memset(cache, 0, sizeof cache);
    cache[0][1] = sticker[0][1];
    cache[1][1] = sticker[1][1];

    for(int i=2; i<=n; ++i){
        for(int j=0; j<2; ++j){
            int dy = j ? -1 : 1;
            cache[j][i] = max(cache[j+dy][i-1], cache[j+dy][i-2])+ sticker[j][i];
        }
    }

    return max(cache[0][n], cache[1][n]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i=0; i<2; ++i){
            for(int j=1; j<=n; ++j){
                cin >> sticker[i][j];
            }
        }
        cout << solution(n) << "\n";
    }

    return 0;

}
