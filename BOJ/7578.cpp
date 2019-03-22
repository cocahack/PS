#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int MAX = 500000;
int A[MAX+1];
unordered_map<int, int> B;

struct FenwickTree{
    vector<int> _tree;
    FenwickTree(ll n) : _tree(n+1, 0){}
    ll sum(int pos){
        ++pos;
        int ret = 0;
        while(pos){
            ret += _tree[pos];
            pos &= (pos - 1);
        }
        return ret;
    }
    void update(int pos, ll val){
        ++pos;
        while (pos < _tree.size()){
            _tree[pos] += val;
            pos += (pos & -pos);
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, tmp, i;
    cin >> n;
    FenwickTree ft{n};
    for(i=0; i<n; ++i) cin >> A[i];
    for(i=0; i<n; ++i){
        cin >> tmp;
        B[tmp] = i;
    }

    ll ret = 0;
    for(i=0; i<n; ++i){
        int pos = B[A[i]];
        ret += ft.sum(n-1) - ft.sum(pos);
        ft.update(pos, 1);
    }

    cout << ret;


    return 0;
}
