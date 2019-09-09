#include <bits/stdc++.h>
using namespace std;

int get_sum(const multiset<int>& sticks)
{
  int ret = 0;
  for(auto s : sticks) ret += s;
  return ret;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  multiset<int> sticks;
  sticks.insert(64);

  int x;
  cin >> x;

  while(get_sum(sticks) > x) {
    int smallest = *sticks.begin();
    sticks.erase(sticks.begin());

    if(get_sum(sticks) + (smallest / 2) >= x) {
      sticks.insert(smallest / 2);
    } else {
      sticks.insert(smallest / 2);
      sticks.insert(smallest / 2);
    }
  }

  cout << sticks.size();

  return 0;
}
