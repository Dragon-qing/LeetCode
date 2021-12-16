class Solution:
    temp = []
    ans = []

    def combine(self, n: int, k: int) -> list[list[int]]:
        self.ans.clear()
        left = 1
        right = n
        self.dfs(left, right, k)
        return self.ans

    @classmethod
    def dfs(cls, left, right, k):
        if len(cls.temp) + right - left + 1 < k:
            return
        if len(cls.temp) == k:
            cls.ans.append(cls.temp.copy())
            return
        cls.temp.append(left)
        cls.dfs(left+1, right, k)
        cls.temp.pop()
        cls.dfs(left+1, right, k)


if __name__ == '__main__':
    sol = Solution()
    test = sol.combine(1, 1)
    print(test)
