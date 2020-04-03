#include <bits/stdc++.h>
using namespace std;
int N, answer = numeric_limits<int>::max(), board[20][20];
bool team1[20];

void recursion(int curr) {
  if(curr == N) {
    int t1 = 0, t2 = 0;
    for(int i=0; i<N; ++i) {
      if(team1[i]) {
        for (int j = i+1; j < N; ++j) {
          if(team1[j]) t1 += board[i][j] + board[j][i];
        }
      } else {
        for (int j = i+1; j < N; ++j) {
          if(!team1[j]) t2 += board[i][j] + board[j][i];
        }
      }
    }
    answer = min(answer, abs(t1 - t2));
    return;
  }

  team1[curr] = true;
  recursion(curr + 1);
  team1[curr] = false;

  recursion(curr + 1);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N;
  for(int i=0; i<N; ++i) for (int j = 0; j < N; ++j) cin >> board[i][j];

  recursion(0);

  cout << answer;

  return 0;
}

