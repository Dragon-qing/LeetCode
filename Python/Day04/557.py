class Solution:
    def reverseWords(self, s: str) -> str:
        left = 0
        length = len(s)
        re = ""
        while left < length:
            right = left
            while  right < length and s[right] != ' ':
                right += 1
            itr = right
            right = itr - 1
            while left<=right:
                re += s[right]
                right -= 1
            if itr < length:
                re += s[itr]
                left = itr + 1
            else:
                left = itr
        return re


if __name__ == '__main__':
    sol = Solution()
    s = "Let's take LeetCode contest"
    re = sol.reverseWords(s)
    print(re)
