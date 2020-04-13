class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int, vector<int>, less<int>> q;
        
        for(auto s : stones) q.push(s);
        
        while(q.size() > 1) {
            int first = q.top();
            q.pop();
            int second = q.top();
            q.pop();
            
            if(first > second) {
                q.push(first-second);
            }
        }
        
        return q.size() ? q.top() : 0;
    }
};

