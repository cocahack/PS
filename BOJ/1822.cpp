#include <bits/stdc++.h>
using namespace std;
set<unsigned> s;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  unsigned a, b, t;
  cin >> a >> b;

  for(int i=0; i<a; ++i){
    cin >> t;
    s.insert(t);
  }

  for(int i=0; i<b; ++i){
    cin >> t;
    s.erase(t);
  }

  cout << s.size() << "\n";

  for(auto i : s) {
    cout << i << " ";
  }

  return 0;
}

