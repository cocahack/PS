#include <bits/stdc++.h>
#define for1d(size) for(int i=0; i<size; ++i)
using namespace std;
int n, arr[11], op[4];
int selected_op[10];
constexpr int MAX_LIMIT = 10'0000'0001, MIN_LIMIT = -10'0000'0001;
int max_val = MIN_LIMIT;
int min_val = MAX_LIMIT;

int calculator(int a, int b, int op)
{
  switch(op) {
    case 1:
      return a + b;
    case 2:
      return a - b;
    case 3:
      return a * b;
    case 4:
      return a / b;
  }
}

void cal()
{
  stack<int> s;
  s.push(calculator(arr[0], arr[1], selected_op[0]));

  for(int i=1; i<n-1; ++i){
    int acc = s.top();
    s.pop();
    s.push(calculator(acc, arr[i+1], selected_op[i]));
  }

  int result = s.top();

  max_val = max(max_val, result);
  min_val = min(min_val, result);
}

void select_op(int iter)
{
  if(iter == n-1) {
    cal();
    return;
  }
  for(int i=0; i<4; ++i){
    if(op[i]) {
      selected_op[iter] = i + 1;
      op[i]--;
      select_op(iter + 1);
      op[i]++;
      selected_op[iter] = 0;
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  for1d(n) cin >> arr[i];
  for1d(4) cin >> op[i];

  select_op(0);

  cout << max_val << "\n" << min_val;

  return 0;
}
