#include <bits/stdc++.h>

using namespace std;
class Trie {
public:
	int c = 0;
    vector<int> ids;
    Trie* children[27]{nullptr,};

    Trie() = default;
    ~Trie() {
        for (int i=0; i<27; ++i) delete children[i];
    }

    void insert(string& s, int idx, int num){
        if(s.size() == idx) {
            ids.push_back(num);
            return;
        }

        int ci = s[idx] != '?' ? s[idx] - 'a' : 26;
        if (children[ci] == nullptr) {
            children[ci] = new Trie();
        }
        children[ci]->insert(s, idx+1, num);
    }

    void search(string& s, int idx) {
        if(s.size() == idx) {
			c++;
            return;
        }

        if (children[26]) {
            children[26]->search(s, idx+1);
        }
        
        int ci = s[idx] - 'a';
        if(children[ci]) {
            children[ci]->search(s, idx+1);
        }
    }
    
    void make_result(vector<int>& answer) {
        if(c != 0) {
            for(auto& i : ids) answer[i] = c;
        }
        
        for(int i=0; i<27; ++i) {
            if(children[i]) children[i]->make_result(answer);
        }
    }
};

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer(queries.size(), 0);
    Trie query_root = Trie();
    int idx = 0;

    for(auto q : queries) {
        query_root.insert(q, 0, idx++);
    }

    for(auto w : words) {
        query_root.search(w, 0);
    }
    
    query_root.make_result(answer);

    return answer;
}

