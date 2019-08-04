#include <bits/stdc++.h>
using namespace std;
unordered_set<int> primes;
int visited[10001];

int bfs(int input, int output)
{
  queue<int> q;
  q.push(input);
  visited[input] = 0;

  while(q.size()) {
    auto cur = q.front();
    q.pop();

    if(output == cur) {
      return visited[output];
    }

    for(int i=0; i<4; ++i){
      int base = (int)pow(10, i);
      int digit = ((cur / base) % (base * 10)) % 10;
      int erase_digit = cur - digit * base;
      for(int j=0; j<10; ++j){
        int next = erase_digit + j * base;
        if(next > 999 && (primes.find(next) != primes.end()) && visited[next] == -1){
          visited[next] = visited[cur] + 1;
          q.push(next);
        }
      }
    }

  }

  return -1;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  for(int i=1001; i<10000; i+=2){
    bool prime = true;
    for(int j=3; j*j<=i; j+=2) {
      if(i % j == 0){
        prime = false;
      }
    }
    if(prime) primes.insert(i);
  }

  int t, input, output;
  cin >> t;

  while(t--){
    cin >> input >> output;
    memset(visited, -1, sizeof visited);
    int answer = bfs(input, output);
    if (answer < 0) {
      cout << "Impossible\n";
    } else {
      cout << answer << "\n";
    }
  }

  return 0;
}

