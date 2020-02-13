class Solution:
    def numTrees(self, n: int) -> int:
        if n == 0:
            return 1
        fac = 1
        for i in range(1, 2*n + 1):
            fac *= i
            if i == n:
                nfac = fac
            if i == n+1:
                n1fac = fac
            if i == 2*n:
                _2nfac = fac

        return int(_2nfac / (nfac * n1fac))
