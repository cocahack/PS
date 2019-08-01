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

int kmp(const vector<int> pi, const string& H, const string& N)
{
  int h = H.size(), n = N.size(), begin = 0, matched = 0, ret = 0;
  while(begin + n <= h) {
    if (matched < n && H[begin + matched] == N[matched]) {
      ++matched;
      if (matched == n) {
        ++ret;
      }
    } else {
      if(matched == 0) {
        ++begin;
      } else {
        begin += matched - pi[matched - 1];
        matched = pi[matched - 1];
      }
    }
  }

  return ret;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string s;

  while(1){
    cin >> s;
    if(s == ".") break;

    vector<int> pi(s.size(), 0);
    int rest_size = get_partial_match(s, pi);

    if(s.size() % rest_size == 1) {
      cout << "1\n";
    } else {
      string N(s.begin(), s.begin() + rest_size);
      cout << kmp(pi, s, N) << "\n";
    }
  }

  return 0;
}

