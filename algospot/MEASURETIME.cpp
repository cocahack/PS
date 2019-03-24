#include <bits/stdc++.h>
using namespace std;
constexpr int MAX = 1000000;

int seq[50000];
int tree[MAX+1];

int sum(int arr[], int idx)
{
    ++idx;
    int ret = 0;
    while(idx){
        ret += arr[idx];
        idx &= (idx - 1);
    }
    return ret;
}

void update(int arr[], size_t size, int idx, int val)
{
    ++idx;
    while(idx < size){
        arr[idx] += val;
        idx += (idx & -idx);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n, i, answer;
    cin >> t;

    while(t--){
        memset(tree, 0, sizeof tree);
        answer = 0;
        cin >> n;
        for(i=0; i<n; ++i) cin >> seq[i];

        for(i=0; i<n; ++i){
            answer += sum(tree, MAX) - sum(tree, seq[i]);
            update(tree, MAX+1, seq[i], 1);
        }

        cout << answer << "\n";
    }

    return 0;
}
