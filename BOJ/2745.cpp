#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string n;
    ll b, base = 1, answer = 0;

    cin >> n >> b;
    reverse(n.begin(), n.end());

    for(int i = 0; i < n.size(); ++i){
        base = i ? base * b : 1;
        int k = n[i] >= 'A' ? n[i] - 'A' + 10 : n[i] - '0';
        answer += base * k;
    }

    cout << answer;

    return 0;
}
