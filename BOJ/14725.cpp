#include <bits/stdc++.h>
using namespace std;

struct Node {
  string key;
  map<string, Node*> children;
  Node() {}
  Node(string _key):key(_key) { }
};
string cur_key;

void recur(Node* root, int remains)
{
  if(!remains) return;
  cin >> cur_key;

  auto cur = root->children.find(cur_key);
  Node* node;
  if(cur == root->children.end()) {
    node = new Node(cur_key);
    root->children.insert(make_pair(cur_key, node));
  } else {
    node = cur->second;
  }
  recur(node, remains-1);
}

void print(Node* root, int depth) {
  if(depth != 0) {
    string delim = "";
    for(int i=0; i<depth-1; ++i) {
      delim += "--";
    }
    delim += root->key;

    cout << delim << "\n";
  }
  for(auto child : root->children) {
    print(child.second, depth+1);
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, a;
  string t;
  cin >> n;

  Node* root = new Node("");

  while(n--) {
    cin >> a;
    recur(root, a);
  }

  print(root, 0);

  return 0;
}

