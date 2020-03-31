#include <bits/stdc++.h>

using namespace std;

vector<string> suspect_lists[8];
int answer = 0;
unordered_set<string> answer_list;

void update_suspect_lists(const vector<string>& user_id, const vector<string>& banned_id) {
  for(int i=0; i<banned_id.size(); ++i) {

    for(auto user : user_id) {
      if(user.size() != banned_id[i].size()) continue;

      bool correct = true;
      for(int j=0; j<user.size(); ++j) {
        if(user[j] != banned_id[i][j] && banned_id[i][j] != '*') {
          correct = false;
          break;
        }
      }

      if(correct) {
        suspect_lists[i].push_back(user);
      }

    }

  }
}

void dfs(const vector<string>& user_id, int size, vector<bool>& used_list, int curr) {
  if(curr == size) {
    string s;
    for(int i=0; i<used_list.size(); ++i) {
      if(used_list[i]) {
        s += (char)(i + '0');
      }
    }
    if(answer_list.find(s) == answer_list.end()) {
      answer_list.insert(s);
      answer++;
    }
    return;
  }

  bool visited[8]{0,};

  for(auto suspect : suspect_lists[curr]) {

    for (int i = 0; i < user_id.size(); ++i) {
      if(suspect == user_id[i]) {

        if(!used_list[i] && !visited[i]) {
          used_list[i] = true;
          visited[i] = true;
          dfs(user_id, size, used_list, curr+1);
          used_list[i] = false;
        }

      }
    }

  }

}

int solution(vector<string> user_id, vector<string> banned_id) {
  sort(user_id.begin(), user_id.end());
  update_suspect_lists(user_id, banned_id);

  vector<bool> used_list(user_id.size(), false);
  dfs(user_id, banned_id.size(), used_list, 0);

  return answer;
}

