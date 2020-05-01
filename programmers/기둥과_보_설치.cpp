#include <string>
#include <vector>

using namespace std;

bool fs[101][101]{0,};
bool ps[101][101]{0,};
int N;
bool can_build_b(int y, int x);
bool can_build_p(int y, int x);
bool can_remove_b(int y, int x);
bool can_remove_p(int y, int x);

inline bool is_exist_left_b(int y, int x) {
    return x - 1 >= 0 && fs[y][x-1];
}

inline bool is_exist_right_b(int y, int x) {
    return x + 1 < N && fs[y][x+1];
}

inline bool is_exist_left_p(int y, int x) {
    return y-1 >= 0 && ps[y-1][x];
}

inline bool is_exist_right_p(int y, int x) {
    return y-1 >= 0 && ps[y-1][x+1];
}

bool can_build_b(int y, int x) {
    bool left_b = is_exist_left_b(y, x);
    bool right_b = is_exist_right_b(y, x);
    return (left_b && right_b)
           || is_exist_left_p(y, x)
           || is_exist_right_p(y, x);
}

bool can_remove_b(int y, int x) {
    fs[y][x] = false;
    bool left_b = x - 1 >= 0 && fs[y][x-1] ? can_build_b(y, x-1) : true;
    bool right_b = x + 1 < N && fs[y][x+1] ? can_build_b(y, x+1) : true;
    bool left_p = ps[y][x] ? can_build_p(y, x) : true;
    bool right_p = x + 1 < N && ps[y][x+1] ? can_build_p(y, x+1) : true;

    bool ret = left_b && right_b && left_p && right_p;
    fs[y][x] = true;
    return ret;
}

bool can_build_p(int y, int x) {
    bool left_b = x - 1 >= 0 ? fs[y][x-1] : false;
    bool right_b = fs[y][x];
    return y == 0 || left_b || right_b || ps[y-1][x];
}

bool can_remove_p(int y, int x) {
    ps[y][x] = false;
    bool left_b = x - 1 >= 0 && fs[y+1][x-1]? can_build_b(y+1, x-1) : true;
    bool right_b = fs[y+1][x] ? can_build_b(y+1, x) : true;
    bool up_p = ps[y+1][x] ? can_build_p(y+1, x) : true;

    bool ret = up_p && left_b && right_b;
    ps[y][x] = true;
    return ret;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    N = n;

    for(auto frame : build_frame) {
        bool is_b = frame[2], c = frame[3];
        int y = frame[1], x = frame[0];
        if(c) {
            if(is_b) {
                fs[y][x] = can_build_b(y, x);
            } else {
                ps[y][x] = can_build_p(y, x);
            }
        } else {
            if(is_b) {
                fs[y][x] ^= can_remove_b(y, x);
            } else {
                ps[y][x] ^= can_remove_p(y, x);
            }
        }
    }

    for(int x=0; x<=n; ++x) {
        for(int y=0; y<=n; ++y) {
            if(ps[y][x]) {
                answer.push_back({x, y, 0});
            }
            if(fs[y][x]) {
                answer.push_back({x, y, 1});
            }
        }
    }

    return answer;
}

