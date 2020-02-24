class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<int>> memo(s.size(), vector<int>(p.size(), -1));
        return isMatchHelper(memo, s, p, 0, 0);
    }
private:
    bool isMatchHelper(vector<vector<int>>& memo, string& s, string& p, int s_idx, int p_idx) {
        if(p_idx == p.size()) {
            return s_idx == s.size();
        }
        
        if(s_idx == s.size()) {
            for(int i=p_idx; i < p.size(); ++i){
                if(p[i] != '*') return false;
            }
            return true;
        }
        
        auto& ret = memo[s_idx][p_idx];
        if (ret != -1) return ret;
        ret = 0;
        
        char pc = p[p_idx];
        
        if(pc == '?' || pc == s[s_idx]) {
            return ret = isMatchHelper(memo, s, p, s_idx+1, p_idx+1);
        }
        
        if(pc == '*') {
            ret = isMatchHelper(memo, s, p, s_idx, p_idx+1);
            if(ret) return ret;
            ret = isMatchHelper(memo, s, p, s_idx+1, p_idx);
            if(ret) return ret;
            ret = isMatchHelper(memo, s, p, s_idx+1, p_idx+1);
            return ret;
        }
        
        return ret;
    }
};
