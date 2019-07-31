#include <bits/stdc++.h>
using namespace std;

int get_partial_match(const string& s, vector<int>& pi)
{
  int n = s.size();
  int begin = 1, matched = 0;

  while(begin + matched < n) {
    if(s[begin + matched] == s[matched]) {
      ++matched;
      pi[begin+matched-1] = matched;
    } else {
      if(matched == 0) {
        ++begin;
      } else {
        begin += matched - pi[matched-1];
        matched = pi[matched-1];
      }
    }
  }

  return n - matched;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int L;
  string A;
  cin >> L >> A;
  vector<int> pi(L, 0);

  cout << get_partial_match(A, pi);

  return 0;
}

