#include <bits/stdc++.h>

using namespace std;

vector<int> sets[500];
int set_number = 0;

int make_integer(const string& s, int start, int& end) {
  int ret = 0;

  for (int i = start; i < s.size(); ++i) {
    if(s[i] == '}' || s[i] == ',') {
      end = i;
      break;
    }
    ret = ret * 10 + (s[i] - '0');
  }

  return ret;
}

void parsing(const string& s) {

  int end = 0, el;
  for(int i = 1; i < s.size() - 1; ) {
    if (s[i] == '{' || s[i] == ',') {
      el = make_integer(s, i+1, end);
      sets[set_number].push_back(el);
      i = end;
    } else {
      // s[i] == '}'
      i += 2;
      set_number++;
    }
  }
}

bool sort_algorithm(const vector<int>& lhs, const vector<int>& rhs) {
  return lhs.size() < rhs.size();
}

vector<int> solution(string s) {
  vector<int> answer;
  parsing(s);

  sort(sets, sets+set_number, sort_algorithm);

  answer.push_back(sets[0][0]);
  unordered_set<int> h;
  h.insert(answer[0]);
  for(int i=1; i<set_number; ++i) {
    for(int j=0; j < sets[i].size(); ++j) {
      if(h.find(sets[i][j]) == h.end()) {
        h.insert(sets[i][j]);
        answer.push_back(sets[i][j]);
        break;
      }
    }
  }

  return answer;
}

