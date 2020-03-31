#include <bits/stdc++.h>

using namespace std;

unordered_map<long long, long long> parent;

long long find(long long curr) {
  if (parent[curr] == curr) return parent[curr];
  return parent[curr] = find(parent[curr]);
}

void merge(long long u, long long v) {
  u = find(u), v = find(v);
  if(u == v) return;
  if(parent[u] > parent[v]) swap(u, v);
  parent[u] = v;
}

vector<long long> solution(long long k, vector<long long> room_numbers) {
  vector<long long> answer;

  for(auto room_number: room_numbers) {
    if(parent.find(room_number) == parent.end()) {
      answer.push_back(room_number);
      parent.insert({room_number, room_number});
      if(room_number - 1 > 0 && parent.find(room_number - 1) != parent.end()) {
        merge(room_number - 1, room_number);
      }
      if(room_number + 1 <= k && parent.find(room_number + 1) != parent.end()) {
        merge(room_number, room_number + 1);
      }
    } else {
      long long rightmost = find(room_number) + 1;
      answer.push_back(rightmost);
      parent.insert({rightmost, rightmost});
      merge(rightmost - 1, rightmost);
      if(rightmost + 1 <= k && parent.find(rightmost + 1) != parent.end()) {
        merge(rightmost, rightmost + 1);
      }
    }
  }

  return answer;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

//  auto answer = solution(10, {1,3,4,1,3,1});
  auto answer = solution(10, {1,1,1,1,1,1});
  for(auto a : answer) {
    cout << a << " ";
  }
  cout << "\n";

  return 0;
}

