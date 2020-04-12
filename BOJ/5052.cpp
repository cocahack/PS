#include <bits/stdc++.h>
using namespace std;

int n;
bool inconsistent = false;

struct Node {
  bool is_end;
  vector<Node*> children;

  Node():is_end(false){ children = vector<Node*>(10, nullptr); }
  ~Node() { for (int i = 0; i < 10; ++i) delete children[i]; }

  void save(const string& pnum, int idx) {
    if(pnum.size() == idx) {
      is_end = true;
      return;
    }

    int num = pnum[idx] - '0';
    if(children[num] == nullptr) {
      children[num] = new Node();
    }
    if(is_end) {
      inconsistent = true;
    }
    children[num]->save(pnum, idx+1);
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  while(t--) {
    inconsistent = false;
    cin >> n;
    string s;
    Node* root = new Node();
    vector<string> pnums(n);
    for(int i=0; i<n; ++i) cin >> pnums[i];
    sort(pnums.begin(), pnums.end());

    for(auto pnum : pnums) {
      if(inconsistent) break;
      root->save(pnum, 0);
    }
    delete root;
    cout << (inconsistent ? "NO" : "YES" ) << "\n";
  }

  return 0;
}

