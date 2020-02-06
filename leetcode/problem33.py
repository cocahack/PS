from typing import *


class Solution:
    def search(self, nums: List[int], target: int) -> int:
        left = 0
        right = len(nums) - 1
        while left <= right:
            if nums[left] == target:
                return left
            elif nums[right] == target:
                return right
            else:
                left += 1
                right -= 1
        return -1

s = Solution()
print(s.search([4,5,6,7,0,1,2], 0))

