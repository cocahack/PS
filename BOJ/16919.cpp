#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> m, even;
deque<vector<vector<int>>> map_container;
deque<int> when_inserted;

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

void print(int r, int c, vector<vector<int>>& mm)
{
    for(int i=0; i<r; ++i){
        for(int j=0; j<c; ++j){
            cout << (mm[i][j] == -1 ? '.' : 'O');
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
    m = vector<vector<int>>(r, vector<int>(c, -1));
    even = m;

    for(int i=0; i<r; ++i){
        for(int j=0; j<c; ++j){
            cin >> tmp;
            if(tmp == 'O'){
                m[i][j] = 3;
            }
        }
    }

    for(int i=1; i<=100001; ++i){
        if(i % 2 == 1) {
            count_down(r, c);
            boom(r, c);
            bool new_map = true;
            int j;
            for(j = 0; j < map_container.size(); ++j){
                if(map_container[j] == m) new_map = false;
                if(!new_map) break;
            }
            if(!new_map){
                loop_start = when_inserted[j];
                while(j--){
                    map_container.pop_front();
                    when_inserted.pop_front();
                }
                break;
            }
            else{
                map_container.push_back(m);
                when_inserted.push_back(i);
            }
        }
        else {
            count_down(r, c);
            install_boom(r, c);
            even = m;
        }

        if(n == i){
            print(r, c, m);
            exit(0);
        }
    }

    int all_minus = when_inserted[0] - 1;
    for(int i=0; i<when_inserted.size(); ++i) {
        when_inserted[i] -= all_minus;
    }
    n -= all_minus;

    if(n % 2 == 0) print(r, c, even);
    else{
        int gap = when_inserted.size() * 2;
        for(int i=0; i < when_inserted.size(); ++i){
            if((n - when_inserted[i]) % gap == 0){
                print(r, c, map_container[i]);
                break;
            }
        }
    }
    return 0;
}
