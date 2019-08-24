#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  priority_queue<int> max_q;
  priority_queue<int, vector<int>, greater<int>> min_q;

  int n, i;
  cin >> n;

  while(n--) {
    cin >> i;
    int print_num;
    if(min_q.empty() && max_q.empty()) {
      max_q.push(i);
      print_num = i;
    }
    else if(min_q.size() < max_q.size()) {
      if(i >= max_q.top()) {
        min_q.push(i);
      } else {
        min_q.push(max_q.top());
        max_q.pop();
        max_q.push(i);
      }
      print_num = max_q.top();
    } else if(max_q.size() < min_q.size()) {
      if(i <= min_q.top()) {
        max_q.push(i);
      } else {
        max_q.push(min_q.top());
        min_q.pop();
        min_q.push(i);
      }
      print_num = max_q.top();
    } else {
      if(max_q.top() >= i) {
        max_q.push(i);
        print_num = max_q.top();
      } else {
        min_q.push(i);
        print_num = min_q.top();
      }
    }
    cout << print_num << "\n";
  }

  return 0;
}

