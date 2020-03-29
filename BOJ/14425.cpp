#include <bits/stdc++.h>
using namespace std;

constexpr int ALPHABETS = 26;
int N, M;

struct Trie_Node {
  Trie_Node* childNode[ALPHABETS];
  bool is_terminal;
  Trie_Node(): is_terminal(false) {
    memset(childNode, 0, sizeof childNode);
  }
  ~Trie_Node() {
    for (int i = 0; i < ALPHABETS; ++i) {
      if(childNode[i]) delete childNode[i];
    }
  }

  void insert(const char* key) {
    if(*key == 0) {
      is_terminal = true;
    } else {
      int next = (*key) - 'a';
      if(childNode[next] == nullptr) {
        childNode[next] = new Trie_Node();
      }
      childNode[next]->insert(key+1);
    }
  }

  bool find(const char* key) {
    if(*key == 0) return is_terminal;
    int next = (*key) - 'a';
    if(childNode[next] == nullptr) return false;
    return childNode[next]->find(key+1);
  }
};

Trie_Node* root = new Trie_Node();

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  char s[500];
  cin >> N >> M;
  for (int i = 0; i < N; ++i) {
    memset(s, 0, sizeof s);
    cin >> s;
    root->insert(s);
  }


  int answer = 0;
  for (int i = 0; i < M; ++i) {
    memset(s, 0, sizeof s);
    cin >> s;
    if(root->find(s)) ++answer;
  }

  delete root;

  cout << answer;

  return 0;
}

