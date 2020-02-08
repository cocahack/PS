class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        answer = []
        candidates.sort()

        def dfs(arr, remains):
            if remains == 0:
                answer.append(arr[:])
                return

            for c in candidates:
                if remains - c >= 0 and (len(arr) == 0 or arr[-1] <= c):
                    arr.append(c)
                    dfs(arr, remains - c)
                    del arr[-1]

        dfs([], target)

        return answer

