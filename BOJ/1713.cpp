#include <bits/stdc++.h>
using namespace std;

struct student{
  int num, r_count, insert_time;
  student(int n, int r, int i): num(n), r_count(r), insert_time(i){}
  bool operator < (const student& rhs) const {
    if(r_count != rhs.r_count) return r_count < rhs.r_count;
    return insert_time > rhs.insert_time;
  }
};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m, r;
  cin >> n >> m;
  vector<bool> is_inserted(m+1, 0);
  set<student> frames;

  while(m--) {
    cin >> r;
    if(is_inserted[r]) {
      auto iter = frames.begin();
      for(; iter != frames.end(); ++iter){
        if(iter->num == r) break;
      }
      student s = *iter;
      frames.erase(iter);
      s.r_count++;
      frames.insert(s);
    } else {
      if(frames.size() == n) {
        student min_s = *frames.begin();
        frames.erase(frames.begin());
        is_inserted[min_s.num] = false;
      }
      student s = student(r, 1, m);
      is_inserted[r] = true;
      frames.insert(s);
    }
  }

  vector<int> students;
  for(auto iter : frames) students.push_back(iter.num);
  sort(students.begin(), students.end());

  for(auto num : students) {
    cout << num << " ";
  }

  return 0;
}
