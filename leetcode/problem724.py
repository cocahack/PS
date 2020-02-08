from functools import reduce


class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        if len(nums) == 0:
            return -1
        all_sums = reduce((lambda x, y: x + y), nums)
        ls, rs = 0, all_sums

        for i, v in enumerate(nums):
            rs -= v
            if ls == rs:
                return i
            ls += v

        return -1
