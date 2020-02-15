class Solution:
    def numEnclaves(self, A: List[List[int]]) -> int:
        N = len(A)
        M = len(A[0])
        delta = [[-1,0],[0,1],[1,0],[0,-1]]
        visited = 2

        def checkBoundary(y, x):
            return y >= 0 and x >= 0 and y < N and x < M

        def dfs(y, x):
            A[y][x] = visited
            for d in delta:
                nextY, nextX = y + d[0], x + d[1]
                if not checkBoundary(nextY, nextX) or A[nextY][nextX] != 1:
                    continue
                dfs(nextY, nextX)

        for i in range(N):
            for j in range(M):
                if (i == 0 or j == 0 or i == N-1 or j == M-1) and A[i][j] == 1:
                    dfs(i, j)


        count = 0
        for i in range(N):
            for j in range(M):
                if A[i][j] == 1:
                    count += 1

        return count



