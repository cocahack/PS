#include <bits/stdc++.h>
using namespace std;
int n, k, l;
int delta[4][2] {1, 0, 0, -1, -1, 0, 0, 1};

int board[101][101]{0,};
int s[101]{0,};
char d[101];
vector<pair<int, int>> snake;
int dir = 3;

bool is_crash(const pair<int, int>& head)
{
  for(auto body : snake) {
    if(body == head) return true;
  }
  return head.first < 1 || head.second < 1 || head.first > n || head.second > n;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> k;
  int y, x;
  for(int i=0; i<k; ++i) {
    cin >> y >> x;
    board[y][x] = 1;
  }
  cin >> l;

  for(int i=0; i<l; ++i) {
    cin >> s[i] >> d[i];
  }

  int l_idx = 0, second = 0;
  snake.push_back({1, 1});

  while(1) {
    ++second;

    auto head = snake.back();

    pair<int, int> new_head = {head.first + delta[dir % 4][0], head.second + delta[dir % 4][1]};
    if(is_crash(new_head)) break;
    snake.push_back(new_head);

    if(board[new_head.first][new_head.second] != 1) {
      snake.erase(snake.begin());
    } else {
      board[new_head.first][new_head.second] = 0;
    }

    // 회전
    if(l_idx < l && second == s[l_idx]) {
      if(d[l_idx] == 'L') {
        dir--;
        if(dir < 0) dir = 3;
      } else {
        dir++;
      }
      l_idx++;
    }
  }

  cout << second;

  return 0;
}
