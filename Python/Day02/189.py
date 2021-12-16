class Solution:
    def rotate(self, nums: list[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        temp_list = [0 for i in range(len(nums))]
        begin, end = 0, len(nums) - 1
        while begin <= end:
            temp_list[(begin+k)%len(nums)] = nums[begin]
            begin+=1
        nums[:] = temp_list[:]
        print(temp_list)


if __name__ == '__main__':
    s = Solution()
    nums = [1, 2, 3, 4, 5, 6, 7]
    s.rotate(nums=nums, k=3)
    print(nums[-1])

    # 更优解
    # a = len(nums)
    # # nums[:] = nums[-k%a:]+nums[:-k%a]
    # nums[:] = [nums[i] for i in range(-(k % a), a - k % a)]



