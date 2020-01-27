#include <bits/stdc++.h>
using namespace std;

int n, m;
int board[500][500];

int tetromino[19][4][2] = {
    { {0,0}, {0,1}, {1,0}, {1,1} },
    { {0,0}, {0,1}, {0,2}, {0,3} },
    { {0,0}, {1,0}, {2,0}, {3,0} },
    { {0,0}, {1,0}, {1,1}, {2,1} },
    { {1,0}, {1,1}, {0,1}, {0,2} },
    { {0,0}, {1,0}, {2,0}, {2,1} },
    { {0,0}, {1,0}, {0,1}, {0,2} },
    { {1,0}, {1,1}, {1,2}, {0,2} },
    { {0,0}, {0,1}, {1,1}, {2,1} },
    { {0,0}, {0,1}, {0,2}, {1,1} },
    { {1,0}, {0,1}, {1,1}, {2,1} },
    { {0,0}, {1,0}, {2,0}, {1,1} },
    { {1,0}, {1,1}, {1,2}, {0,1} },
    { {2,0}, {0,1}, {1,1}, {2,1} },
    { {0,0}, {0,1}, {0,2}, {1,2} },
    { {0,0}, {0,1}, {1,0}, {2,0} },
    { {0,0}, {1,0}, {1,1}, {1,2} },
    { {1,0}, {2,0}, {0,1}, {1,1} },
    { {0,0}, {0,1}, {1,1}, {1,2} },
};

inline bool check_boundary(int y, int x)
{
  return y >= 0 && x >= 0 && y < n && x < m;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;
  int answer = 0;

  for(int i=0; i<n; ++i) for(int j=0; j<m; ++j) cin >> board[i][j];

  for(int i=0; i<n; ++i){
    for(int j=0; j<m; ++j) {
      for(int k=0; k<19; ++k) {
        int loc_answer = 0;
        bool valid = true;
        for(int l=0; l<4; ++l) {
          int y = i + tetromino[k][l][0], x = j + tetromino[k][l][1];
          if(!check_boundary(y, x)) {
            valid = false;
            break;
          }
          loc_answer += board[y][x];
        }
        if(valid) {
          answer = max(answer, loc_answer);
        }
      }
    }
  }

  cout << answer;

  return 0;
}
