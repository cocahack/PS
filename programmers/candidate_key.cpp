#include <bits/stdc++.h>
using namespace std;

void solve(set<string>& keys, vector<vector<string>>& relation, int col_idx, int max_len, string combinations, int row, int col)
{
  sort(combinations.begin(), combinations.end());
  if(combinations.size() == max_len) {
    bool unique = true;
    set<string> dic;
    for(int i=0; i<row; ++i) {
      string s = "";
      for (char c : combinations) {
        int idx = c - '0';
        s += relation[i][idx];
      }
      if(dic.find(s) != dic.end()) {
        unique = false;
        break;
      } else {
        dic.insert(s);
      }
    }

    if(unique) {
      bool unique_set = true;
      for (string s : keys) {
        int count = 0;
        for(int j = 0; j < s.size(); ++j) {
          for(int k = 0; k < combinations.size(); ++k) {
            if(s[j] == combinations[k]) {
              count++;
              break;
            }
          }
        }
        if (count == s.size()) {
          unique_set = false;
          break;
        }
      }
      if (unique_set) {
        keys.insert(combinations);
      }
    }
    return;
  }

  if(col_idx >= col) return;

  for(int i=col_idx; i<col; ++i){
    solve(keys, relation, i+1, max_len, combinations + (char)('0' + (char)i), row, col);
  }
}

int solution(vector<vector<string>> relation) {
  int row = relation.size(), col = relation[0].size();
  set<string> combinations;

  for(int i=0; i<col; ++i) {
    solve(combinations, relation, 0, i+1, "", row, col);
  }

  return combinations.size();
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cout << solution(
      {{"100","ryan","music","2"},
       {"200","apeach","math","2"},
       {"300","tube","computer","3"},
       {"400","con","computer","4"},
       {"500","muzi","music","3"},
       {"600","apeach","music","2"}}
      );

  return 0;
}

