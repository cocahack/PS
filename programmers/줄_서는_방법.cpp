#include <string>
#include <vector>

using namespace std;
using ll = long long;
ll fac[21];
bool used[21];

vector<int> solution(int n, ll k) {
  vector<int> answer;
  fac[0] = 1ll;
  for(int i=1;i <21; ++i) {
    fac[i] = fac[i-1] * i;
  }

  ll lo = 0;

  for(int i=n-1; i >=0; --i) {

    for(int j=0; j <= i; ++j) {

      ll nlo = lo + fac[i] * j, hlo = lo + fac[i] * (j + 1);

      if(nlo <= k && k <= hlo) {
        int cnt = 0, l;
        for (l = 0; l < n; ++l) {
          if(used[l]) continue;
          if(cnt == j) {
            break;
          }
          ++cnt;
        }

        answer.push_back(l+1);
        used[l] = true;
        lo = nlo;
        break;
      }

    }

  }

  return answer;
}

