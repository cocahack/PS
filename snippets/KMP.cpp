//#include <bits/stdc++.h>
using namespace std;

void get_partial_match(const string& s, vector<int>& pi)
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
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string H, N;
  cin >> H >> N;
  int h = H.size(), n = N.size();
  vector<int> pi(n, 0), matched_loc;
  
  get_partial_match(N, pi);
  
  int begin = 0, matched = 0;
  
  while(begin < h - n) {
    if(matched < n && H[begin+matched] == N[matched]) {
      ++matched;
      if(matched == n) matched_loc.push_back(begin);
    } else {
      if(matched == 0) {
        ++begin;
      } else {
        begin += matched - pi[matched-1];
        matched = pi[matched-1];
      }
    }
  }
  
  for(auto loc : matched_loc) {
    cout << loc << "\n";
  }

  return 0;
}

