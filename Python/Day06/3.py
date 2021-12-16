class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        left, right = 0, 0
        max_length = 1
        dic = {}
        while right < len(s):
            if dic.get(s[right], 0) > left:
                left = dic[s[right]]
            max_length = max(max_length, right - left + 1)
            dic[s[right]] = right + 1
            right += 1
        return max_length
