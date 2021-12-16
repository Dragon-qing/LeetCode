import collections


class Solution:
    def orangesRotting(self, grid: list[list[int]]) -> int:
        row = len(grid)
        col = len(grid[0])
        oranges_list = [(i, j) for i in range(row) for j in range(col) if grid[i][j] > 0]
        good_oranges = []
        bad_oranges = []
        for i, j in oranges_list:
            if grid[i][j] == 1:
                good_oranges.append((i, j))
            else:
                bad_oranges.append((i, j))
        if not len(good_oranges): return 0
        q = collections.deque(bad_oranges)
        deep = -1
        seen = set(bad_oranges)
        while q:
            deep += 1
            length = len(q)
            for _ in range(length):
                r, c = q.popleft()
                for i, j in [[r - 1, c], [r + 1, c], [r, c - 1], [r, c + 1]]:
                    if 0 <= i < row and 0 <= j < col and (i, j) not in seen:
                        if (i, j) in good_oranges:
                            good_oranges.remove((i, j))
                            q.append((i, j))
                            seen.add((i, j))
        if len(good_oranges):
            return -1
        return deep


if __name__ == '__main__':
    sol = Solution()
    test = [[2,1,1],[1,1,0],[0,1,1]]
    print(sol.orangesRotting(test))
