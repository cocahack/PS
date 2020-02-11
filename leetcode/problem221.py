import math

class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        memo = {}
        h = len(matrix)
        if h == 0:
            return 0
        w = len(matrix[0])


        answer = 0
        for y in range(h+1):
            for x in range(w+1):
                if y == 0 or x == 0 or matrix[y-1][x-1] == '0':
                    memo[(y, x)] = 0
                    continue

                surround_min = min(memo[(y-1, x-1)], memo[(y-1,x)], memo[(y, x-1)])
                if surround_min != 0:
                    sqrt_min = math.sqrt(surround_min)
                    memo[(y, x)] = pow(sqrt_min + 1, 2)
                else:
                    memo[(y, x)] = 1

                answer = max(answer, memo[(y, x)])

        return int(answer)

