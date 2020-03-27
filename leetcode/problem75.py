class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        N = len(nums)
        red = 0
        blue = N - 1
        i = 0

        while i <= blue:
            if nums[i] == 0:
                nums[i], nums[red] = nums[red],  nums[i]
                i += 1
                red += 1
            elif nums[i] == 2:
                nums[i], nums[blue] = nums[blue],  nums[i]
                blue -= 1
            else:
                i += 1

