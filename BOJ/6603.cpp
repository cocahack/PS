#include <bits/stdc++.h>
using namespace std;

int lotto[49], k;
bool picks[49];

void dfs(int selected, int last) {
  if(selected == 6) {
    for(int i=0; i<k; ++i) if(picks[i]) cout << lotto[i] << " ";
    cout << "\n";
    return;
  }

  for(int i=last+1; i<k; ++i) {
    picks[i] = true;
    dfs(selected+1, i);
    picks[i] = false;
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  while(true) {
    cin >> k;
    if(k == 0) break;

    for (int i = 0; i < k; ++i) cin >> lotto[i];

    dfs(0, -1);
    cout << "\n";
  }
  return 0;
}

