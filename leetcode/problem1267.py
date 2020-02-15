class Solution:
    def countServers(self, grid: List[List[int]]) -> int:
        M = len(grid)
        N = len(grid[0])

        for y in range(M):
            cnt = 0
            for x in range(N):
                if grid[y][x] != 0:
                    cnt += 1
            if cnt > 1:
                for x in range(N):
                    grid[y][x] = 2 if grid[y][x] >= 1 else 0

        for x in range(N):
            cnt = 0
            for y in range(M):
                if grid[y][x] != 0:
                    cnt += 1
            if cnt > 1:
                for y in range(M):
                    grid[y][x] = 2 if grid[y][x] >= 1 else 0

        answer = 0

        for y in range(M):
            for x in range(N):
                if grid[y][x] == 2:
                    answer += 1

        return answer


