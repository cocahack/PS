#include <bits/stdc++.h>>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> cache(n+1, numeric_limits<int>::max());
    cache[n] = 0;

    queue<int> q;
    q.push(n);

    while(q.size()){
        auto num = q.front();
        q.pop();
        if(num < 1) continue;
        if(num == 1) break;
        int next_val = cache[num] + 1, next;

        if(num % 3 == 0 && num / 3 > 0) {
            next = num / 3;
            cache[next] = min(cache[next], next_val);
            q.push(next);
        }

        if(num % 2 == 0 && num / 2 > 0){
            next = num / 2;
            cache[next] = min(cache[next], next_val);
            q.push(next);
        }

        if(num - 1 > 0){
            next = num - 1;
            cache[next] = min(cache[next], next_val);
            q.push(next);
        }
}

    cout << cache[1];

    return 0;
}
