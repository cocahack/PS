#include <bits/stdc++.h>
using namespace std;
int check[26];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  memset(check, -1, sizeof check);
  string s;
  cin >> s;

  for(int i=0; i<s.size(); ++i) {
    int a = s[i] - 'a';
    if(check[a] == -1) {
      check[a] = i;
    }
  }

  for(int i=0; i<26; ++i) cout << check[i] << " ";

  return 0;
}

