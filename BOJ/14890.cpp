#include <bits/stdc++.h>
using namespace std;

int N, L, board[100][100];

bool check_left_to_right(int num) {
  int y = num;
  bool slope[N];
  memset(slope, 0, sizeof slope);
  for (int i = 1; i < N;) {

    if (board[y][i-1] == board[y][i] ) { i++; continue; }
    if (abs(board[y][i-1] - board[y][i]) > 1) return false;

    if(board[y][i-1] < board[y][i]) {

      for (int j = i - 1; j >= i - L; --j) {
        if(j < 0 || abs(board[y][j] - board[y][i]) != 1 || slope[j] ) return false;
      }

      for (int j = i - 1; j >= i - L; --j) {
        slope[j] = true;
      }

      i++;
    }

    else {

      for(int j = i; j < i + L; ++j) {
        if(j >= N || abs(board[y][j] - board[y][i-1]) != 1 ) return false;
      }

      for(int j = i; j < i + L; ++j) {
        slope[j] = true;
      }

      i += L;
    }
  }

  return true;
}

bool check_up_to_down(int num) {
  int x = num;
  bool slope[N];
  memset(slope, 0, sizeof slope);
  for (int i = 1; i < N;) {

    if (board[i-1][x] == board[i][x] ) { i++; continue; }
    if (abs(board[i-1][x] - board[i][x]) > 1) return false;

    if(board[i-1][x] < board[i][x]) {

      for (int j = i - 1; j >= i - L; --j) {
        if(j < 0 || abs(board[j][x] - board[i][x]) != 1 || slope[j] ) return false;
      }

      for (int j = i - 1; j >= i - L; --j) {
        slope[j] = true;
      }

      i++;
    }

    else {

      for(int j = i; j < i + L; ++j) {
        if(j >= N || abs(board[j][x] - board[i-1][x]) != 1 ) return false;
      }

      for(int j = i; j < i + L; ++j) {
        slope[j] = true;
      }

      i += L;
    }
  }

  return true;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N >> L;
  for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) cin >> board[i][j];

  int answer = 0;

  for(int i=0; i<N; ++i) {
    answer += check_left_to_right(i);
    answer += check_up_to_down(i);
  }

  cout << answer;

  return 0;
}

