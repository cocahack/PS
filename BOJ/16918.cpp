#include <bits/stdc++.h>
using namespace std;

int m [201][201]{0,};

void count_down(int r, int c)
{
    for(int i=0; i<r; ++i){
        for(int j=0; j<c; ++j){
            if(m[i][j] != -1){
                m[i][j]--;
            }
        }
    }
}

int dir[4][2] {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

bool check_valid(int y, int x, int r, int c)
{
    return (y < r && y >= 0) && (x < c && x >= 0);
}

void boom(int r, int c)
{
    for(int i=0; i<r; ++i){
        for(int j=0; j<c; ++j){
            if(!m[i][j]){
                for(int k = 0; k < 4; ++k){
                    int y = i+dir[k][0], x = j + dir[k][1];
                    if(check_valid(y, x, r, c)){
                        if(m[y][x]) m[y][x] = -1;
                    }
                }
                m[i][j] = -1;
            }
        }
    }
}


void install_boom(int r, int c)
{
    for(int i=0; i<r; ++i){
        for(int j=0; j<c; ++j){
            if(m[i][j] == -1){
                m[i][j] = 3;
            }
        }
    }
}

void print(int r, int c)
{
    for(int i=0; i<r; ++i){
        for(int j=0; j<c; ++j){
            cout << (m[i][j] == -1 ? '.' : 'O');
        }
        cout << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int r, c, n;
    char tmp;
    cin >> r >> c >> n;
    memset(m, -1, sizeof m);

    for(int i=0; i<r; ++i){
        for(int j=0; j<c; ++j){
            cin >> tmp;
            if(tmp == 'O'){
                m[i][j] = 3;
            }
        }
    }


    for(int i=1; i<=n; ++i){
        if(i % 2 == 1) {
            count_down(r, c);
            boom(r, c);
        }
        else {
            count_down(r, c);
            install_boom(r, c);
        }
    }

    print(r, c);

    return 0;
}
