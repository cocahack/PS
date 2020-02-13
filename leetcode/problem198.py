class Solution:
    def rob(self, nums: List[int]) -> int:
        if len(nums) == 0:
            return 0

        memo = {}

        def dp(curr, rob):
            if curr >= len(nums):
                return 0

            if (curr, rob) in memo:
                return memo[(curr, rob)]


            memo[(curr, rob)] = nums[curr] if rob else 0

            if rob:
                memo[(curr, rob)] += max(dp(curr+1, 0), dp(curr+2, 1), dp(curr+2, 0))
            else:
                memo[(curr, rob)] += max(dp(curr+1, 1), dp(curr+2, 1), dp(curr+2, 0))

            return memo[(curr, rob)]

        return max(dp(0, 0), dp(0, 1))
