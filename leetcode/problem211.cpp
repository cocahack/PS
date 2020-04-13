class WordDictionary {
public:
    bool is_end;
    vector<WordDictionary*> children;
    
    /** Initialize your data structure here. */
    WordDictionary() {
        is_end = false;
        children = vector<WordDictionary*>(26, nullptr);
    }
    
    ~WordDictionary() {
        for(auto ptr : children) delete ptr;
    }
    
    void addWordHelper(const string& word, int idx) {
        if(word.size() == idx) {
            is_end = true;
            return;
        }
        
        int alpha = word[idx] - 'a';
        if(children[alpha] == nullptr) {
            children[alpha] = new WordDictionary();
        }
        children[alpha]->addWordHelper(word, idx+1);
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        addWordHelper(word, 0);
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    
    bool searchHelper(const string& word, int idx) {
        if(word.size() == idx) {
            return is_end;
        }
        
        bool ret = false;
        int alpha = word[idx] - 'a';
        if(word[idx] == '.') {
            for(auto child : children) {
                if(child) ret = child->searchHelper(word, idx+1);
                if(ret) break;
            }
        } else if(children[alpha]) {
            ret = children[alpha]->searchHelper(word, idx+1);
        }
        
        return ret;
    }
    
    bool search(string word) {
        return searchHelper(word, 0);
    }
};

