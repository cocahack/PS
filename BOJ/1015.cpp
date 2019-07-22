#include <bits/stdc++.h>
using namespace std;
using pair_arr = vector<pair<int, int>>;
pair_arr A;

bool compare(const pair<int,int>& lhs, const pair<int, int>& rhs)
{
  if(lhs.second != rhs.second) return lhs.second < rhs.second;
  return lhs.first < rhs.first;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N, a;
  cin >> N;

  for(int i=0; i<N; ++i) {
    cin >> a;
    A.push_back(make_pair(i, a));
  }

  sort(A.begin(), A.end(), compare);
  vector<int> P(N);

  for(int i=0; i<N; ++i){
    P[A[i].first] = i;
  }

  for(auto answer : P) {
    cout << answer << " ";
  }

  return 0;
}
