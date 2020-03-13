class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        int idx = 0, N = nums.size();
        while(idx < N) {
            if(nums[idx] == idx + 1 || nums[idx] <= 0 || N <= nums[idx] || nums[nums[idx]-1] == nums[idx]){
                ++idx;
                continue;
            } 
            swap(nums[nums[idx]-1], nums[idx]);
        }
        
        for(int i=0; i<N; ++i) {
            if (nums[i] != i+1) {
                return i+1;
            }
        }
        
        return N + 1;
    }
};

