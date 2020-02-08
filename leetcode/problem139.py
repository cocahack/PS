class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        cache = [-1] * len(s)
        def dfs(start):
            if start == len(s):
                return 1

            if cache[start] != -1:
                return cache[start]

            cache[start] = 0
            for w in wordDict:
                can_next = True
                for i, c in enumerate(w):
                    if start + i >= len(s) or c != s[start + i]:
                        can_next = False
                        break
                if can_next:
                    cache[start] |= dfs(start + len(w))
                if cache[start]:
                    break
            return cache[start]

        return dfs(0)



