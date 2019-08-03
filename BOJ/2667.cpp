#include <bits/stdc++.h>
using namespace std;
vector<string> board;
int n, delta[4][2] = {-1, 0, 0, -1, 1, 0, 0, 1};
bool visited[25][25]{0,};
vector<int> answers;

inline bool check_boundary(int y, int x)
{
  return y >= 0 && y < n && x >= 0 && x < n;
}

int dfs(int y, int x)
{
  if(visited[y][x] || !check_boundary(y, x) || board[y][x] == '0') return 0;

  visited[y][x] = true;
  int ret = 1;
  for(int i=0; i<4; ++i){
    ret += dfs(y + delta[i][0], x + delta[i][1]);
  }

  return ret;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  board = vector<string>(n);
  for(int i=0; i<n; ++i) cin >> board[i];

  for(int i=0; i<n; ++i) {
    for (int j = 0; j < n; ++j) {
      if(!visited[i][j] && board[i][j] == '1'){
        int answer = dfs(i, j);
        answers.push_back(answer);
      }
      visited[i][j] = true;
    }
  }

  sort(answers.begin(), answers.end());

  cout << answers.size() << "\n";
  for(auto a : answers) {
    cout << a << "\n";
  }

  return 0;
}

