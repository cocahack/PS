#include <iostream>
using namespace std;

struct Dice {
  int plain[6]{0, 0, 0, 0, 0, 0};
  void rolling(int dir) {
    if(dir == 1) {
      int temp = plain[0];
      plain[0] = plain[1];
      plain[1] = plain[5];
      plain[5] = plain[2];
      plain[2] = temp;
    } else if(dir == 2) {
      int temp = plain[0];
      plain[0] = plain[2];
      plain[2] = plain[5];
      plain[5] = plain[1];
      plain[1] = temp;
    } else if (dir == 4) {
      int temp = plain[0];
      plain[0] = plain[4];
      plain[4] = plain[5];
      plain[5] = plain[3];
      plain[3] = temp;
    } else if (dir == 3) {
    int temp = plain[0];
    plain[0] = plain[3];
    plain[3] = plain[5];
    plain[5] = plain[4];
    plain[4] = temp;
    }
  }
};

int map[21][21]{0,};
int n, m, y, x, k;

int delta[5][2] {
  0, 0,
  0, 1,
  0, -1,
  -1, 0,
  1, 0,
};

bool is_valid(int _y, int _x)
{
  return _y >= 0 && _y < n && _x >= 0 && _x < m;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m >> y >> x >> k;

  for(int i=0; i<n; ++i) {
    for(int j=0; j<m; ++j) {
      cin >> map[i][j];
    }
  }

  int dir;
  Dice d;
  while(k--){
    cin >> dir;
    int next_y = y + delta[dir][0], next_x = x + delta[dir][1];
    if(!is_valid(next_y, next_x)) continue;
    y = next_y , x = next_x;

    d.rolling(dir);

    if(map[y][x]) {
      d.plain[0] = map[y][x];
      map[y][x] = 0;
    } else {
      map[y][x] = d.plain[0];
    }

    cout << d.plain[5] << "\n";
  }

  return 0;
}
