bool comp(const vector<int>& lhs, const vector<int>& rhs) {
    if(lhs[0] != rhs[0]) return lhs[0] < rhs[0];
    return lhs[1] < rhs[1];
}
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if (envelopes.empty()) return 0;
        
        sort(envelopes.begin(), envelopes.end(), comp);
        
        vector<int> memo(envelopes.size(), -1);
        
        int ret = -1;
        for(int i=0; i<envelopes.size(); ++i){
            ret = max(ret, maxEnvelopesHelper(envelopes, memo, i));
        }
        return ret;
    }
    
    int maxEnvelopesHelper(vector<vector<int>>& envelopes, vector<int>& memo, int idx) {
        int& ret = memo[idx];
        if(ret != -1) return ret;
        
        ret = 1;
        for(int i = idx+1; i < envelopes.size(); ++i) {
            if(envelopes[idx][0] < envelopes[i][0] && envelopes[idx][1] < envelopes[i][1]) {
                ret = max(ret, 1 + maxEnvelopesHelper(envelopes, memo, i));
            }
        }
        
        return ret;
    }
};

