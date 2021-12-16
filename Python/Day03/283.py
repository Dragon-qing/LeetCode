class Solution:
    def moveZeroes(self, nums: list[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        begin = 0
        end = len(nums)
        while begin < end:
            if nums[begin] == 0:
                nums.pop(begin)
                nums.append(0)
                end -= 1
                continue
            begin += 1



        # n = len(nums)
        # left=0
        # right = 0
        # while right < n:
        #     if nums[right]!=0:
        #         nums[left],nums[right]=nums[right],nums[left]
        #         left = left +1
        #     right=right +1


if __name__ == '__main__':
    nums = [0, 0, 1]
    s = Solution()
    s.moveZeroes(nums)
    print(nums)
