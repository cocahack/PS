#include <bits/stdc++.h>
using namespace std;

int get_partial_match(const string& s, int start_at)
{
  int n = s.size();
  vector<int> pi(n, 0);
  int begin = start_at + 1, matched = 0, ret = 0;

  while(begin + matched < n) {
    if(s[begin + matched] == s[start_at + matched]) {
      ++matched;
      pi[begin+matched-1] = matched;
      ret = max(matched, ret);
    } else {
      if(matched == 0) {
        ++begin;
      } else {
        begin += matched - pi[start_at+matched-1];
        matched = pi[start_at+matched-1];
      }
    }
  }

  return ret;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int ans = 0;
  string s;
  cin >> s;

  for(int i=0; i<s.size(); ++i){
    ans = max(ans, get_partial_match(s, i));
  }

  cout << ans;

  return 0;
}

