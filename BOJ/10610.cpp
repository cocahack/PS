#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string N;
  cin >> N;

  sort(N.begin(), N.end(), greater<char>());

  int digit_sum = 0;
  for(auto c : N){
    digit_sum += (c - '0');
  }

  if(digit_sum % 3 != 0 || N.size() < 2 || N.back() != '0') {
    cout << -1;
  } else {
    cout << N;
  }

  return 0;
}
