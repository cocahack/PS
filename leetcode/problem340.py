class Solution:
    def lengthOfLongestSubstringKDistinct(self, s: str, k: int) -> int:
        N = len(s)
        if N <= k:
            return N

        hashmap = {}
        left, right = 0, 0
        answer = k

        while right < N:
            if len(hashmap) <= k:
                hashmap[s[right]] = right
                right += 1

            if len(hashmap) == k + 1:
                del_idx = min(hashmap.values())
                del hashmap[s[del_idx]]
                left = del_idx + 1

            answer = max(answer, right - left)

        return answer
