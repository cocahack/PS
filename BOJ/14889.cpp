#include <bits/stdc++.h>
using namespace std;

int board[20][20]{0,}, N, answer = numeric_limits<int>::max();
bool team[20];

void update_answer() {
  int start = 0, link = 0;

  for(int i=0; i<N; ++i) {
    if(team[i]) {
      for(int j=i+1; j<N; ++j) {
        if(team[j]) {
          start += board[i][j] + board[j][i];
        }
      }
    } else {
      for(int j=i+1; j<N; ++j) {
        if(!team[j]) {
          link += board[i][j] + board[j][i];
        }
      }
    }
  }

  answer = min(answer, abs(start - link));
}

void recur(int idx, int selected) {
  if(selected == N / 2) {
    update_answer();
    return;
  }

  for (int i = idx; i < N; ++i) {
    team[i] = true;
    recur(i+1, selected+1);
    team[i] = false;
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N;
  for(int i=0; i<N; ++i) for(int j=0; j<N; ++j) cin >> board[i][j];

  recur(0, 0);

  cout << answer;
  return 0;
}

