class Solution:
    def lengthOfLongestSubstringKDistinct(self, s: str) -> int:
        N = len(s)
        if N <= 2:
            return N

        hashmap = {}
        left, right = 0, 0
        answer = 2

        while right < N:
            if len(hashmap) <= 2:
                hashmap[s[right]] = right
                right += 1

            if len(hashmap) == 3:
                del_idx = min(hashmap.values())
                del hashmap[s[del_idx]]
                left = del_idx + 1

            answer = max(answer, right - left)

        return answer
