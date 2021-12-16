class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        m = len(s1)
        n = len(s2)
        list1 = [0 for i in range(26)]
        list2 = [0 for i in range(26)]
        if m > n: return False
        for i in range(m):
            list1[ord(s1[i]) - ord('a')] += 1
            list2[ord(s2[i]) - ord('a')] += 1
        if list1 == list2:
            return True
        index = m
        while index < n:
            list2[ord(s2[index]) - ord("a")] += 1
            list2[ord(s2[index - m]) - ord("a")] -= 1
            if list1 == list2:
                return True
            index += 1
        return False
