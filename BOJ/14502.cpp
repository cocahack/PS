#include <bits/stdc++.h>
using namespace std;

int N, M;
int board[8][8];
int delta[4][2]{-1, 0, 0, -1, 0, 1, 1, 0};

bool check_possible(int y, int x)
{
  return y >= 0 && y < N && x >= 0 && x < M;
}

int check_helper(vector<vector<bool>>& visited, int y, int x)
{
  queue<int> q;
  q.push(y*M+x);
  int ret = 0;

  while(q.size()){
    auto n = q.front();
    q.pop();
    int ny = n / M, nx = n % M;

    if(visited[ny][nx]) continue;
    visited[ny][nx] = true;

    for(int i=0; i<4; ++i){
      int dy = ny + delta[i][0], dx = nx + delta[i][1];
      if(check_possible(dy, dx) && board[dy][dx] == 0) q.push(dy * M + dx);
    }

    ret++;
  }
  return ret;
}

int check()
{
  vector<vector<bool>> visited(N, vector<bool>(M, false));
  int ret = N * M;
  for(int i=0; i<N; ++i){
    for(int j=0; j<M; ++j){
      if(board[i][j] == 2) {
        ret -= check_helper(visited, i, j);
        visited[i][j] = true;
      }
      else if(board[i][j] == 1) {
        ret--;
        visited[i][j] = true;
      }
    }
  }

  return ret;
}

int solve(vector<int>& walls)
{
  for(auto w : walls){
    int y = w / M, x = w % M;
    board[y][x] = 1;
  }

  int ret = check();

  for(auto w : walls){
    int y = w / M, x = w % M;
    board[y][x] = 0;
  }

  return ret;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N >> M;
  int n = N * M;
  for(int i=0; i<N; ++i) for(int j=0; j<M; ++j) cin >> board[i][j];

  std::vector<bool> v(n);
  std::fill(v.end() - 3, v.end(), true);

  int answer = 0;
  do {
    vector<int> walls;
    bool possible = true;
    for (int i = 0; i < n; ++i) {
      if(!possible) break;
      if (v[i]) {
        if(board[i/M][i%M]){
          possible = false;
        }
        walls.push_back(i);
      }
    }
    if(possible) answer = max(answer, solve(walls));
  } while (std::next_permutation(v.begin(), v.end()));

  cout << answer;

  return 0;
}
