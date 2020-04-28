#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, L, C;
    cin >> N >> L >> C;
    
    int contains = (C-L)/(L+1) + 1;
    if(contains % 13 == 0) contains--;
    int answer = N / contains, remains = N % contains;
    if (remains) {
        if(remains % 13 == 0) {
            if (!((remains + 1) * L <= C && answer && (contains - 1) % 13 != 0)) {
                answer++;
            }
        }
        answer++;
    }

    cout << answer;

    return 0;
}

