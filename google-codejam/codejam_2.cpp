#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;
vector<vector<char>> footprint;
vector<vector<bool>> can_reach;

void init_footprint(const string l)
{
    int y = 0, x = 0;
    for(char d : l){
        footprint[y][x] = d;
        if(d == 'S'){
            ++y;
        } else {
            ++x;
        }
    }
}

void dfs(const int n,
         string& ret,
         int y,
         int x,
         char d,
         bool& finished)
{
    if(x == n || y == n) return;
    if(x == n-1 && y == n-1){
        finished = true;
        ret += d;
        return;
    }
    if(finished){
        ret += d;
        return;
    }
    if(!can_reach[y][x]) return;

    char l_d = footprint[y][x];
    if(l_d == 'S'){
        dfs(n, ret, y, x+1, 'E', finished);
        if (finished) {
            ret += d;
            return;
        }
    } else if(l_d == 'E'){
        dfs(n, ret, y+1, x, 'S', finished);
        if (finished) {
            ret += d;
            return;
        }
    }
    else {
        dfs(n, ret, y, x + 1, 'E', finished);
        if (finished) {
            ret += d;
            return;
        }
        dfs(n, ret, y + 1, x, 'S', finished);
        if (finished) {
            ret += d;
            return;
        }
    }
    can_reach[y][x] = false;
}

string solution(const int n)
{
    string ret = "";
    bool finished = false;

    dfs(n, ret, 0, 0, 'a', finished);
    ret.pop_back();
    reverse(ret.begin(), ret.end());

    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n, c = 1;
    string l;
    cin >> t;
    while(t--){
        cin >> n;
        cin >> l;
        footprint = vector<vector<char>>(n+1, vector<char>(n+1, 0));
        can_reach = vector<vector<bool>>(n+1, vector<bool>(n+1, 1));
        init_footprint(l);
        cout << "Case #"
             << c
             << ": "
             << solution(n)
             << "\n";
        ++c;
    }

    return 0;
}
