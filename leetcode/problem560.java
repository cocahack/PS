class Solution {
    public int subarraySum(int[] nums, int k) {
        if(nums.length == 0) return 0;
        int answer = 0;
        HashMap<Integer, Integer> tv = new HashMap<>();
        tv.put(0, 1);

        int sum = 0;

        for (int i=0; i<nums.length; ++i) {
            sum += nums[i];

            if(tv.containsKey(sum - k)) {
                answer += tv.get(sum - k);
            }

            if(tv.containsKey(sum)) {
                tv.put(sum, tv.get(sum) + 1);
            } else {
                tv.put(sum, 1);
            }
        }

        return answer;
    }
}

