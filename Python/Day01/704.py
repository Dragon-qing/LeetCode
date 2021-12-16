class Solution:
    def search(self, nums: list[int], target: int) -> int:
        begin = 0
        end = len(nums)
        while begin < end:
            i = int((begin + end) / 2)
            if nums[i] == target:
                return i
            elif nums[i]<target:
                begin = i+1
            else:
                end = i
        return -1


if __name__ == '__main__':
    s = Solution()
    print(s.search(nums=[5], target=5))
