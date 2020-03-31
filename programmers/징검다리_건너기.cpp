#include <bits/stdc++.h>

using namespace std;


bool is_possible(const vector<int>& stones, int k, int target) {
  int consequences = 0, before = -1;
  int max_con = 0;

  for(int i=0; i<stones.size(); ++i) {
    if(stones[i] <= target) {
      if (before + 1 == i) {
        consequences++;
        max_con = max(max_con, consequences);
        before = i;
      } else {
        consequences = 1;
        max_con = max(max_con, consequences);
        before = i;
      }
    }
  }

  return max_con >= k;
}

int solution(vector<int> stones, int k) {
  int lo = 1, hi = 200000000, mid;

  while(lo + 1 < hi) {
    mid = (lo + hi) / 2;
    if(is_possible(stones, k, mid)) {
      hi = mid;
    } else {
      lo = mid;
    }
  }

  return is_possible(stones, k, hi) ? hi : lo;
}

