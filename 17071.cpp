#include <bits/stdc++.h>
using namespace std;
constexpr int MAX = 500'000;
struct Node{
    int m;
    int c;
    Node(int cur, int move){ c = cur, m =move ;}
};
int cache[2][MAX+1];

inline int seqsum(int n) { return n * (n + 1) / 2; }

int solution(int n, int k){
    queue<Node> q;
    q.push(Node(n, 0));
    int answer = -1;
    while (q.size()){
        Node node = q.front();
        q.pop();
        int mod2 = node.m % 2;
        if(node.c < 0 || node.c > MAX ) continue;
        if(cache[mod2][node.c] != -1) continue;
        cache[mod2][node.c] = node.m;

        q.push(Node(node.c - 1, node.m + 1));
        q.push(Node(node.c + 1, node.m + 1));
        q.push(Node(node.c * 2, node.m + 1));
    }

    int sum, i = 0;

    while(1){
        sum = k + seqsum(i);
        if(sum > MAX) break;

        if(cache[i%2][sum] != -1 && cache[i%2][sum] <= i){
            answer = i;
            break;
        }

        ++i;
    }

    return answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    memset(cache, -1, sizeof cache);
    cout << solution(n, k);

    return 0;
}
