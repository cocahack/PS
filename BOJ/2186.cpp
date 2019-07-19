#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int MAX = 100;
vector<string> board;
string word;
int N, M, K;

ll cache[MAX][MAX][MAX]{0,};

inline bool check_boundary(int y, int x)
{
  return y >= 0 && y < N && x >= 0 && x < M;
}

ll solve(int y, int x, int idx)
{
  if(!check_boundary(y, x)) return 0;
  if(board[y][x] != word[idx]) return 0;

  ll& ret = cache[y][x][idx];
  if(ret != -1) return ret;
  ret = 0;

  int next_idx = idx + 1;
  if(next_idx == word.size()) return ret = 1;

  for(int i=1; i<=K; ++i){
    ret += solve(y + i, x, next_idx);
    ret += solve(y - i, x, next_idx);
    ret += solve(y, x + i, next_idx);
    ret += solve(y, x - i, next_idx);
  }

  return ret;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N >> M >> K;
  board = vector<string>(N);
  for(int i = 0; i < N; ++i){
    cin >> board[i];
  }

  cin >> word;

  memset(cache, -1, sizeof cache);
  ll answer = 0;

  for(int i=0; i<N; ++i){
    for(int j=0; j<M; ++j){
      if(board[i][j] == word[0]){
        answer += solve(i, j, 0);
      }
    }
  }

  cout << answer;

  return 0;
}
