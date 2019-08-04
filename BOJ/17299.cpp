#include <bits/stdc++.h>
using namespace std;

int arr[1000001];
int freq[1000001];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  for(int i=0; i<n; ++i) cin >> arr[i], freq[arr[i]]++;

  stack<int> s, answer;

  for(int i=n-1; i>=0; --i){
    while(s.size() && freq[s.top()] <= freq[arr[i]]) s.pop();
    if(s.empty()) {
      answer.push(-1);
    } else {
      answer.push(s.top());
    }
    s.push(arr[i]);
  }

  while(answer.size()){
    cout << answer.top() << " ";
    answer.pop();
  }

  return 0;
}

