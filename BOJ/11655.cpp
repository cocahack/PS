#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string s;
  getline(cin, s);
  for(unsigned char c : s) {
    if(c < 'A' || c > 'z' || (c > 'Z' && c < 'a')) cout << c;
    else {
      unsigned char next_c = c + 13u;
      if(c >= 'a' && next_c > 'z') {
        next_c -= 26u;
      }

      if(c >= 'A' && c <= 'Z' && next_c > 'Z') {
        next_c -= 26u;
      }
      cout << next_c;
    }
  }

  return 0;
}

