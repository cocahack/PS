#pragma GCC optimize("O3")
//#include <bits/stdc++.h>
using namespace std;
using Node = tuple<int, int, char>;
int T, input, output;
char op[10001];
int last_state[10001];

inline int D(int v)
{
  return (v * 2) % 10000;
}

inline int S(int v)
{
  return v-1 < 0 ? 9999 : v-1;
}

inline int L(int v)
{
  return (v % 1000) * 10 + v / 1000;
}

inline int R(int v)
{
  int q = v / 10, d4 = v - q * 10;
  return q + d4 * 1000;
}

void bfs()
{
  queue<Node> q;
  q.push(make_tuple(input, 10001, 'A'));

  while(q.size()){
    auto cur = q.front();
    q.pop();

    int a = get<0>(cur), b = get<1>(cur);
    char c = get<2>(cur);

    if(last_state[a] != -1) continue;
    last_state[a] = b;
    op[a] = c;
    if(a == output) return;

    q.push(make_tuple(D(a), a, 'D'));
    q.push(make_tuple(S(a), a, 'S'));
    q.push(make_tuple(L(a), a, 'L'));
    q.push(make_tuple(R(a), a, 'R'));
  }

}

string answer_builder()
{
  int cur = output;
  string ret = "";
  while(cur != input){
    ret += op[cur];
    cur = last_state[cur];
  }
  reverse(ret.begin(), ret.end());
  return ret;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> T;

  while(T--){
    cin >> input >> output;
    memset(last_state, -1, sizeof last_state);
    memset(op, 0, sizeof op);
    bfs();
    cout << answer_builder() << "\n";
  }

  return 0;
}
