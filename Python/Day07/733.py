class Solution:
    def floodFill(self, image: list[list[int]], sr: int, sc: int, newColor: int) -> list[list[int]]:
        # 行数
        m = len(image)
        # 列数
        n = len(image[0])
        # 访问记录表
        readed = [[0 for j in range(n)] for i in range(m)]
        # 待访问list
        ready = []
        # 目标值
        temp = image[sr][sc]
        ready.append((sr, sc))
        while len(ready):
            t = ready.pop(0)
            readed[t[0]][t[1]] = 1
            image[t[0]][t[1]] = newColor
            self.initReady(m, n, ready, t[1], t[0], readed, temp, image)
        return image

    def initReady(self, m, n, ready, sc, sr, readed, key, image):
        # 上
        if sr - 1 > -1 and not readed[sr-1][sc] and image[sr-1][sc] == key:
            ready.append((sr - 1, sc))
        # 下
        if sr + 1 < m and not readed[sr+1][sc] and image[sr+1][sc] == key:
            ready.append((sr + 1, sc))
        # 左
        if sc - 1 > -1 and not readed[sr][sc-1] and image[sr][sc-1] == key:
            ready.append((sr, sc - 1))
        # 右
        if sc + 1 < n and not readed[sr][sc+1] and image[sr][sc+1] == key:
            ready.append((sr, sc + 1))


if __name__ == '__main__':
    sol = Solution()
    test = [[0,0,0],[0,0,0]]
    print(test)
    test = sol.floodFill(test, 0, 0, 2)
    print(test)
