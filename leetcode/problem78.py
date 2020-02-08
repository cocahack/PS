class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        N = len(nums)
        if N == 0:
            return [[]]

        answer = []
        nums.sort()
        def dfs(arr):
            if len(arr) == N:
                return

            answer.append(arr[:])
            for i, v in enumerate(nums):
                if len(arr) > 0 and arr[-1] >= v:
                    continue
                arr.append(v)
                dfs(arr)
                arr.pop(-1)

        dfs([])
        answer.append(nums)
        return answer

