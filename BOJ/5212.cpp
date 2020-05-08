#include <bits/stdc++.h>
using namespace std;

int delta[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
vector<string> board;
int r, c;
bool is_sea(int y, int x) {
    return y < 0 || y >= r || x < 0 || x >= c || board[y][x] == '.';
}

bool check(int y, int x) {
    int ny, nx, cnt = 0;
    for(int i=0; i<4; ++i) {
        ny = y + delta[i][0], nx = x + delta[i][1];
        if(is_sea(ny, nx)) cnt++;
    }
    return cnt >= 3;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> r >> c;
    board = vector<string>(r);

    for(int i=0; i<r; ++i) cin >> board[i];

    vector<int> yp, xp;

    for(int y=0; y<r; ++y) {
        for(int x=0; x<c; ++x) {
            if(board[y][x] == 'X') {
                if(check(y, x)) {
                    board[y][x] = 'x';
                }
                else {
                    yp.push_back(y);
                    xp.push_back(x);
                }
            }
        }
    }

    sort(yp.begin(), yp.end());
    sort(xp.begin(), xp.end());

    int sy = *yp.begin(), ey = *yp.rbegin(), sx = *xp.begin(), ex = *xp.rbegin();

    for(int y = sy; y <= ey; ++y) {
        string s(ex - sx + 1, '.');
        for(int x = sx; x <= ex; ++x) {
            if(board[y][x] == 'X') s[x-sx] = 'X';
        }
        cout << s << "\n";
    }

    return 0;
}

