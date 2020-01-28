#include <bits/stdc++.h>
using namespace std;

int building[1'000'001]{0,};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int f, s, g, u, d;
  cin >> f >> s >> g >> u >> d;

  queue<int> q;
  q.push(s);
  building[s] = 1;
  int answer = -1;

  while(q.size()) {
    auto cur = q.front();
    q.pop();

    if(cur == g) {
      answer = building[cur] - 1;
      break;
    }

    int up = cur + u, down = cur - d;

    if(up <= f && !building[up]) {
      building[up] = building[cur] + 1;
      q.push(up);
    }

    if(down >= 1 && !building[down]) {
      building[down] = building[cur] + 1;
      q.push(down);
    }
  }


  if(answer != -1) cout << answer;
  else cout << "use the stairs";

  return 0;
}

