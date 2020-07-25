class Solution {
private:
    
    void transform_case(string& S, int idx) {
        char diff = 'a' - 'A';
        
        if (S[idx] >= 'A' && S[idx] <= 'Z') {
            S[idx] += diff;
            return;
        }
        
        if (S[idx] >= 'a' && S[idx] <= 'z') {
            S[idx] -= diff;
            return;
        }
    }
    
    void recur(vector<string>& answer, vector<int>& alphabet_indexes, string& S, int idx) {
        if(idx == alphabet_indexes.size()) {
            answer.push_back(S);
            return;
        }
        
        transform_case(S, alphabet_indexes[idx]);
        recur(answer, alphabet_indexes, S, idx+1);
        transform_case(S, alphabet_indexes[idx]);
        recur(answer, alphabet_indexes, S, idx+1);
    }
    
public:
    vector<string> letterCasePermutation(string S) {
        if(S.empty()) {
            return {S};
        }
        
        vector<int> alphabet_indexes;
        for(int i=0; i<S.size(); ++i) {
            if(!(S[i] >= '0' && S[i] <= '9')) {
                alphabet_indexes.push_back(i);
            }
        }
        
        vector<string> answer;
        
        recur(answer, alphabet_indexes, S, 0);
        
        return answer;
    }
};

