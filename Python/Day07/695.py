class Solution:
    def maxAreaOfIsland(self, grid: list[list[int]]) -> int:
        # 行数
        row = len(grid)
        # 列数
        col = len(grid[0])
        readed = [[0 for i in range(col)] for i in range(row)]
        ready = []
        max_area = 0
        for r in range(row):
            for c in range(col):
                # 如果被访问过则直接跳过
                if readed[r][c]: continue
                # 如果是岛屿则进行广度优先搜索
                if grid[r][c]:
                    ready.append((r, c))
                    readed[r][c] = 1
                    temp = 0
                    while len(ready):
                        temp += 1
                        t = ready.pop(0)
                        self.initReady(t[1], col, grid, t[0], readed, ready, row)
                    max_area = max(temp, max_area)
        return max_area

    def initReady(self, c, col, grid, r, readed, ready, row):
        for i, j in [[r - 1, c], [r + 1, c], [r, c - 1], [r, c + 1]]:
            if 0 <= i < row and 0 <= j < col and not readed[i][j] and grid[i][j]:
                ready.append((i, j))
                readed[i][j] = 1


if __name__ == '__main__':
    sol = Solution()
    test = [[1,1,0,0,0],[1,1,0,0,0],[0,0,0,1,1],[0,0,0,1,1]]
    print(sol.maxAreaOfIsland(test))