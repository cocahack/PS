#include <bits/stdc++.h>
using namespace std;
class Board
{
public:
    vector<vector<int>> state;
    pair<int, int> starting;
    bool operator == (const Board& b) const
    {
        return state == b.state;
    }
    bool operator < (const Board& b) const
    {
        return state < b.state;
    }
    Board(){ state.resize(9, vector<int>(9,0)); starting = make_pair(0, 0);}
    void set(int y, int x, int n)
    {
        state[y][x] = n;
    }
    void unset(int y, int x)
    {
        state[y][x] = 0;
    }
    int get(int y, int x) { return state[y][x];}

    void set_starting(int y, int x){ starting.first = y, starting.second = x;}

    void set_next_starting()
    {
        for(int i=0; i<9; ++i){
            for(int j=0; j<9; ++j){
                if(state[i][j] == 0){
                    starting.first = i;
                    starting.second = j;
                    return;
                }
            }
        }
        starting.first = -1;
    }
};
bool valid_position(int y, int x)
{
    return (y >= 0 && y < 9) && (x >= 0 && x < 9);
}

Board b;
Board best;
bool dominos[10][10];
bool chkr[10][10];
bool chkc[10][10];
bool chks[10][10];
bool finish = false;

void print()
{
    for(int i=0; i<9; ++i){
        for(int j=0; j<9; ++j){
            cout << best.state[i][j];
        }
        cout << "\n";
    }
}

bool is_valid(int y, int x, int v)
{
    return !(chkr[y][v] || chkc[x][v] || chks[3*(y/3)+x/3][v]);
}

void set_chk(int y, int x, int v, int b)
{
    chkr[y][v] = b;
    chkc[x][v] = b;
    chks[3*(y/3)+x/3][v] = b;
}

void solve()
{
    if(finish) return;
    if(b.starting.first == -1 ){
        best = b;
        finish = true;
        return;
    }

    int y = b.starting.first, x = b.starting.second;

    for(int i=1; i<=9; ++i){
        for(int j=1; j<=9; ++j){
            if(i == j || (dominos[i][j] || dominos[j][i])) continue;
            for(int dir = 0; dir < 2; ++dir){
                int next_y = y + (dir == 0 ? 1 : 0), next_x = x + (dir == 0 ? 0 : 1);
                if (valid_position(next_y, next_x) && !b.get(next_y, next_x)) {
                    b.set(y, x, i);
                    b.set(next_y, next_x, j);
                    if (is_valid(y, x, i) && is_valid(next_y, next_x, j)) {
                        dominos[i][j] = true;
                        set_chk(y, x, i, true);
                        set_chk(next_y, next_x, j, true);
                        b.set_next_starting();
                        solve();
                        b.set_starting(y, x);
                        set_chk(y, x, i, false);
                        set_chk(next_y, next_x, j, false);
                        dominos[i][j] = false;
                    }
                    b.unset(y, x);
                    b.unset(next_y, next_x);
                }
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, v1, v2, i, t = 1, y, x;
    string s;
    while(1) {
        cin >> n;
        if(n == 0) break;
        b = Board{};
        best = Board{};
        memset(dominos, 0, sizeof dominos);
        memset(chkc, 0, sizeof chkc);
        memset(chkr, 0, sizeof chkr);
        memset(chks, 0, sizeof chks);
        finish = false;
        while (n--) {
            cin >> v1 >> s;
            y = s[0] - 'A', x = s[1]-'1';
            b.set(y, x, v1);
            set_chk(y, x, v1, true);
            cin >> v2 >> s;
            y = s[0] - 'A', x = s[1]-'1';
            b.set(y, x, v2);
            set_chk(y, x, v2, true);
            dominos[v1][v2] = true;
        }
        for (i = 1; i <= 9; ++i) {
            cin >> s;
            y = s[0] - 'A', x = s[1]-'1';
            b.set(y, x, i);
            set_chk(y, x, i, true);
        }

        b.set_next_starting();
        solve();

        cout << "Puzzle " << t << "\n";
        print();
        ++t;
    }
    return 0;
}
