class Solution:
    def findPairs(self, nums: List[int], k: int) -> int:
        dic = {}

        for n in nums:
            if n not in dic:
                dic[n] = 1
            else:
                dic[n] += 1

        uniqueNums = list(set(nums))
        uniqueNums.sort()
        N = len(uniqueNums)

        left = 0
        right = 0
        answer = 0

        while left < N and right < N:
            if left == right:
                if k == 0 and uniqueNums[right] in dic and dic[uniqueNums[right]] > 1:
                    answer += 1
                right += 1
            elif uniqueNums[right] - uniqueNums[left] < k:
                right += 1
            elif uniqueNums[right] - uniqueNums[left] > k:
                left += 1
            else:
                answer += 1
                right += 1

        return answer

