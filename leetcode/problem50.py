class Solution:
    def myPow(self, x: float, n: int) -> float:
        if x == 0:
            return 0

        if n < 0:
            x = 1 / x
            n *= -1

        def recurPow(base, exp):
            if exp == 0:
                return 1

            halfExp = recurPow(base, exp // 2)
            return halfExp * halfExp if exp % 2 == 0 else halfExp * halfExp * base

        return recurPow(x, n)


