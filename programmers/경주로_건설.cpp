#include<bits/stdc++.h>
using namespace std;

int delta[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
int d8[8][2] = {-1, -1, -1, 0, -1, 1, 0, -1, 0, 1, 1, -1, 1, 0, 1, 1};

inline bool check_boundary(int y, int x, int y_max, int x_max) {
    return y >= 0 && y < y_max && x >= 0 && x < x_max;
}
// Snippets area end.


int cost[25][25]{0,};

struct Node {
    int y, x, d, c;
    bool operator < (const Node& rhs) const {
        if (c != rhs.c) return c < rhs.c;
        if (y != rhs.y) return y < rhs.y;
        if (x != rhs.x) return x < rhs.x;
        return d < rhs.d;
    }
    Node(int _y, int _x, int _d, int _c): y(_y), x(_x), d(_d), c(_c){}
};

inline bool check_opposite(int src_d, int dest_d) {
    switch (src_d) {
        case 0:
            return dest_d == 2;
        case 1:
            return dest_d == 3;
        case 2:
            return dest_d == 0;
        case 3:
            return dest_d == 1;
    }
    return true;
}

int solution(vector<vector<int>> board) {
    int answer = numeric_limits<int>::max();
    int len = board.size();

    memset(cost, -1, sizeof cost);

    priority_queue<Node> q;
    q.push(Node(0, 0, 1, 0));
    q.push(Node(0, 0, 2, 0));

    while(q.size()) {
        auto n = q.top();
        q.pop();

        int y = n.y, x = n.x, d = n.d, c = n.c;
        
        if(!(cost[y][x] == -1 || n.c <= cost[y][x])) {
            continue;
        }
        
        cost[y][x] = c;

        if(y == len - 1 && x == len - 1) {
            answer = min(answer, cost[y][x]);
            continue;
        }
        
        for(int i=0; i<4; ++i) {
            if(check_opposite(d, i)) continue;
            
            int dy = y + delta[i][0], dx = x + delta[i][1];
            if(check_boundary(dy, dx, len, len) && board[y][x] != 1) {
                q.push(Node(dy, dx, i, cost[y][x] + 100 + (d == i ? 0 : 500)));
            }
        }
    }

    return answer;
}

