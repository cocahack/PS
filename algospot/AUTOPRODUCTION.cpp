#include <bits/stdc++.h>
using namespace std;

struct material
{
    int r, c;
    vector<int> slot;
};
using material = struct material;

bool can_produce(const vector<material>& m, const int n, int x, int rest, int p)
{
    if(x == n) return rest >= 0 ? true : false;

    // 선택할 수 있는 칸의 개수가 없는데 더 선택할게 남았다면 false
    if(rest<=0 && x < n) return false;

    int needs = m[x].r * p;

    for(int i=1; i<= rest; ++i){
        int sum = 0;
        if(i > m[x].c) break;
        for(int j=0; j<i; ++j){
            sum += m[x].slot[j];
        }
        if(sum>=needs && can_produce(m, n, x+1, rest-i, p)) return true;
    }

    return false;
}

int solve(const vector<material>& m, const int n)
{
    int min = 0, max = 10000, mid;

    while(min+1<max){
        mid = (min+max)/2;

        if(can_produce(m,n,0,10,mid))
            min = mid;
        else
            max = mid;
    }

    while(max>=0){
        if(max ==0) return max;
        if(can_produce(m,n,0,10,max)) return max;
        --max;
    }
}

int main()
{
    int t, n;
    scanf("%d", &t);

    while(t--){
        scanf("%d", &n);

        vector<material> m(n);
        int tmp;

        for(int i=0; i<n; ++i) {
            scanf("%d %d", &m[i].r, &m[i].c);
            for(int j=0; j<m[i].c; ++j)
                scanf("%d", &tmp), m[i].slot.push_back(tmp);
            sort(m[i].slot.begin(), m[i].slot.end(), greater<int>());
        }

        printf("%d\n", solve(m, n));
    }
    return 0;
}
