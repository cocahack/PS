#include <bits/stdc++.h>
using namespace std;
int arr[26]{0,};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string s;
  cin >> s;

  for(char c : s){
    arr[c-'A']++;
  }

  int odd = 0;
  for(int i = 0; i < 26; ++i){
    odd += (arr[i] % 2);
  }

  if(odd > 1) {
    cout << "I\'m Sorry Hansoo";
    return 0;
  }

  string a = "", b = "";

  for(int i=0; i<26; ++i){
    while(arr[i]/2){
      a += 'A' + i;
      b += 'A' + i;
      arr[i] -= 2;
    }
  }

  for(int i=0; i<26; ++i){
    if(arr[i]) {
      a += 'A' + i;
      break;
    }
  }

  reverse(b.begin(), b.end());
  cout << a + b;
  
  return 0;
}
