import collections


class Solution:
    def updateMatrix(self, mat: list[list[int]]) -> list[list[int]]:
        row = len(mat)
        col = len(mat[0])
        dis = [[0] * col for _ in range(row)]
        zeros_list = [(i, j) for i in range(row) for j in range(col) if mat[i][j] == 0]
        flags = set(zeros_list)
        que = collections.deque(zeros_list)
        while que:
            r, c = que.popleft()
            for i, j in [[r - 1, c], [r + 1, c], [r, c - 1], [r, c + 1]]:
                if 0 <= i < row and 0 <= j < col and (i, j) not in flags:
                    dis[i][j] = dis[r][c] + 1
                    flags.add((i, j))
                    que.append((i, j))
        return dis


if __name__ == '__main__':
    test = [[1,0,1,1,0,0,1,0,0,1],[0,1,1,0,1,0,1,0,1,1],[0,0,1,0,1,0,0,1,0,0],[1,0,1,0,1,1,1,1,1,1],[0,1,0,1,1,0,0,0,0,1],[0,0,1,0,1,1,1,0,1,0],[0,1,0,1,0,1,0,0,1,1],[1,0,0,0,1,1,1,1,0,1],[1,1,1,1,1,1,1,0,1,0],[1,1,1,1,0,1,0,0,1,1]]
    for i in range(len(test)):
        print(test[i])
    print()
    sol = Solution()
    test = sol.updateMatrix(test)
    for i in range(len(test)):
        print(test[i])
