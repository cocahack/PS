class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        if m == 0 or n == 0:
            return 0
        factorial = [1]
        for i in range(1, m+n):
            factorial.append(factorial[i-1] * i)
        return factorial[m+n-2] // factorial[m-1] // factorial[n-1]

