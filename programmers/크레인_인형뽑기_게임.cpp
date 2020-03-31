#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
  stack<int> lanes[board[0].size()];

  for(int i = board.size()-1 ; i >= 0; --i) {
    for(int j = 0; j<board[0].size(); ++j) {
      if(board[i][j]) {
        lanes[j].push(board[i][j]);
      }
    }
  }

  stack<int> bucket;

  int answer = 0;

  for(int m : moves) {
    if(lanes[m-1].size()){
      int doll = lanes[m-1].top();
      lanes[m-1].pop();

      if (bucket.size() && bucket.top() == doll) {
        bucket.pop();
        answer += 2;
      } else {
        bucket.push(doll);
      }
    }
  }

  return answer;
}


