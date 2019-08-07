#include <bits/stdc++.h>
using namespace std;

constexpr int MAX = 1'000'001;
int n;
struct Event
{
  int point, order;
  bool is_end;
  bool operator < (const Event& e) const {
    if(point != e.point) return point < e.point;
    if(is_end != e.is_end) return is_end > e.is_end;
    return order < e.order;
  }
};

Event e[MAX*2+2];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int a, b, order = 0;
  cin >> n;
  for(int i=0; i<2*n; i+=2, order++){
    cin >> e[i].point;
    e[i].order = order;
    e[i].is_end = false;
    cin >> e[i+1].point;
    e[i+1].order = order;
    e[i+1].is_end = true;
  }

  sort(e, e+2*n);
  int cur = 0, answer = 0;

  for(int i=0; i<n*2; ++i){
    if(e[i].is_end) {
      answer = max(cur, answer);
      cur--;
    } else {
      cur++;
    }
  }

  cout << answer;

  return 0;
}

