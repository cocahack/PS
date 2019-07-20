#include <bits/stdc++.h>
using namespace std;
using record = tuple<string, int, int, int>;

bool compare(const record& lhs, const record& rhs)
{
  if(get<1>(lhs) != get<1>(rhs)) return get<1>(lhs) > get<1>(rhs);
  if(get<2>(lhs) != get<2>(rhs)) return get<2>(lhs) < get<2>(rhs);
  if(get<3>(lhs) != get<3>(rhs)) return get<3>(lhs) > get<3>(rhs);
  return get<0>(lhs) < get<0>(rhs);
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N;
  cin >> N;

  string s;
  int a, b, c;
  vector<record> v;

  for(int i=0; i<N; ++i){
    cin >> s >> a >> b >> c;
    v.push_back(make_tuple(s, a, b, c));
  }

  sort(v.begin(), v.end(), compare);

  for(auto t : v) {
    cout << get<0>(t) << "\n";
  }

  return 0;
}
