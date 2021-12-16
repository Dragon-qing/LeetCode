class Solution:
    def sortedSquares(self, nums: list[int]) -> list[int]:
        re = list(map(lambda x: x ** 2, nums))
        re.sort()
        nums.sort(reverse=True)
        return re


if __name__ == '__main__':
    s = Solution()
    nums = [-4,-1,0,3,10]
    x= 3
    print(s.sortedSquares(nums))
    print(nums,x)
