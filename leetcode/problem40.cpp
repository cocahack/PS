class Solution {
private:
    vector<vector<int>> answer;
    
    void recur(vector<int>& cnd, vector<int>& pcom, int idx, int target) {
        if(target == 0) {
            answer.push_back(pcom);
            return;
        }
        
        if(target < 0) return;
        
        for(int i = idx; i < cnd.size(); ++i) {
            if(i > idx && cnd[i-1] == cnd[i]) continue;
            pcom.push_back(cnd[i]);
            recur(cnd, pcom, i+1, target-cnd[i]);
            pcom.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        answer = vector<vector<int>>(0);
        vector<int> partial_combination;
        recur(candidates, partial_combination, 0, target);
        
        return answer;
    }
};

