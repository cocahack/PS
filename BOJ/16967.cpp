#include <bits/stdc++.h>
using namespace std;

int arr[602][602]{0,};
int real_arr[301][301]{0,};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int h, w, x, y, i, j;
    cin >> h >> w >> x >> y;

    for(i=0; i<h+x; ++i) for(j=0; j<w+y; ++j) cin >> arr[i][j];

    for(i=0; i<x; ++i){
        for(j=0; j<w; ++j){
            real_arr[i][j] = arr[i][j];
        }
    }

    for(i=x; i<h; ++i){
        for(j=0; j<y; ++j){
            real_arr[i][j] = arr[i][j];
        }
    }

    for(i=x; i<h; ++i){
        for(j=w; j<w+y; ++j){
            real_arr[i-x][j-y] = arr[i][j];
        }
    }

    for(i=h; i<h+x; ++i){
        for(j=y; j<w+y; ++j){
            real_arr[i-x][j-y] = arr[i][j];
        }
    }

    for(i=x; i<h; ++i){
        for(j=y; j<w; ++j){
            if(!real_arr[i][j])
                real_arr[i][j] = arr[i][j] - real_arr[i-x][j-y];
        }
    }

    for(i=0; i<h; ++i) {
        for (j = 0; j < w; ++j) {
            cout << real_arr[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
