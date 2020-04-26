#include <bits/stdc++.h>

using namespace std;

class Trie {
    Trie* children[26]{0,};
    int cnt[26]{0,};
    bool is_end = false;
public:
    Trie(){}
    ~Trie() {
        for(int i=0; i<26; ++i) delete children[i];
    }
    
    void insert(const string& s, int idx) {
        if(idx == s.size()) {
            is_end = true;
            return;
        }
        
        int ci = s[idx] - 'a';
        if(children[ci] == nullptr) {
            children[ci] = new Trie();
        }
        cnt[ci]++;
        children[ci]->insert(s, idx+1);
    }
    
    int search(const string& s, int idx) {
        if(s.size() == idx) {
            return 0;
        }
        
        int ci = s[idx] - 'a';
        
        if(cnt[ci] == 1) {
            return 1;
        }
        
        return children[ci]->search(s, idx+1) + 1;
    }
};

int solution(vector<string> words) {
    int answer = 0;
    Trie root = Trie();
    
    for(string w : words) {
        root.insert(w, 0);
    }
    
    for(string w : words) {
        answer += root.search(w, 0);
    }
    
    return answer;
}

