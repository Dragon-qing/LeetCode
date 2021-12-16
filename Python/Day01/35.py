class Solution:
    def searchInsert(self, nums: list[int], target: int) -> int:
        start = 0
        end = len(nums)
        mid = (start + end) // 2
        while start < end:
            if (nums[mid] == target):
                return mid
            elif nums[mid]<target:
                start = mid+1
            else:
                end = mid
            mid = (start + end) // 2
        return mid