#include <bits/stdc++.h>
using namespace std;

char chars[21] {'b','d','e','f','g','h','j','k','l','m','o','p','q','r','s','u','v','w','x','y','z'};
char common_chars[5] {'a','c','i','n','t'};
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, k;
  string w;
  cin >> n >> k;
  vector<string> words(n);
  for(int i=0;i<n;++i) {
    cin >> w;
    words[i] = string(w.begin()+4, w.end()-4);
  }

  if(k < 5) {
    cout << 0;
    return 0;
  }

  if(k == 26) {
    cout << n;
    return 0;
  }

  int answer = 0;
  std::vector<bool> v(21);
  std::fill(v.end() - 21 + k - 5, v.end(), true);

  do {
    string letters = "";
    int local_answer = 0;
    for(int j=0; j<21; ++j) if(!v[j]) letters += chars[j];

    for(auto word : words) {
      bool skip = false;
      for(auto c : word) {
        bool exist = false;

        for(auto lc: letters) {
          if(c == lc) {
            exist = true;
            break;
          }
        }

        for(auto cc : common_chars) {
          if(cc == c) {
            exist = true;
            break;
          }
        }

        if(!exist) {
          skip = true;
          break;
        }
      }
      if(skip) continue;
      local_answer++;
    }

    answer = max(answer, local_answer);
  } while (next_permutation(v.begin(), v.end()));

  cout << answer;

  return 0;
}
