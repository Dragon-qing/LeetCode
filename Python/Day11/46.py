class Solution:
    re = []
    temp = []

    def permute(self, nums: list[int]) -> list[list[int]]:
        self.re.clear()
        seen = dict.fromkeys(nums, 0)
        self.dfs(0, nums, seen)
        return self.re

    @classmethod
    def dfs(cls, index, nums, seen):
        if index >= len(nums):
            cls.re.append(cls.temp.copy())
            return
        for i in range(len(nums)):
            if not seen[nums[i]]:
                cls.temp.append(nums[i])
                seen[nums[i]] = 1
                cls.dfs(index+1, nums, seen)
                seen[nums[i]] = 0
                cls.temp.pop()



if __name__ == '__main__':
    sol = Solution()
    test = [1,2,3,4]
    test = sol.permute(test)
    print(test)
