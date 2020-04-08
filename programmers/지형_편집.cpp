#include<bits/stdc++.h>
using namespace std;

vector<long long> blocks(90000, 0ll);
vector<long long> acc(90001, 0ll);

long long f(long long N, long long P, long long Q, long long target) {
  long long ret = 0ll;

  auto iter = lower_bound(blocks.begin(), blocks.begin() + N * N, target);
  auto iter2 = upper_bound(blocks.begin(), blocks.begin() + N * N, target);

  long long low_idx = iter - blocks.begin(), upp_idx = iter2 - blocks.begin();

  low_idx = low_idx-1;
    
  long long plus = ((low_idx + 1) * target) - (acc[low_idx+1] - acc[0]);
  long long minus = (acc[N*N] - acc[upp_idx]) - ((N*N - upp_idx) * target);

  if(low_idx >= 0) {
      ret += plus * P;
  }
   ret += minus * Q;

  return ret;
}

long long solution(vector<vector<int> > land, int P, int Q)
{
  long long N = land.size();
  double lo, hi;

  acc[0] = 0;
  for(int i=0; i<N; ++i) for(int j=0; j<N; ++j) {
      blocks[N*i+j] = land[i][j];
    }

  sort(blocks.begin(), blocks.begin() + N * N);

  for(int i=0; i<N; ++i) for(int j=0; j<N; ++j) {
      int cur = N*i+j;
      acc[cur+1] = blocks[cur] + acc[cur];
    }

  lo = blocks[0], hi = blocks[N*N-1];

  for(int iter = 0; iter < 50; ++iter) {
    double a = (2*lo + hi) / 3.;
    double b = (lo + hi*2) / 3.;

    if(f(N, P, Q, a) > f(N, P, Q, b)) {
      lo = a;
    } else {
      hi = b;
    }
  }

  double mid = (lo + hi) / 2;

  long long ret = numeric_limits<long long>::max();

  for(double i = mid-2; i < mid+2; ++i) {
    ret = min(ret, f(N, P, Q, i));
  }

  return ret;
}

