#include <bits/stdc++.h>
#define for2d(out, in) for(int i=0; i<out; ++i) for(int j=0; j<in; ++j)
using namespace std;
int board[128][128]{0,};
int white = 0, blue = 0;

void count_up(int value)
{
  if(value == 1) blue++;
  else if(value == 0) white++;
}

void quad_tree(int y, int x, int len)
{
  if(len == 1) {
    count_up(board[y][x]);
    return ;
  }

  bool all_same = true;
  int half = len / 2, target = board[y][x];
  for(int i = y; i < y + len; ++i) {
    for(int j = x; j < x + len; ++j) {
      if(target != board[i][j]) {
        all_same = false;
        break;
      }
    }
  }

  if(all_same) {
    count_up(target);
  } else {
    quad_tree(y, x, half);
    quad_tree(y , x + half, half);
    quad_tree(y + half, x, half);
    quad_tree(y + half, x + half, half);
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  for2d(n, n) cin >> board[i][j];

  quad_tree(0, 0, n);

  cout << white << "\n" << blue;

  return 0;
}

