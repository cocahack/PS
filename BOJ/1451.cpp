#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll sums[100][100]{0,};
vector<string> board;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N, M;
  cin >> N >> M;

  string tmp;
  for(int i=0; i<N; ++i){
    cin >> tmp;
    board.push_back(tmp);
  }

for(int i=0; i<N; ++i){
    for(int j=0; j<M; ++j){
      ll cur = board[i][j] - '0';
      if(i == 0){
        sums[i][j] = j == 0 ? cur : cur + sums[i][j-1];
      } else if(j == 0){
        sums[i][j] = i == 0 ? cur : cur + sums[i-1][j];
      } else {
        sums[i][j] = cur + sums[i-1][j] + sums[i][j-1] - sums[i-1][j-1];
      }
    }
  }

  ll answer = 0, first, second, third;
  for(int i=1; i<N; ++i){
    for(int j=1; j<M; ++j){
      // first case
      first = sums[N-1][j-1];
      second = sums[i-1][M-1] - sums[i-1][j-1];
      third = sums[N-1][M-1] - first - second;

      answer = max(answer, first * second * third);

      //second case
      first = sums[i-1][j-1];
      second = sums[N-1][j-1] - first;
      third = sums[N-1][M-1] - first - second;

      answer = max(answer, first * second * third);

      // third case
      first = sums[i-1][M-1];
      second = sums[N-1][j-1] - sums[i-1][j-1];
      third = sums[N-1][M-1] - first - second;

      answer = max(answer, first * second * third);

      // fourth case
      first = sums[i-1][j-1];
      second = sums[i-1][M-1] - sums[i-1][j-1];
      third = sums[N-1][M-1] - first - second;

      answer = max(answer, first * second * third);
    }
  }

  for(int i=1; i<N-1; ++i){
    for(int j=i+1; j<N; ++j){
      first = sums[i-1][M-1];
      second = sums[j-1][M-1] - first;
      third = sums[N-1][M-1] - first - second;

      answer = max(answer, first * second * third);
    }
  }


  for(int i=1; i<M-1; ++i){
    for(int j=i+1; j<M; ++j){
      first = sums[N-1][i-1];
      second = sums[N-1][j-1] - first;
      third = sums[N-1][M-1] - first - second;

      answer = max(answer, first * second * third);
    }
  }


  cout << answer;


  return 0;
}
