include <bits/stdc++.h>
using namespace std;

int n, m, board[51][51];
bool visited[51][51]{0,};

int dir[4][2] = {
    {-1, 0},
    {0, 1},
    {1, 0},
    {0, -1},
};

struct cleaner {
  int y, x, d;
  void turn_left() {
    this->d = (this->d + 3) % 4;
  }
};

bool check_boundary(int y, int x) {
  return y >= 0 && x >= 0 && y < n && x < m;
}

void set_next_location(cleaner c, int& y, int& x) {
  y = y + dir[c.d][0];
  x = x + dir[c.d][1];
}

void set_reverse_next_location(cleaner c, int& y, int& x) {
  y = y - dir[c.d][0];
  x = x - dir[c.d][1];
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cleaner c = cleaner();
  cin >> n >> m >> c.y >> c.x >> c.d;

  for(int i=0; i<n; ++i) for(int j=0; j<m; ++j) cin >> board[i][j];
  bool is_not_ended = true;
  int answer = 0;

  do {
    if(!visited[c.y][c.x]) answer++;
    visited[c.y][c.x] = true;
    int next_y, next_x;

    bool is_forwarded = false;

    for(int i=0; i<4; ++i) {
      c.turn_left();
      next_y = c.y, next_x = c.x;
      set_next_location(c, next_y, next_x);
      if (check_boundary(next_y, next_x) && !visited[next_y][next_x] && !board[next_y][next_x]) {
        set_next_location(c, c.y, c.x);
        is_forwarded = true;
        break;
      }
    }

    if(!is_forwarded) {
      set_reverse_next_location(c, c.y, c.x);
      if(board[c.y][c.x]) is_not_ended = false;
    }

  } while(is_not_ended);

  cout << answer;

  return 0;
}:
