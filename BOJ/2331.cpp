#include <bits/stdc++.h>
using namespace std;
unordered_set<int> visited;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int a, p;
    cin >> a >> p;
    visited.insert(a);
    vector<int> save;
    save.push_back(a);
    int answer = 0;

    while(1){
        int next_a = 0;
        while(a){
            int m = a % 10;
            int z = 1;
            for(int i=0; i<p; ++i) z *= m;
            next_a += z;
            a /= 10;
        }
        if(visited.find(next_a) != visited.end()) {
            for(int i=0; i<save.size(); ++i){
                if(save[i] == next_a) break;
                answer++;
            }
            break;
        }
        visited.insert(next_a);
        save.push_back(next_a);
        a = next_a;
    }

    cout << answer;


    return 0;
}
