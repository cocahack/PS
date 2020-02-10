class Solution:
    def climbStairs(self, n: int) -> int:
        if n <= 2:
            return n

        before2 = 1
        before1 = 2
        cur = 0
        for i in range(3, n+1):
            cur = before2 + before1
            before2 = before1
            before1 = cur

        return cur
