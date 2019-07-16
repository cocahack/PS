#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, b;

    cin >> n >> b;
    string answer = "";

    while(n){
        int m = n % b;
        if(m >= 10){
            answer.push_back('A' + (m - 10));
        } else {
            answer.push_back('0' + m);
        }

        n /= b;
    }

    reverse(answer.begin(), answer.end());

    cout << answer;

    return 0;

}
